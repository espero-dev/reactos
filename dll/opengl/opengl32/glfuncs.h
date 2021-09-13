/*
 * List of all GL functions exported by opengl32.dll.
 * Usage: USE_GL_FUNC(name, return type, prototype arguments, call arguments, icd offset, x86 stack size)
 */

#ifndef USE_GL_FUNC_RET
#define USE_GL_FUNC_RET(name, ret_type, proto_args, call_args, offset, stack)   \
    USE_GL_FUNC(name, proto_args, call_args, offset, stack)
#endif

USE_GL_FUNC(NewList, (GLuint list, GLenum mode), (list,mode), 0, 8)
USE_GL_FUNC(EndList, (void), (), 1, 0)
USE_GL_FUNC(CallList, (GLuint list), (list), 2, 4)
USE_GL_FUNC(CallLists, (GLsizei n, GLenum type, const GLvoid *lists), (n,type,lists), 3, 12)
USE_GL_FUNC(DeleteLists, (GLuint list, GLsizei range), (list,range), 4, 8)
USE_GL_FUNC_RET(GenLists, GLuint, (GLsizei range), (range), 5, 4)
USE_GL_FUNC(ListBase, (GLuint base), (base), 6, 4)
USE_GL_FUNC(Begin, (GLenum mode), (mode), 7, 4)
USE_GL_FUNC(Bitmap, (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap), (width,height,xorig,yorig,xmove,ymove,bitmap), 8, 28)
USE_GL_FUNC(Color3b, (GLbyte red, GLbyte green, GLbyte blue), (red,green,blue), 9, 12)
USE_GL_FUNC(Color3bv, (const GLbyte *v), (v), 10, 4)
USE_GL_FUNC(Color3d, (GLdouble red, GLdouble green, GLdouble blue), (red,green,blue), 11, 24)
USE_GL_FUNC(Color3dv, (const GLdouble *v), (v), 12, 4)
USE_GL_FUNC(Color3f, (GLfloat red, GLfloat green, GLfloat blue), (red,green,blue), 13, 12)
USE_GL_FUNC(Color3fv, (const GLfloat *v), (v), 14, 4)
USE_GL_FUNC(Color3i, (GLint red, GLint green, GLint blue), (red,green,blue), 15, 12)
USE_GL_FUNC(Color3iv, (const GLint *v), (v), 16, 4)
USE_GL_FUNC(Color3s, (GLshort red, GLshort green, GLshort blue), (red,green,blue), 17, 12)
USE_GL_FUNC(Color3sv, (const GLshort *v), (v), 18, 4)
USE_GL_FUNC(Color3ub, (GLubyte red, GLubyte green, GLubyte blue), (red,green,blue), 19, 12)
USE_GL_FUNC(Color3ubv, (const GLubyte *v), (v), 20, 4)
USE_GL_FUNC(Color3ui, (GLuint red, GLuint green, GLuint blue), (red,green,blue), 21, 12)
USE_GL_FUNC(Color3uiv, (const GLuint *v), (v), 22, 4)
USE_GL_FUNC(Color3us, (GLushort red, GLushort green, GLushort blue), (red,green,blue), 23, 12)
USE_GL_FUNC(Color3usv, (const GLushort *v), (v), 24, 4)
USE_GL_FUNC(Color4b, (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha), (red,green,blue,alpha), 25, 16)
USE_GL_FUNC(Color4bv, (const GLbyte *v), (v), 26, 4)
USE_GL_FUNC(Color4d, (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha), (red,green,blue,alpha), 27, 32)
USE_GL_FUNC(Color4dv, (const GLdouble *v), (v), 28, 4)
USE_GL_FUNC(Color4f, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), (red,green,blue,alpha), 29, 16)
USE_GL_FUNC(Color4fv, (const GLfloat *v), (v), 30, 4)
USE_GL_FUNC(Color4i, (GLint red, GLint green, GLint blue, GLint alpha), (red,green,blue,alpha), 31, 16)
USE_GL_FUNC(Color4iv, (const GLint *v), (v), 32, 4)
USE_GL_FUNC(Color4s, (GLshort red, GLshort green, GLshort blue, GLshort alpha), (red,green,blue,alpha), 33, 16)
USE_GL_FUNC(Color4sv, (const GLshort *v), (v), 34, 4)
USE_GL_FUNC(Color4ub, (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha), (red,green,blue,alpha), 35, 16)
USE_GL_FUNC(Color4ubv, (const GLubyte *v), (v), 36, 4)
USE_GL_FUNC(Color4ui, (GLuint red, GLuint green, GLuint blue, GLuint alpha), (red,green,blue,alpha), 37, 16)
USE_GL_FUNC(Color4uiv, (const GLuint *v), (v), 38, 4)
USE_GL_FUNC(Color4us, (GLushort red, GLushort green, GLushort blue, GLushort alpha), (red,green,blue,alpha), 39, 16)
USE_GL_FUNC(Color4usv, (const GLushort *v), (v), 40, 4)
USE_GL_FUNC(EdgeFlag, (GLboolean flag), (flag), 41, 4)
USE_GL_FUNC(EdgeFlagv, (const GLboolean *flag), (flag), 42, 4)
USE_GL_FUNC(End, (void), (), 43, 0)
USE_GL_FUNC(Indexd, (GLdouble c), (c), 44, 8)
USE_GL_FUNC(Indexdv, (const GLdouble *c), (c), 45, 4)
USE_GL_FUNC(Indexf, (GLfloat c), (c), 46, 4)
USE_GL_FUNC(Indexfv, (const GLfloat *c), (c), 47, 4)
USE_GL_FUNC(Indexi, (GLint c), (c), 48, 4)
USE_GL_FUNC(Indexiv, (const GLint *c), (c), 49, 4)
USE_GL_FUNC(Indexs, (GLshort c), (c), 50, 4)
USE_GL_FUNC(Indexsv, (const GLshort *c), (c), 51, 4)
USE_GL_FUNC(Normal3b, (GLbyte nx, GLbyte ny, GLbyte nz), (nx,ny,nz), 52, 12)
USE_GL_FUNC(Normal3bv, (const GLbyte *v), (v), 53, 4)
USE_GL_FUNC(Normal3d, (GLdouble nx, GLdouble ny, GLdouble nz), (nx,ny,nz), 54, 24)
USE_GL_FUNC(Normal3dv, (const GLdouble *v), (v), 55, 4)
USE_GL_FUNC(Normal3f, (GLfloat nx, GLfloat ny, GLfloat nz), (nx,ny,nz), 56, 12)
USE_GL_FUNC(Normal3fv, (const GLfloat *v), (v), 57, 4)
USE_GL_FUNC(Normal3i, (GLint nx, GLint ny, GLint nz), (nx,ny,nz), 58, 12)
USE_GL_FUNC(Normal3iv, (const GLint *v), (v), 59, 4)
USE_GL_FUNC(Normal3s, (GLshort nx, GLshort ny, GLshort nz), (nx,ny,nz), 60, 12)
USE_GL_FUNC(Normal3sv, (const GLshort *v), (v), 61, 4)
USE_GL_FUNC(RasterPos2d, (GLdouble x, GLdouble y), (x,y), 62, 16)
USE_GL_FUNC(RasterPos2dv, (const GLdouble *v), (v), 63, 4)
USE_GL_FUNC(RasterPos2f, (GLfloat x, GLfloat y), (x,y), 64, 8)
USE_GL_FUNC(RasterPos2fv, (const GLfloat *v), (v), 65, 4)
USE_GL_FUNC(RasterPos2i, (GLint x, GLint y), (x,y), 66, 8)
USE_GL_FUNC(RasterPos2iv, (const GLint *v), (v), 67, 4)
USE_GL_FUNC(RasterPos2s, (GLshort x, GLshort y), (x,y), 68, 8)
USE_GL_FUNC(RasterPos2sv, (const GLshort *v), (v), 69, 4)
USE_GL_FUNC(RasterPos3d, (GLdouble x, GLdouble y, GLdouble z), (x,y,z), 70, 24)
USE_GL_FUNC(RasterPos3dv, (const GLdouble *v), (v), 71, 4)
USE_GL_FUNC(RasterPos3f, (GLfloat x, GLfloat y, GLfloat z), (x,y,z), 72, 12)
USE_GL_FUNC(RasterPos3fv, (const GLfloat *v), (v), 73, 4)
USE_GL_FUNC(RasterPos3i, (GLint x, GLint y, GLint z), (x,y,z), 74, 12)
USE_GL_FUNC(RasterPos3iv, (const GLint *v), (v), 75, 4)
USE_GL_FUNC(RasterPos3s, (GLshort x, GLshort y, GLshort z), (x,y,z), 76, 12)
USE_GL_FUNC(RasterPos3sv, (const GLshort *v), (v), 77, 4)
USE_GL_FUNC(RasterPos4d, (GLdouble x, GLdouble y, GLdouble z, GLdouble w), (x,y,z,w), 78, 32)
USE_GL_FUNC(RasterPos4dv, (const GLdouble *v), (v), 79, 4)
USE_GL_FUNC(RasterPos4f, (GLfloat x, GLfloat y, GLfloat z, GLfloat w), (x,y,z,w), 80, 16)
USE_GL_FUNC(RasterPos4fv, (const GLfloat *v), (v), 81, 4)
USE_GL_FUNC(RasterPos4i, (GLint x, GLint y, GLint z, GLint w), (x,y,z,w), 82, 16)
USE_GL_FUNC(RasterPos4iv, (const GLint *v), (v), 83, 4)
USE_GL_FUNC(RasterPos4s, (GLshort x, GLshort y, GLshort z, GLshort w), (x,y,z,w), 84, 16)
USE_GL_FUNC(RasterPos4sv, (const GLshort *v), (v), 85, 4)
USE_GL_FUNC(Rectd, (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2), (x1,y1,x2,y2), 86, 32)
USE_GL_FUNC(Rectdv, (const GLdouble *v1, const GLdouble *v2), (v1,v2), 87, 8)
USE_GL_FUNC(Rectf, (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2), (x1,y1,x2,y2), 88, 16)
USE_GL_FUNC(Rectfv, (const GLfloat *v1, const GLfloat *v2), (v1,v2), 89, 8)
USE_GL_FUNC(Recti, (GLint x1, GLint y1, GLint x2, GLint y2), (x1,y1,x2,y2), 90, 16)
USE_GL_FUNC(Rectiv, (const GLint *v1, const GLint *v2), (v1,v2), 91, 8)
USE_GL_FUNC(Rects, (GLshort x1, GLshort y1, GLshort x2, GLshort y2), (x1,y1,x2,y2), 92, 16)
USE_GL_FUNC(Rectsv, (const GLshort *v1, const GLshort *v2), (v1,v2), 93, 8)
USE_GL_FUNC(TexCoord1d, (GLdouble s), (s), 94, 8)
USE_GL_FUNC(TexCoord1dv, (const GLdouble *v), (v), 95, 4)
USE_GL_FUNC(TexCoord1f, (GLfloat s), (s), 96, 4)
USE_GL_FUNC(TexCoord1fv, (const GLfloat *v), (v), 97, 4)
USE_GL_FUNC(TexCoord1i, (GLint s), (s), 98, 4)
USE_GL_FUNC(TexCoord1iv, (const GLint *v), (v), 99, 4)
USE_GL_FUNC(TexCoord1s, (GLshort s), (s), 100, 4)
USE_GL_FUNC(TexCoord1sv, (const GLshort *v), (v), 101, 4)
USE_GL_FUNC(TexCoord2d, (GLdouble s, GLdouble t), (s,t), 102, 16)
USE_GL_FUNC(TexCoord2dv, (const GLdouble *v), (v), 103, 4)
USE_GL_FUNC(TexCoord2f, (GLfloat s, GLfloat t), (s,t), 104, 8)
USE_GL_FUNC(TexCoord2fv, (const GLfloat *v), (v), 105, 4)
USE_GL_FUNC(TexCoord2i, (GLint s, GLint t), (s,t), 106, 8)
USE_GL_FUNC(TexCoord2iv, (const GLint *v), (v), 107, 4)
USE_GL_FUNC(TexCoord2s, (GLshort s, GLshort t), (s,t), 108, 8)
USE_GL_FUNC(TexCoord2sv, (const GLshort *v), (v), 109, 4)
USE_GL_FUNC(TexCoord3d, (GLdouble s, GLdouble t, GLdouble r), (s,t,r), 110, 24)
USE_GL_FUNC(TexCoord3dv, (const GLdouble *v), (v), 111, 4)
USE_GL_FUNC(TexCoord3f, (GLfloat s, GLfloat t, GLfloat r), (s,t,r), 112, 12)
USE_GL_FUNC(TexCoord3fv, (const GLfloat *v), (v), 113, 4)
USE_GL_FUNC(TexCoord3i, (GLint s, GLint t, GLint r), (s,t,r), 114, 12)
USE_GL_FUNC(TexCoord3iv, (const GLint *v), (v), 115, 4)
USE_GL_FUNC(TexCoord3s, (GLshort s, GLshort t, GLshort r), (s,t,r), 116, 12)
USE_GL_FUNC(TexCoord3sv, (const GLshort *v), (v), 117, 4)
USE_GL_FUNC(TexCoord4d, (GLdouble s, GLdouble t, GLdouble r, GLdouble q), (s,t,r,q), 118, 32)
USE_GL_FUNC(TexCoord4dv, (const GLdouble *v), (v), 119, 4)
USE_GL_FUNC(TexCoord4f, (GLfloat s, GLfloat t, GLfloat r, GLfloat q), (s,t,r,q), 120, 16)
USE_GL_FUNC(TexCoord4fv, (const GLfloat *v), (v), 121, 4)
USE_GL_FUNC(TexCoord4i, (GLint s, GLint t, GLint r, GLint q), (s,t,r,q), 122, 16)
USE_GL_FUNC(TexCoord4iv, (const GLint *v), (v), 123, 4)
USE_GL_FUNC(TexCoord4s, (GLshort s, GLshort t, GLshort r, GLshort q), (s,t,r,q), 124, 16)
USE_GL_FUNC(TexCoord4sv, (const GLshort *v), (v), 125, 4)
USE_GL_FUNC(Vertex2d, (GLdouble x, GLdouble y), (x,y), 126, 16)
USE_GL_FUNC(Vertex2dv, (const GLdouble *v), (v), 127, 4)
USE_GL_FUNC(Vertex2f, (GLfloat x, GLfloat y), (x,y), 128, 8)
USE_GL_FUNC(Vertex2fv, (const GLfloat *v), (v), 129, 4)
USE_GL_FUNC(Vertex2i, (GLint x, GLint y), (x,y), 130, 8)
USE_GL_FUNC(Vertex2iv, (const GLint *v), (v), 131, 4)
USE_GL_FUNC(Vertex2s, (GLshort x, GLshort y), (x,y), 132, 8)
USE_GL_FUNC(Vertex2sv, (const GLshort *v), (v), 133, 4)
USE_GL_FUNC(Vertex3d, (GLdouble x, GLdouble y, GLdouble z), (x,y,z), 134, 24)
USE_GL_FUNC(Vertex3dv, (const GLdouble *v), (v), 135, 4)
USE_GL_FUNC(Vertex3f, (GLfloat x, GLfloat y, GLfloat z), (x,y,z), 136, 12)
USE_GL_FUNC(Vertex3fv, (const GLfloat *v), (v), 137, 4)
USE_GL_FUNC(Vertex3i, (GLint x, GLint y, GLint z), (x,y,z), 138, 12)
USE_GL_FUNC(Vertex3iv, (const GLint *v), (v), 139, 4)
USE_GL_FUNC(Vertex3s, (GLshort x, GLshort y, GLshort z), (x,y,z), 140, 12)
USE_GL_FUNC(Vertex3sv, (const GLshort *v), (v), 141, 4)
USE_GL_FUNC(Vertex4d, (GLdouble x, GLdouble y, GLdouble z, GLdouble w), (x,y,z,w), 142, 32)
USE_GL_FUNC(Vertex4dv, (const GLdouble *v), (v), 143, 4)
USE_GL_FUNC(Vertex4f, (GLfloat x, GLfloat y, GLfloat z, GLfloat w), (x,y,z,w), 144, 16)
USE_GL_FUNC(Vertex4fv, (const GLfloat *v), (v), 145, 4)
USE_GL_FUNC(Vertex4i, (GLint x, GLint y, GLint z, GLint w), (x,y,z,w), 146, 16)
USE_GL_FUNC(Vertex4iv, (const GLint *v), (v), 147, 4)
USE_GL_FUNC(Vertex4s, (GLshort x, GLshort y, GLshort z, GLshort w), (x,y,z,w), 148, 16)
USE_GL_FUNC(Vertex4sv, (const GLshort *v), (v), 149, 4)
USE_GL_FUNC(ClipPlane, (GLenum plane, const GLdouble *equation), (plane,equation), 150, 8)
USE_GL_FUNC(ColorMaterial, (GLenum face, GLenum mode), (face,mode), 151, 8)
USE_GL_FUNC(CullFace, (GLenum mode), (mode), 152, 4)
USE_GL_FUNC(Fogf, (GLenum pname, GLfloat param), (pname,param), 153, 8)
USE_GL_FUNC(Fogfv, (GLenum pname, const GLfloat *params), (pname,params), 154, 8)
USE_GL_FUNC(Fogi, (GLenum pname, GLint param), (pname,param), 155, 8)
USE_GL_FUNC(Fogiv, (GLenum pname, const GLint *params), (pname,params), 156, 8)
USE_GL_FUNC(FrontFace, (GLenum mode), (mode), 157, 4)
USE_GL_FUNC(Hint, (GLenum target, GLenum mode), (target,mode), 158, 8)
USE_GL_FUNC(Lightf, (GLenum light, GLenum pname, GLfloat param), (light,pname,param), 159, 12)
USE_GL_FUNC(Lightfv, (GLenum light, GLenum pname, const GLfloat *params), (light,pname,params), 160, 12)
USE_GL_FUNC(Lighti, (GLenum light, GLenum pname, GLint param), (light,pname,param), 161, 12)
USE_GL_FUNC(Lightiv, (GLenum light, GLenum pname, const GLint *params), (light,pname,params), 162, 12)
USE_GL_FUNC(LightModelf, (GLenum pname, GLfloat param), (pname,param), 163, 8)
USE_GL_FUNC(LightModelfv, (GLenum pname, const GLfloat *params), (pname,params), 164, 8)
USE_GL_FUNC(LightModeli, (GLenum pname, GLint param), (pname,param), 165, 8)
USE_GL_FUNC(LightModeliv, (GLenum pname, const GLint *params), (pname,params), 166, 8)
USE_GL_FUNC(LineStipple, (GLint factor, GLushort pattern), (factor,pattern), 167, 8)
USE_GL_FUNC(LineWidth, (GLfloat width), (width), 168, 4)
USE_GL_FUNC(Materialf, (GLenum face, GLenum pname, GLfloat param), (face,pname,param), 169, 12)
USE_GL_FUNC(Materialfv, (GLenum face, GLenum pname, const GLfloat *params), (face,pname,params), 170, 12)
USE_GL_FUNC(Materiali, (GLenum face, GLenum pname, GLint param), (face,pname,param), 171, 12)
USE_GL_FUNC(Materialiv, (GLenum face, GLenum pname, const GLint *params), (face,pname,params), 172, 12)
USE_GL_FUNC(PointSize, (GLfloat size), (size), 173, 4)
USE_GL_FUNC(PolygonMode, (GLenum face, GLenum mode), (face,mode), 174, 8)
USE_GL_FUNC(PolygonStipple, (const GLubyte *mask), (mask), 175, 4)
USE_GL_FUNC(Scissor, (GLint x, GLint y, GLsizei width, GLsizei height), (x,y,width,height), 176, 16)
USE_GL_FUNC(ShadeModel, (GLenum mode), (mode), 177, 4)
USE_GL_FUNC(TexParameterf, (GLenum target, GLenum pname, GLfloat param), (target,pname,param), 178, 12)
USE_GL_FUNC(TexParameterfv, (GLenum target, GLenum pname, const GLfloat *params), (target,pname,params), 179, 12)
USE_GL_FUNC(TexParameteri, (GLenum target, GLenum pname, GLint param), (target,pname,param), 180, 12)
USE_GL_FUNC(TexParameteriv, (GLenum target, GLenum pname, const GLint *params), (target,pname,params), 181, 12)
USE_GL_FUNC(TexImage1D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels), (target,level,internalformat,width,border,format,type,pixels), 182, 32)
USE_GL_FUNC(TexImage2D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels), (target,level,internalformat,width,height,border,format,type,pixels), 183, 36)
USE_GL_FUNC(TexEnvf, (GLenum target, GLenum pname, GLfloat param), (target,pname,param), 184, 12)
USE_GL_FUNC(TexEnvfv, (GLenum target, GLenum pname, const GLfloat *params), (target,pname,params), 185, 12)
USE_GL_FUNC(TexEnvi, (GLenum target, GLenum pname, GLint param), (target,pname,param), 186, 12)
USE_GL_FUNC(TexEnviv, (GLenum target, GLenum pname, const GLint *params), (target,pname,params), 187, 12)
USE_GL_FUNC(TexGend, (GLenum coord, GLenum pname, GLdouble param), (coord,pname,param), 188, 16)
USE_GL_FUNC(TexGendv, (GLenum coord, GLenum pname, const GLdouble *params), (coord,pname,params), 189, 12)
USE_GL_FUNC(TexGenf, (GLenum coord, GLenum pname, GLfloat param), (coord,pname,param), 190, 12)
USE_GL_FUNC(TexGenfv, (GLenum coord, GLenum pname, const GLfloat *params), (coord,pname,params), 191, 12)
USE_GL_FUNC(TexGeni, (GLenum coord, GLenum pname, GLint param), (coord,pname,param), 192, 12)
USE_GL_FUNC(TexGeniv, (GLenum coord, GLenum pname, const GLint *params), (coord,pname,params), 193, 12)
USE_GL_FUNC(FeedbackBuffer, (GLsizei size, GLenum type, GLfloat *buffer), (size,type,buffer), 194, 12)
USE_GL_FUNC(SelectBuffer, (GLsizei size, GLuint *buffer), (size,buffer), 195, 8)
USE_GL_FUNC_RET(RenderMode, GLint, (GLenum mode), (mode), 196, 4)
USE_GL_FUNC(InitNames, (void), (), 197, 0)
USE_GL_FUNC(LoadName, (GLuint name), (name), 198, 4)
USE_GL_FUNC(PassThrough, (GLfloat token), (token), 199, 4)
USE_GL_FUNC(PopName, (void), (), 200, 0)
USE_GL_FUNC(PushName, (GLuint name), (name), 201, 4)
USE_GL_FUNC(DrawBuffer, (GLenum mode), (mode), 202, 4)
USE_GL_FUNC(Clear, (GLbitfield mask), (mask), 203, 4)
USE_GL_FUNC(ClearAccum, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), (red,green,blue,alpha), 204, 16)
USE_GL_FUNC(ClearIndex, (GLfloat c), (c), 205, 4)
USE_GL_FUNC(ClearColor, (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha), (red,green,blue,alpha), 206, 16)
USE_GL_FUNC(ClearStencil, (GLint s), (s), 207, 4)
USE_GL_FUNC(ClearDepth, (GLclampd depth), (depth), 208, 8)
USE_GL_FUNC(StencilMask, (GLuint mask), (mask), 209, 4)
USE_GL_FUNC(ColorMask, (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha), (red,green,blue,alpha), 210, 16)
USE_GL_FUNC(DepthMask, (GLboolean flag), (flag), 211, 4)
USE_GL_FUNC(IndexMask, (GLuint mask), (mask), 212, 4)
USE_GL_FUNC(Accum, (GLenum op, GLfloat value), (op,value), 213, 8)
USE_GL_FUNC(Disable, (GLenum cap), (cap), 214, 4)
USE_GL_FUNC(Enable, (GLenum cap), (cap), 215, 4)
USE_GL_FUNC(Finish, (void), (), 216, 0)
USE_GL_FUNC(Flush, (void), (), 217, 0)
USE_GL_FUNC(PopAttrib, (void), (), 218, 0)
USE_GL_FUNC(PushAttrib, (GLbitfield mask), (mask), 219, 4)
USE_GL_FUNC(Map1d, (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points), (target,u1,u2,stride,order,points), 220, 32)
USE_GL_FUNC(Map1f, (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points), (target,u1,u2,stride,order,points), 221, 24)
USE_GL_FUNC(Map2d, (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points), (target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points), 222, 56)
USE_GL_FUNC(Map2f, (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points), (target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points), 223, 40)
USE_GL_FUNC(MapGrid1d, (GLint un, GLdouble u1, GLdouble u2), (un,u1,u2), 224, 20)
USE_GL_FUNC(MapGrid1f, (GLint un, GLfloat u1, GLfloat u2), (un,u1,u2), 225, 12)
USE_GL_FUNC(MapGrid2d, (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2), (un,u1,u2,vn,v1,v2), 226, 40)
USE_GL_FUNC(MapGrid2f, (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2), (un,u1,u2,vn,v1,v2), 227, 24)
USE_GL_FUNC(EvalCoord1d, (GLdouble u), (u), 228, 8)
USE_GL_FUNC(EvalCoord1dv, (const GLdouble *u), (u), 229, 4)
USE_GL_FUNC(EvalCoord1f, (GLfloat u), (u), 230, 4)
USE_GL_FUNC(EvalCoord1fv, (const GLfloat *u), (u), 231, 4)
USE_GL_FUNC(EvalCoord2d, (GLdouble u, GLdouble v), (u,v), 232, 16)
USE_GL_FUNC(EvalCoord2dv, (const GLdouble *u), (u), 233, 4)
USE_GL_FUNC(EvalCoord2f, (GLfloat u, GLfloat v), (u,v), 234, 8)
USE_GL_FUNC(EvalCoord2fv, (const GLfloat *u), (u), 235, 4)
USE_GL_FUNC(EvalMesh1, (GLenum mode, GLint i1, GLint i2), (mode,i1,i2), 236, 12)
USE_GL_FUNC(EvalPoint1, (GLint i), (i), 237, 4)
USE_GL_FUNC(EvalMesh2, (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2), (mode,i1,i2,j1,j2), 238, 20)
USE_GL_FUNC(EvalPoint2, (GLint i, GLint j), (i,j), 239, 8)
USE_GL_FUNC(AlphaFunc, (GLenum func, GLclampf ref), (func,ref), 240, 8)
USE_GL_FUNC(BlendFunc, (GLenum sfactor, GLenum dfactor), (sfactor,dfactor), 241, 8)
USE_GL_FUNC(LogicOp, (GLenum opcode), (opcode), 242, 4)
USE_GL_FUNC(StencilFunc, (GLenum func, GLint ref, GLuint mask), (func,ref,mask), 243, 12)
USE_GL_FUNC(StencilOp, (GLenum fail, GLenum zfail, GLenum zpass), (fail,zfail,zpass), 244, 12)
USE_GL_FUNC(DepthFunc, (GLenum func), (func), 245, 4)
USE_GL_FUNC(PixelZoom, (GLfloat xfactor, GLfloat yfactor), (xfactor,yfactor), 246, 8)
USE_GL_FUNC(PixelTransferf, (GLenum pname, GLfloat param), (pname,param), 247, 8)
USE_GL_FUNC(PixelTransferi, (GLenum pname, GLint param), (pname,param), 248, 8)
USE_GL_FUNC(PixelStoref, (GLenum pname, GLfloat param), (pname,param), 249, 8)
USE_GL_FUNC(PixelStorei, (GLenum pname, GLint param), (pname,param), 250, 8)
USE_GL_FUNC(PixelMapfv, (GLenum map, GLint mapsize, const GLfloat *values), (map,mapsize,values), 251, 12)
USE_GL_FUNC(PixelMapuiv, (GLenum map, GLint mapsize, const GLuint *values), (map,mapsize,values), 252, 12)
USE_GL_FUNC(PixelMapusv, (GLenum map, GLint mapsize, const GLushort *values), (map,mapsize,values), 253, 12)
USE_GL_FUNC(ReadBuffer, (GLenum mode), (mode), 254, 4)
USE_GL_FUNC(CopyPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type), (x,y,width,height,type), 255, 20)
USE_GL_FUNC(ReadPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels), (x,y,width,height,format,type,pixels), 256, 28)
USE_GL_FUNC(DrawPixels, (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels), (width,height,format,type,pixels), 257, 20)
USE_GL_FUNC(GetBooleanv, (GLenum pname, GLboolean *params), (pname,params), 258, 8)
USE_GL_FUNC(GetClipPlane, (GLenum plane, GLdouble *equation), (plane,equation), 259, 8)
USE_GL_FUNC(GetDoublev, (GLenum pname, GLdouble *params), (pname,params), 260, 8)
USE_GL_FUNC_RET(GetError, GLenum, (void), (), 261, 0)
USE_GL_FUNC(GetFloatv, (GLenum pname, GLfloat *params), (pname,params), 262, 8)
USE_GL_FUNC(GetIntegerv, (GLenum pname, GLint *params), (pname,params), 263, 8)
USE_GL_FUNC(GetLightfv, (GLenum light, GLenum pname, GLfloat *params), (light,pname,params), 264, 12)
USE_GL_FUNC(GetLightiv, (GLenum light, GLenum pname, GLint *params), (light,pname,params), 265, 12)
USE_GL_FUNC(GetMapdv, (GLenum target, GLenum query, GLdouble *v), (target,query,v), 266, 12)
USE_GL_FUNC(GetMapfv, (GLenum target, GLenum query, GLfloat *v), (target,query,v), 267, 12)
USE_GL_FUNC(GetMapiv, (GLenum target, GLenum query, GLint *v), (target,query,v), 268, 12)
USE_GL_FUNC(GetMaterialfv, (GLenum face, GLenum pname, GLfloat *params), (face,pname,params), 269, 12)
USE_GL_FUNC(GetMaterialiv, (GLenum face, GLenum pname, GLint *params), (face,pname,params), 270, 12)
USE_GL_FUNC(GetPixelMapfv, (GLenum map, GLfloat *values), (map,values), 271, 8)
USE_GL_FUNC(GetPixelMapuiv, (GLenum map, GLuint *values), (map,values), 272, 8)
USE_GL_FUNC(GetPixelMapusv, (GLenum map, GLushort *values), (map,values), 273, 8)
USE_GL_FUNC(GetPolygonStipple, (GLubyte *mask), (mask), 274, 4)
USE_GL_FUNC_RET(GetString, const GLubyte *, (GLenum name), (name), 275, 4)
USE_GL_FUNC(GetTexEnvfv, (GLenum target, GLenum pname, GLfloat *params), (target,pname,params), 276, 12)
USE_GL_FUNC(GetTexEnviv, (GLenum target, GLenum pname, GLint *params), (target,pname,params), 277, 12)
USE_GL_FUNC(GetTexGendv, (GLenum coord, GLenum pname, GLdouble *params), (coord,pname,params), 278, 12)
USE_GL_FUNC(GetTexGenfv, (GLenum coord, GLenum pname, GLfloat *params), (coord,pname,params), 279, 12)
USE_GL_FUNC(GetTexGeniv, (GLenum coord, GLenum pname, GLint *params), (coord,pname,params), 280, 12)
USE_GL_FUNC(GetTexImage, (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels), (target,level,format,type,pixels), 281, 20)
USE_GL_FUNC(GetTexParameterfv, (GLenum target, GLenum pname, GLfloat *params), (target,pname,params), 282, 12)
USE_GL_FUNC(GetTexParameteriv, (GLenum target, GLenum pname, GLint *params), (target,pname,params), 283, 12)
USE_GL_FUNC(GetTexLevelParameterfv, (GLenum target, GLint level, GLenum pname, GLfloat *params), (target,level,pname,params), 284, 16)
USE_GL_FUNC(GetTexLevelParameteriv, (GLenum target, GLint level, GLenum pname, GLint *params), (target,level,pname,params), 285, 16)
USE_GL_FUNC_RET(IsEnabled, GLboolean, (GLenum cap), (cap), 286, 4)
USE_GL_FUNC_RET(IsList, GLboolean, (GLuint list), (list), 287, 4)
USE_GL_FUNC(DepthRange, (GLclampd zNear, GLclampd zFar), (zNear,zFar), 288, 16)
USE_GL_FUNC(Frustum, (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar), (left,right,bottom,top,zNear,zFar), 289, 48)
USE_GL_FUNC(LoadIdentity, (void), (), 290, 0)
USE_GL_FUNC(LoadMatrixf, (const GLfloat *m), (m), 291, 4)
USE_GL_FUNC(LoadMatrixd, (const GLdouble *m), (m), 292, 4)
USE_GL_FUNC(MatrixMode, (GLenum mode), (mode), 293, 4)
USE_GL_FUNC(MultMatrixf, (const GLfloat *m), (m), 294, 4)
USE_GL_FUNC(MultMatrixd, (const GLdouble *m), (m), 295, 4)
USE_GL_FUNC(Ortho, (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar), (left,right,bottom,top,zNear,zFar), 296, 48)
USE_GL_FUNC(PopMatrix, (void), (), 297, 0)
USE_GL_FUNC(PushMatrix, (void), (), 298, 0)
USE_GL_FUNC(Rotated, (GLdouble angle, GLdouble x, GLdouble y, GLdouble z), (angle,x,y,z), 299, 32)
USE_GL_FUNC(Rotatef, (GLfloat angle, GLfloat x, GLfloat y, GLfloat z), (angle,x,y,z), 300, 16)
USE_GL_FUNC(Scaled, (GLdouble x, GLdouble y, GLdouble z), (x,y,z), 301, 24)
USE_GL_FUNC(Scalef, (GLfloat x, GLfloat y, GLfloat z), (x,y,z), 302, 12)
USE_GL_FUNC(Translated, (GLdouble x, GLdouble y, GLdouble z), (x,y,z), 303, 24)
USE_GL_FUNC(Translatef, (GLfloat x, GLfloat y, GLfloat z), (x,y,z), 304, 12)
USE_GL_FUNC(Viewport, (GLint x, GLint y, GLsizei width, GLsizei height), (x,y,width,height), 305, 16)
USE_GL_FUNC(ArrayElement, (GLint i), (i), 306, 4)
USE_GL_FUNC(BindTexture, (GLenum target, GLuint texture), (target,texture), 307, 8)
USE_GL_FUNC(ColorPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), (size,type,stride,pointer), 308, 16)
USE_GL_FUNC(DisableClientState, (GLenum array), (array), 309, 4)
USE_GL_FUNC(DrawArrays, (GLenum mode, GLint first, GLsizei count), (mode,first,count), 310, 12)
USE_GL_FUNC(DrawElements, (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices), (mode,count,type,indices), 311, 16)
USE_GL_FUNC(EdgeFlagPointer, (GLsizei stride, const GLvoid *pointer), (stride,pointer), 312, 8)
USE_GL_FUNC(EnableClientState, (GLenum array), (array), 313, 4)
USE_GL_FUNC(IndexPointer, (GLenum type, GLsizei stride, const GLvoid *pointer), (type,stride,pointer), 314, 12)
USE_GL_FUNC(Indexub, (GLubyte c), (c), 315, 4)
USE_GL_FUNC(Indexubv, (const GLubyte *c), (c), 316, 4)
USE_GL_FUNC(InterleavedArrays, (GLenum format, GLsizei stride, const GLvoid *pointer), (format,stride,pointer), 317, 12)
USE_GL_FUNC(NormalPointer, (GLenum type, GLsizei stride, const GLvoid *pointer), (type,stride,pointer), 318, 12)
USE_GL_FUNC(PolygonOffset, (GLfloat factor, GLfloat units), (factor,units), 319, 8)
USE_GL_FUNC(TexCoordPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), (size,type,stride,pointer), 320, 16)
USE_GL_FUNC(VertexPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer), (size,type,stride,pointer), 321, 16)
USE_GL_FUNC_RET(AreTexturesResident, GLboolean, (GLsizei n, const GLuint *textures, GLboolean *residences), (n,textures,residences), 322, 12)
USE_GL_FUNC(CopyTexImage1D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border), (target,level,internalformat,x,y,width,border), 323, 28)
USE_GL_FUNC(CopyTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border), (target,level,internalformat,x,y,width,height,border), 324, 32)
USE_GL_FUNC(CopyTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width), (target,level,xoffset,x,y,width), 325, 24)
USE_GL_FUNC(CopyTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height), (target,level,xoffset,yoffset,x,y,width,height), 326, 32)
USE_GL_FUNC(DeleteTextures, (GLsizei n, const GLuint *textures), (n,textures), 327, 8)
USE_GL_FUNC(GenTextures, (GLsizei n, GLuint *textures), (n,textures), 328, 8)
USE_GL_FUNC(GetPointerv, (GLenum pname, GLvoid* *params), (pname,params), 329, 8)
USE_GL_FUNC_RET(IsTexture, GLboolean, (GLuint texture), (texture), 330, 4)
USE_GL_FUNC(PrioritizeTextures, (GLsizei n, const GLuint *textures, const GLclampf *priorities), (n,textures,priorities), 331, 12)
USE_GL_FUNC(TexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels), (target,level,xoffset,width,format,type,pixels), 332, 28)
USE_GL_FUNC(TexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels), (target,level,xoffset,yoffset,width,height,format,type,pixels), 333, 36)
USE_GL_FUNC(PopClientAttrib, (void), (), 334, 0)
USE_GL_FUNC(PushClientAttrib, (GLbitfield mask), (mask), 335, 4)

#undef USE_GL_FUNC
#undef USE_GL_FUNC_RET
