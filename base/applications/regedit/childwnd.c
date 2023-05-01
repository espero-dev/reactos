/*
 * Regedit child window
 *
 * Copyright (C) 2002 Robert Dickenson <robd@reactos.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "regedit.h"

ChildWnd* g_pChildWnd;
static int last_split;
HBITMAP SizingPattern = 0;
HBRUSH  SizingBrush = 0;

extern LPCWSTR get_root_key_name(HKEY hRootKey)
{
    if (hRootKey == HKEY_CLASSES_ROOT) return L"HKEY_CLASSES_ROOT";
    if (hRootKey == HKEY_CURRENT_USER) return L"HKEY_CURRENT_USER";
    if (hRootKey == HKEY_LOCAL_MACHINE) return L"HKEY_LOCAL_MACHINE";
    if (hRootKey == HKEY_USERS) return L"HKEY_USERS";
    if (hRootKey == HKEY_CURRENT_CONFIG) return L"HKEY_CURRENT_CONFIG";
    if (hRootKey == HKEY_DYN_DATA) return L"HKEY_DYN_DATA";

    return L"UNKNOWN HKEY, PLEASE REPORT";
}

extern void ResizeWnd(int cx, int cy)
{
    HDWP hdwp = BeginDeferWindowPos(4);
    RECT rt, rs, rb;
    const int nButtonWidth = 44;
    const int nButtonHeight = 22;
    int cyEdge = GetSystemMetrics(SM_CYEDGE);
    const UINT uFlags = SWP_NOZORDER | SWP_NOACTIVATE;
    SetRect(&rt, 0, 0, cx, cy);
    cy = 0;
    if (hStatusBar != NULL)
    {
        GetWindowRect(hStatusBar, &rs);
        cy = rs.bottom - rs.top;
    }
    GetWindowRect(g_pChildWnd->hAddressBtnWnd, &rb);
    cx = g_pChildWnd->nSplitPos + SPLIT_WIDTH / 2;
    if (hdwp)
        hdwp = DeferWindowPos(hdwp, g_pChildWnd->hAddressBarWnd, NULL,
                              rt.left, rt.top,
                              rt.right - rt.left - nButtonWidth, nButtonHeight,
                              uFlags);
    if (hdwp)
        hdwp = DeferWindowPos(hdwp, g_pChildWnd->hAddressBtnWnd, NULL,
                              rt.right - nButtonWidth, rt.top,
                              nButtonWidth, nButtonHeight,
                              uFlags);
    if (hdwp)
        hdwp = DeferWindowPos(hdwp, g_pChildWnd->hTreeWnd, NULL,
                              rt.left,
                              rt.top + nButtonHeight + cyEdge,
                              g_pChildWnd->nSplitPos - SPLIT_WIDTH/2 - rt.left,
                              rt.bottom - rt.top - cy - 2 * cyEdge,
                              uFlags);
    if (hdwp)
        hdwp = DeferWindowPos(hdwp, g_pChildWnd->hListWnd, NULL,
                              rt.left + cx,
                              rt.top + nButtonHeight + cyEdge,
                              rt.right - cx,
                              rt.bottom - rt.top - cy - 2 * cyEdge,
                              uFlags);
    if (hdwp)
        EndDeferWindowPos(hdwp);
}

/*******************************************************************************
 * Local module support methods
 */

static void draw_splitbar(HWND hWnd, int x)
{
    RECT rt;
    HGDIOBJ OldObj;
    HDC hdc = GetDC(hWnd);

    if(!SizingPattern)
    {
        const DWORD Pattern[4] = {0x5555AAAA, 0x5555AAAA, 0x5555AAAA, 0x5555AAAA};
        SizingPattern = CreateBitmap(8, 8, 1, 1, Pattern);
    }
    if(!SizingBrush)
    {
        SizingBrush = CreatePatternBrush(SizingPattern);
    }
    GetClientRect(hWnd, &rt);
    rt.left = x - SPLIT_WIDTH/2;
    rt.right = x + SPLIT_WIDTH/2+1;
    OldObj = SelectObject(hdc, SizingBrush);
    PatBlt(hdc, rt.left, rt.top, rt.right - rt.left, rt.bottom - rt.top, PATINVERT);
    SelectObject(hdc, OldObj);
    ReleaseDC(hWnd, hdc);
}

/*******************************************************************************
 * finish_splitbar [internal]
 *
 * make the splitbar invisible and resize the windows
 * (helper for ChildWndProc)
 */
static void finish_splitbar(HWND hWnd, int x)
{
    RECT rt;

    draw_splitbar(hWnd, last_split);
    last_split = -1;
    GetClientRect(hWnd, &rt);
    g_pChildWnd->nSplitPos = x;
    ResizeWnd(rt.right, rt.bottom);
    ReleaseCapture();
}

LRESULT CALLBACK AddressBarProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    WNDPROC oldwndproc;
    static WCHAR s_szNode[256];
    oldwndproc = (WNDPROC)GetWindowLongPtr(hwnd, GWLP_USERDATA);

    switch (uMsg)
    {
    case WM_KEYUP:
        if (wParam == VK_RETURN)
        {
            GetWindowTextW(hwnd, s_szNode, COUNT_OF(s_szNode));
            SelectNode(g_pChildWnd->hTreeWnd, s_szNode);
        }
        break;
    default:
        break;
    }
    return CallWindowProcW(oldwndproc, hwnd, uMsg, wParam, lParam);
}

VOID
UpdateAddress(HTREEITEM hItem, HKEY hRootKey, LPCWSTR pszPath, BOOL bSelectNone)
{
    LPCWSTR keyPath, rootName;
    LPWSTR fullPath;
    DWORD cbFullPath;

    /* Wipe the listview, the status bar and the address bar if the root key was selected */
    if (TreeView_GetParent(g_pChildWnd->hTreeWnd, hItem) == NULL)
    {
        ListView_DeleteAllItems(g_pChildWnd->hListWnd);
        SendMessageW(hStatusBar, SB_SETTEXTW, 0, (LPARAM)NULL);
        SendMessageW(g_pChildWnd->hAddressBarWnd, WM_SETTEXT, 0, (LPARAM)NULL);
        return;
    }

    if (pszPath == NULL)
        keyPath = GetItemPath(g_pChildWnd->hTreeWnd, hItem, &hRootKey);
    else
        keyPath = pszPath;

    if (keyPath)
    {
        RefreshListView(g_pChildWnd->hListWnd, hRootKey, keyPath, bSelectNone);
        rootName = get_root_key_name(hRootKey);
        cbFullPath = (wcslen(rootName) + 1 + wcslen(keyPath) + 1) * sizeof(WCHAR);
        fullPath = malloc(cbFullPath);
        if (fullPath)
        {
            /* set (correct) the address bar text */
            if (keyPath[0] != L'\0')
                swprintf(fullPath, L"%s%s%s", rootName, keyPath[0]==L'\\'?L"":L"\\", keyPath);
            else
                fullPath = wcscpy(fullPath, rootName);
            SendMessageW(hStatusBar, SB_SETTEXTW, 0, (LPARAM)fullPath);
            SendMessageW(g_pChildWnd->hAddressBarWnd, WM_SETTEXT, 0, (LPARAM)fullPath);
            free(fullPath);
            /* disable hive manipulation items temporarily (enable only if necessary) */
            EnableMenuItem(hMenuFrame, ID_REGISTRY_LOADHIVE, MF_BYCOMMAND | MF_GRAYED);
            EnableMenuItem(hMenuFrame, ID_REGISTRY_UNLOADHIVE, MF_BYCOMMAND | MF_GRAYED);
            /* compare the strings to see if we should enable/disable the "Load Hive" menus accordingly */
            if (_wcsicmp(rootName, L"HKEY_LOCAL_MACHINE") != 0 ||
                _wcsicmp(rootName, L"HKEY_USERS") != 0)
            {
                /*
                 * enable the unload menu item if at the root, otherwise
                 * enable the load menu item if there is no slash in
                 * keyPath (ie. immediate child selected)
                 */
                if (keyPath[0] == UNICODE_NULL)
                    EnableMenuItem(hMenuFrame, ID_REGISTRY_LOADHIVE, MF_BYCOMMAND | MF_ENABLED);
                else if(!wcschr(keyPath, L'\\'))
                    EnableMenuItem(hMenuFrame, ID_REGISTRY_UNLOADHIVE, MF_BYCOMMAND | MF_ENABLED);
            }
        }
    }
}

/*******************************************************************************
 *
 *  FUNCTION: ChildWndProc(HWND, unsigned, WORD, LONG)
 *
 *  PURPOSE:  Processes messages for the child windows.
 *
 *  WM_COMMAND  - process the application menu
 *  WM_DESTROY  - post a quit message and return
 *
 */
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    BOOL Result;
    RECT rc;

    switch (message)
    {
    case WM_CREATE:
    {
        WNDPROC oldproc;
        HFONT hFont;
        WCHAR buffer[MAX_PATH];

        /* Load "My Computer" string */
        LoadStringW(hInst, IDS_MY_COMPUTER, buffer, COUNT_OF(buffer));

        g_pChildWnd = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(ChildWnd));
        if (!g_pChildWnd) return 0;

        wcsncpy(g_pChildWnd->szPath, buffer, MAX_PATH);
        g_pChildWnd->nSplitPos = 190;
        g_pChildWnd->hWnd = hWnd;
        g_pChildWnd->hAddressBarWnd = CreateWindowExW(WS_EX_CLIENTEDGE, L"Edit", NULL, WS_CHILD | WS_VISIBLE | WS_CHILDWINDOW | WS_TABSTOP,
                                                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                                                      hWnd, (HMENU)0, hInst, 0);
        g_pChildWnd->hAddressBtnWnd = CreateWindowExW(0, L"Button", L"\x00BB", WS_CHILD | WS_VISIBLE | WS_CHILDWINDOW | WS_TABSTOP | BS_TEXT | BS_CENTER | BS_VCENTER | BS_FLAT | BS_DEFPUSHBUTTON,
                                                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                                                      hWnd, (HMENU)0, hInst, 0);
        GetClientRect(hWnd, &rc);
        g_pChildWnd->hTreeWnd = CreateTreeView(hWnd, g_pChildWnd->szPath, (HMENU) TREE_WINDOW);
        g_pChildWnd->hListWnd = CreateListView(hWnd, (HMENU) LIST_WINDOW, rc.right - g_pChildWnd->nSplitPos);
        SetFocus(g_pChildWnd->hTreeWnd);

        /* set the address bar and button font */
        if ((g_pChildWnd->hAddressBarWnd) && (g_pChildWnd->hAddressBtnWnd))
        {
            hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
            SendMessageW(g_pChildWnd->hAddressBarWnd,
                         WM_SETFONT,
                         (WPARAM)hFont,
                         0);
            SendMessageW(g_pChildWnd->hAddressBtnWnd,
                         WM_SETFONT,
                         (WPARAM)hFont,
                         0);
        }
        /* Subclass the AddressBar */
        oldproc = (WNDPROC)GetWindowLongPtr(g_pChildWnd->hAddressBarWnd, GWLP_WNDPROC);
        SetWindowLongPtr(g_pChildWnd->hAddressBarWnd, GWLP_USERDATA, (DWORD_PTR)oldproc);
        SetWindowLongPtr(g_pChildWnd->hAddressBarWnd, GWLP_WNDPROC, (DWORD_PTR)AddressBarProc);
        break;
    }
    case WM_COMMAND:
        if(HIWORD(wParam) == BN_CLICKED)
        {
            PostMessageW(g_pChildWnd->hAddressBarWnd, WM_KEYUP, VK_RETURN, 0);
        }
        break;
    case WM_SETCURSOR:
        if (LOWORD(lParam) == HTCLIENT)
        {
            POINT pt;
            GetCursorPos(&pt);
            ScreenToClient(hWnd, &pt);
            if (pt.x>=g_pChildWnd->nSplitPos-SPLIT_WIDTH/2 && pt.x<g_pChildWnd->nSplitPos+SPLIT_WIDTH/2+1)
            {
                SetCursor(LoadCursorW(0, IDC_SIZEWE));
                return TRUE;
            }
        }
        goto def;
    case WM_DESTROY:
        DestroyListView(g_pChildWnd->hListWnd);
        DestroyTreeView(g_pChildWnd->hTreeWnd);
        DestroyMainMenu();
        HeapFree(GetProcessHeap(), 0, g_pChildWnd);
        g_pChildWnd = NULL;
        PostQuitMessage(0);
        break;
    case WM_LBUTTONDOWN:
    {
        RECT rt;
        int x = (short)LOWORD(lParam);
        GetClientRect(hWnd, &rt);
        if (x>=g_pChildWnd->nSplitPos-SPLIT_WIDTH/2 && x<g_pChildWnd->nSplitPos+SPLIT_WIDTH/2+1)
        {
            last_split = g_pChildWnd->nSplitPos;
            draw_splitbar(hWnd, last_split);
            SetCapture(hWnd);
        }
        break;
    }

    case WM_LBUTTONUP:
    case WM_RBUTTONDOWN:
        if (GetCapture() == hWnd)
        {
            finish_splitbar(hWnd, LOWORD(lParam));
        }
        break;

    case WM_CAPTURECHANGED:
        if (GetCapture()==hWnd && last_split>=0)
            draw_splitbar(hWnd, last_split);
        break;

    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE)
            if (GetCapture() == hWnd)
            {
                RECT rt;
                draw_splitbar(hWnd, last_split);
                GetClientRect(hWnd, &rt);
                ResizeWnd(rt.right, rt.bottom);
                last_split = -1;
                ReleaseCapture();
                SetCursor(LoadCursorW(0, IDC_ARROW));
            }
        break;

    case WM_MOUSEMOVE:
        if (GetCapture() == hWnd)
        {
            HDC hdc;
            RECT rt;
            HGDIOBJ OldObj;
            int x = LOWORD(lParam);
            if(!SizingPattern)
            {
                const DWORD Pattern[4] = {0x5555AAAA, 0x5555AAAA, 0x5555AAAA, 0x5555AAAA};
                SizingPattern = CreateBitmap(8, 8, 1, 1, Pattern);
            }
            if(!SizingBrush)
            {
                SizingBrush = CreatePatternBrush(SizingPattern);
            }

            GetClientRect(hWnd, &rt);
            x = (SHORT) min(max(x, SPLIT_MIN), rt.right - SPLIT_MIN);
            if(last_split != x)
            {
                rt.left = last_split-SPLIT_WIDTH/2;
                rt.right = last_split+SPLIT_WIDTH/2+1;
                hdc = GetDC(hWnd);
                OldObj = SelectObject(hdc, SizingBrush);
                PatBlt(hdc, rt.left, rt.top, rt.right - rt.left, rt.bottom - rt.top, PATINVERT);
                last_split = x;
                rt.left = x-SPLIT_WIDTH/2;
                rt.right = x+SPLIT_WIDTH/2+1;
                PatBlt(hdc, rt.left, rt.top, rt.right - rt.left, rt.bottom - rt.top, PATINVERT);
                SelectObject(hdc, OldObj);
                ReleaseDC(hWnd, hdc);
            }
        }
        break;

    case WM_SETFOCUS:
        if (g_pChildWnd != NULL)
        {
            SetFocus(g_pChildWnd->nFocusPanel? g_pChildWnd->hListWnd: g_pChildWnd->hTreeWnd);
        }
        break;

    case WM_TIMER:
        break;

    case WM_NOTIFY:
        if (g_pChildWnd == NULL) break;

        if (((LPNMHDR)lParam)->idFrom == TREE_WINDOW)
        {
            if (!TreeWndNotifyProc(g_pChildWnd->hListWnd, wParam, lParam, &Result))
                goto def;

            return Result;
        }
        else
        {
            if (((LPNMHDR)lParam)->idFrom == LIST_WINDOW)
            {
                if (!ListWndNotifyProc(g_pChildWnd->hListWnd, wParam, lParam, &Result))
                    goto def;

                return Result;
            }
            else
                goto def;
        }
        break;

    case WM_CONTEXTMENU:
    {
        POINT pt;
        if((HWND)wParam == g_pChildWnd->hListWnd)
        {
            int i, cnt;
            BOOL IsDefault;
            pt.x = (short) LOWORD(lParam);
            pt.y = (short) HIWORD(lParam);
            cnt = ListView_GetSelectedCount(g_pChildWnd->hListWnd);
            i = ListView_GetNextItem(g_pChildWnd->hListWnd, -1, LVNI_FOCUSED | LVNI_SELECTED);
            if (pt.x == -1 && pt.y == -1)
            {
                RECT rc;
                if (i != -1)
                {
                    rc.left = LVIR_BOUNDS;
                    SendMessageW(g_pChildWnd->hListWnd, LVM_GETITEMRECT, i, (LPARAM) &rc);
                    pt.x = rc.left + 8;
                    pt.y = rc.top + 8;
                }
                else
                    pt.x = pt.y = 0;
                ClientToScreen(g_pChildWnd->hListWnd, &pt);
            }
            if(i == -1)
            {
                TrackPopupMenu(GetSubMenu(hPopupMenus, PM_NEW), TPM_RIGHTBUTTON, pt.x, pt.y, 0, hFrameWnd, NULL);
            }
            else
            {
                HMENU mnu = GetSubMenu(hPopupMenus, PM_MODIFYVALUE);
                SetMenuDefaultItem(mnu, ID_EDIT_MODIFY, MF_BYCOMMAND);
                IsDefault = IsDefaultValue(g_pChildWnd->hListWnd, i);
                if(cnt == 1)
                    EnableMenuItem(mnu, ID_EDIT_RENAME, MF_BYCOMMAND | (IsDefault ? MF_DISABLED | MF_GRAYED : MF_ENABLED));
                else
                    EnableMenuItem(mnu, ID_EDIT_RENAME, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
                EnableMenuItem(mnu, ID_EDIT_MODIFY, MF_BYCOMMAND | (cnt == 1 ? MF_ENABLED : MF_DISABLED | MF_GRAYED));
                EnableMenuItem(mnu, ID_EDIT_MODIFY_BIN, MF_BYCOMMAND | (cnt == 1 ? MF_ENABLED : MF_DISABLED | MF_GRAYED));

                TrackPopupMenu(mnu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hFrameWnd, NULL);
            }
        }
        else if ((HWND)wParam == g_pChildWnd->hTreeWnd)
        {
            TVHITTESTINFO hti;
            HMENU hContextMenu;
            TVITEMW item;
            MENUITEMINFOW mii;
            WCHAR buffer[256];
            BOOL isRoot;

            pt.x = (short) LOWORD(lParam);
            pt.y = (short) HIWORD(lParam);

            if (pt.x == -1 && pt.y == -1)
            {
                RECT rc;
                hti.hItem = TreeView_GetSelection(g_pChildWnd->hTreeWnd);
                if (hti.hItem != NULL)
                {
                    TreeView_GetItemRect(g_pChildWnd->hTreeWnd, hti.hItem, &rc, TRUE);
                    pt.x = rc.left + 8;
                    pt.y = rc.top + 8;
                    ClientToScreen(g_pChildWnd->hTreeWnd, &pt);
                    hti.flags = TVHT_ONITEM;
                }
                else
                    hti.flags = 0;
            }
            else
            {
                hti.pt.x = pt.x;
                hti.pt.y = pt.y;
                ScreenToClient(g_pChildWnd->hTreeWnd, &hti.pt);
                TreeView_HitTest(g_pChildWnd->hTreeWnd, &hti);
            }

            if (hti.flags & TVHT_ONITEM)
            {
                TreeView_SelectItem(g_pChildWnd->hTreeWnd, hti.hItem);

                isRoot = (TreeView_GetParent(g_pChildWnd->hTreeWnd, hti.hItem) == NULL);
                hContextMenu = GetSubMenu(hPopupMenus, PM_TREECONTEXT);

                /* idx1 'New' PopupMenu */
                EnableMenuItem(hContextMenu, 1, isRoot? MF_BYPOSITION|MF_DISABLED|MF_GRAYED : MF_BYPOSITION|MF_ENABLED);
                /* idx8 'Permissions' */
                EnableMenuItem(hContextMenu, 8, isRoot? MF_BYPOSITION|MF_DISABLED|MF_GRAYED : MF_BYPOSITION|MF_ENABLED);

                memset(&item, 0, sizeof(item));
                item.mask = TVIF_STATE | TVIF_CHILDREN;
                item.hItem = hti.hItem;
                TreeView_GetItem(g_pChildWnd->hTreeWnd, &item);

                /* Set the Expand/Collapse menu item appropriately */
                LoadStringW(hInst, (item.state & TVIS_EXPANDED) ? IDS_COLLAPSE : IDS_EXPAND, buffer, COUNT_OF(buffer));
                memset(&mii, 0, sizeof(mii));
                mii.cbSize = sizeof(mii);
                mii.fMask = MIIM_STRING | MIIM_STATE | MIIM_ID;
                mii.fState = (item.cChildren > 0) ? MFS_DEFAULT : MFS_GRAYED;
                mii.wID = (item.state & TVIS_EXPANDED) ? ID_TREE_COLLAPSEBRANCH : ID_TREE_EXPANDBRANCH;
                mii.dwTypeData = (LPWSTR) buffer;
                SetMenuItemInfo(hContextMenu, 0, TRUE, &mii);
                TrackPopupMenu(hContextMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hFrameWnd, NULL);
            }
        }
        break;
    }

    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED && g_pChildWnd != NULL)
        {
            ResizeWnd(LOWORD(lParam), HIWORD(lParam));
        }
        /* fall through */
    default:
def:
        return DefWindowProcW(hWnd, message, wParam, lParam);
    }
    return 0;
}
