/* $Id: getprocaddress.c,v 1.5 2002/11/07 16:35:02 brianp Exp $ */

/*
 * Copyright (C) 1999-2002  Brian Paul   All Rights Reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * BRIAN PAUL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * Test that glXGetProcAddress works.
 */

#define GLX_GLXEXT_PROTOTYPES

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* This big list of functions can be generated automatically by
 * running the functions.py script.
 */
static const char *functions[] = {
   "-1.0",
   "glNewList",
   "glEndList",
   "glCallList",
   "glCallLists",
   "glDeleteLists",
   "glGenLists",
   "glListBase",
   "glBegin",
   "glBitmap",
   "glColor3b",
   "glColor3bv",
   "glColor3d",
   "glColor3dv",
   "glColor3f",
   "glColor3fv",
   "glColor3i",
   "glColor3iv",
   "glColor3s",
   "glColor3sv",
   "glColor3ub",
   "glColor3ubv",
   "glColor3ui",
   "glColor3uiv",
   "glColor3us",
   "glColor3usv",
   "glColor4b",
   "glColor4bv",
   "glColor4d",
   "glColor4dv",
   "glColor4f",
   "glColor4fv",
   "glColor4i",
   "glColor4iv",
   "glColor4s",
   "glColor4sv",
   "glColor4ub",
   "glColor4ubv",
   "glColor4ui",
   "glColor4uiv",
   "glColor4us",
   "glColor4usv",
   "glEdgeFlag",
   "glEdgeFlagv",
   "glEnd",
   "glIndexd",
   "glIndexdv",
   "glIndexf",
   "glIndexfv",
   "glIndexi",
   "glIndexiv",
   "glIndexs",
   "glIndexsv",
   "glNormal3b",
   "glNormal3bv",
   "glNormal3d",
   "glNormal3dv",
   "glNormal3f",
   "glNormal3fv",
   "glNormal3i",
   "glNormal3iv",
   "glNormal3s",
   "glNormal3sv",
   "glRasterPos2d",
   "glRasterPos2dv",
   "glRasterPos2f",
   "glRasterPos2fv",
   "glRasterPos2i",
   "glRasterPos2iv",
   "glRasterPos2s",
   "glRasterPos2sv",
   "glRasterPos3d",
   "glRasterPos3dv",
   "glRasterPos3f",
   "glRasterPos3fv",
   "glRasterPos3i",
   "glRasterPos3iv",
   "glRasterPos3s",
   "glRasterPos3sv",
   "glRasterPos4d",
   "glRasterPos4dv",
   "glRasterPos4f",
   "glRasterPos4fv",
   "glRasterPos4i",
   "glRasterPos4iv",
   "glRasterPos4s",
   "glRasterPos4sv",
   "glRectd",
   "glRectdv",
   "glRectf",
   "glRectfv",
   "glRecti",
   "glRectiv",
   "glRects",
   "glRectsv",
   "glTexCoord1d",
   "glTexCoord1dv",
   "glTexCoord1f",
   "glTexCoord1fv",
   "glTexCoord1i",
   "glTexCoord1iv",
   "glTexCoord1s",
   "glTexCoord1sv",
   "glTexCoord2d",
   "glTexCoord2dv",
   "glTexCoord2f",
   "glTexCoord2fv",
   "glTexCoord2i",
   "glTexCoord2iv",
   "glTexCoord2s",
   "glTexCoord2sv",
   "glTexCoord3d",
   "glTexCoord3dv",
   "glTexCoord3f",
   "glTexCoord3fv",
   "glTexCoord3i",
   "glTexCoord3iv",
   "glTexCoord3s",
   "glTexCoord3sv",
   "glTexCoord4d",
   "glTexCoord4dv",
   "glTexCoord4f",
   "glTexCoord4fv",
   "glTexCoord4i",
   "glTexCoord4iv",
   "glTexCoord4s",
   "glTexCoord4sv",
   "glVertex2d",
   "glVertex2dv",
   "glVertex2f",
   "glVertex2fv",
   "glVertex2i",
   "glVertex2iv",
   "glVertex2s",
   "glVertex2sv",
   "glVertex3d",
   "glVertex3dv",
   "glVertex3f",
   "glVertex3fv",
   "glVertex3i",
   "glVertex3iv",
   "glVertex3s",
   "glVertex3sv",
   "glVertex4d",
   "glVertex4dv",
   "glVertex4f",
   "glVertex4fv",
   "glVertex4i",
   "glVertex4iv",
   "glVertex4s",
   "glVertex4sv",
   "glClipPlane",
   "glColorMaterial",
   "glCullFace",
   "glFogf",
   "glFogfv",
   "glFogi",
   "glFogiv",
   "glFrontFace",
   "glHint",
   "glLightf",
   "glLightfv",
   "glLighti",
   "glLightiv",
   "glLightModelf",
   "glLightModelfv",
   "glLightModeli",
   "glLightModeliv",
   "glLineStipple",
   "glLineWidth",
   "glMaterialf",
   "glMaterialfv",
   "glMateriali",
   "glMaterialiv",
   "glPointSize",
   "glPolygonMode",
   "glPolygonStipple",
   "glScissor",
   "glShadeModel",
   "glTexParameterf",
   "glTexParameterfv",
   "glTexParameteri",
   "glTexParameteriv",
   "glTexImage1D",
   "glTexImage2D",
   "glTexEnvf",
   "glTexEnvfv",
   "glTexEnvi",
   "glTexEnviv",
   "glTexGend",
   "glTexGendv",
   "glTexGenf",
   "glTexGenfv",
   "glTexGeni",
   "glTexGeniv",
   "glFeedbackBuffer",
   "glSelectBuffer",
   "glRenderMode",
   "glInitNames",
   "glLoadName",
   "glPassThrough",
   "glPopName",
   "glPushName",
   "glDrawBuffer",
   "glClear",
   "glClearAccum",
   "glClearIndex",
   "glClearColor",
   "glClearStencil",
   "glClearDepth",
   "glStencilMask",
   "glColorMask",
   "glDepthMask",
   "glIndexMask",
   "glAccum",
   "glDisable",
   "glEnable",
   "glFinish",
   "glFlush",
   "glPopAttrib",
   "glPushAttrib",
   "glMap1d",
   "glMap1f",
   "glMap2d",
   "glMap2f",
   "glMapGrid1d",
   "glMapGrid1f",
   "glMapGrid2d",
   "glMapGrid2f",
   "glEvalCoord1d",
   "glEvalCoord1dv",
   "glEvalCoord1f",
   "glEvalCoord1fv",
   "glEvalCoord2d",
   "glEvalCoord2dv",
   "glEvalCoord2f",
   "glEvalCoord2fv",
   "glEvalMesh1",
   "glEvalPoint1",
   "glEvalMesh2",
   "glEvalPoint2",
   "glAlphaFunc",
   "glBlendFunc",
   "glLogicOp",
   "glStencilFunc",
   "glStencilOp",
   "glDepthFunc",
   "glPixelZoom",
   "glPixelTransferf",
   "glPixelTransferi",
   "glPixelStoref",
   "glPixelStorei",
   "glPixelMapfv",
   "glPixelMapuiv",
   "glPixelMapusv",
   "glReadBuffer",
   "glCopyPixels",
   "glReadPixels",
   "glDrawPixels",
   "glGetBooleanv",
   "glGetClipPlane",
   "glGetDoublev",
   "glGetError",
   "glGetFloatv",
   "glGetIntegerv",
   "glGetLightfv",
   "glGetLightiv",
   "glGetMapdv",
   "glGetMapfv",
   "glGetMapiv",
   "glGetMaterialfv",
   "glGetMaterialiv",
   "glGetPixelMapfv",
   "glGetPixelMapuiv",
   "glGetPixelMapusv",
   "glGetPolygonStipple",
   "glGetString",
   "glGetTexEnvfv",
   "glGetTexEnviv",
   "glGetTexGendv",
   "glGetTexGenfv",
   "glGetTexGeniv",
   "glGetTexImage",
   "glGetTexParameterfv",
   "glGetTexParameteriv",
   "glGetTexLevelParameterfv",
   "glGetTexLevelParameteriv",
   "glIsEnabled",
   "glIsList",
   "glDepthRange",
   "glFrustum",
   "glLoadIdentity",
   "glLoadMatrixf",
   "glLoadMatrixd",
   "glMatrixMode",
   "glMultMatrixf",
   "glMultMatrixd",
   "glOrtho",
   "glPopMatrix",
   "glPushMatrix",
   "glRotated",
   "glRotatef",
   "glScaled",
   "glScalef",
   "glTranslated",
   "glTranslatef",
   "glViewport",
   "-1.1",
   "glArrayElement",
   "glColorPointer",
   "glDisableClientState",
   "glDrawArrays",
   "glDrawElements",
   "glEdgeFlagPointer",
   "glEnableClientState",
   "glGetPointerv",
   "glIndexPointer",
   "glInterleavedArrays",
   "glNormalPointer",
   "glTexCoordPointer",
   "glVertexPointer",
   "glPolygonOffset",
   "glCopyTexImage1D",
   "glCopyTexImage2D",
   "glCopyTexSubImage1D",
   "glCopyTexSubImage2D",
   "glTexSubImage1D",
   "glTexSubImage2D",
   "glAreTexturesResident",
   "glBindTexture",
   "glDeleteTextures",
   "glGenTextures",
   "glIsTexture",
   "glPrioritizeTextures",
   "glIndexub",
   "glIndexubv",
   "glPopClientAttrib",
   "glPushClientAttrib",
   "-1.2",
   "glBlendColor",
   "glBlendEquation",
   "glDrawRangeElements",
   "glColorTable",
   "glColorTableParameterfv",
   "glColorTableParameteriv",
   "glCopyColorTable",
   "glGetColorTable",
   "glGetColorTableParameterfv",
   "glGetColorTableParameteriv",
   "glColorSubTable",
   "glCopyColorSubTable",
   "glConvolutionFilter1D",
   "glConvolutionFilter2D",
   "glConvolutionParameterf",
   "glConvolutionParameterfv",
   "glConvolutionParameteri",
   "glConvolutionParameteriv",
   "glCopyConvolutionFilter1D",
   "glCopyConvolutionFilter2D",
   "glGetConvolutionFilter",
   "glGetConvolutionParameterfv",
   "glGetConvolutionParameteriv",
   "glGetSeparableFilter",
   "glSeparableFilter2D",
   "glGetHistogram",
   "glGetHistogramParameterfv",
   "glGetHistogramParameteriv",
   "glGetMinmax",
   "glGetMinmaxParameterfv",
   "glGetMinmaxParameteriv",
   "glHistogram",
   "glMinmax",
   "glResetHistogram",
   "glResetMinmax",
   "glTexImage3D",
   "glTexSubImage3D",
   "glCopyTexSubImage3D",
   "-1.3",
   "glActiveTexture",
   "glClientActiveTexture",
   "glMultiTexCoord1d",
   "glMultiTexCoord1dv",
   "glMultiTexCoord1f",
   "glMultiTexCoord1fv",
   "glMultiTexCoord1i",
   "glMultiTexCoord1iv",
   "glMultiTexCoord1s",
   "glMultiTexCoord1sv",
   "glMultiTexCoord2d",
   "glMultiTexCoord2dv",
   "glMultiTexCoord2f",
   "glMultiTexCoord2fv",
   "glMultiTexCoord2i",
   "glMultiTexCoord2iv",
   "glMultiTexCoord2s",
   "glMultiTexCoord2sv",
   "glMultiTexCoord3d",
   "glMultiTexCoord3dv",
   "glMultiTexCoord3f",
   "glMultiTexCoord3fv",
   "glMultiTexCoord3i",
   "glMultiTexCoord3iv",
   "glMultiTexCoord3s",
   "glMultiTexCoord3sv",
   "glMultiTexCoord4d",
   "glMultiTexCoord4dv",
   "glMultiTexCoord4f",
   "glMultiTexCoord4fv",
   "glMultiTexCoord4i",
   "glMultiTexCoord4iv",
   "glMultiTexCoord4s",
   "glMultiTexCoord4sv",
   "glLoadTransposeMatrixf",
   "glLoadTransposeMatrixd",
   "glMultTransposeMatrixf",
   "glMultTransposeMatrixd",
   "glSampleCoverage",
   "glCompressedTexImage3D",
   "glCompressedTexImage2D",
   "glCompressedTexImage1D",
   "glCompressedTexSubImage3D",
   "glCompressedTexSubImage2D",
   "glCompressedTexSubImage1D",
   "glGetCompressedTexImage",
   "-1.4",
   "glBlendFuncSeparate",
   "glFogCoordf",
   "glFogCoordfv",
   "glFogCoordd",
   "glFogCoorddv",
   "glFogCoordPointer",
   "glMultiDrawArrays",
   "glMultiDrawElements",
   "glPointParameterf",
   "glPointParameterfv",
   "glPointParameteri",
   "glPointParameteriv",
   "glSecondaryColor3b",
   "glSecondaryColor3bv",
   "glSecondaryColor3d",
   "glSecondaryColor3dv",
   "glSecondaryColor3f",
   "glSecondaryColor3fv",
   "glSecondaryColor3i",
   "glSecondaryColor3iv",
   "glSecondaryColor3s",
   "glSecondaryColor3sv",
   "glSecondaryColor3ub",
   "glSecondaryColor3ubv",
   "glSecondaryColor3ui",
   "glSecondaryColor3uiv",
   "glSecondaryColor3us",
   "glSecondaryColor3usv",
   "glSecondaryColorPointer",
   "glWindowPos2d",
   "glWindowPos2dv",
   "glWindowPos2f",
   "glWindowPos2fv",
   "glWindowPos2i",
   "glWindowPos2iv",
   "glWindowPos2s",
   "glWindowPos2sv",
   "glWindowPos3d",
   "glWindowPos3dv",
   "glWindowPos3f",
   "glWindowPos3fv",
   "glWindowPos3i",
   "glWindowPos3iv",
   "glWindowPos3s",
   "glWindowPos3sv",
   "-GL_ARB_multitexture",
   "glActiveTextureARB",
   "glClientActiveTextureARB",
   "glMultiTexCoord1dARB",
   "glMultiTexCoord1dvARB",
   "glMultiTexCoord1fARB",
   "glMultiTexCoord1fvARB",
   "glMultiTexCoord1iARB",
   "glMultiTexCoord1ivARB",
   "glMultiTexCoord1sARB",
   "glMultiTexCoord1svARB",
   "glMultiTexCoord2dARB",
   "glMultiTexCoord2dvARB",
   "glMultiTexCoord2fARB",
   "glMultiTexCoord2fvARB",
   "glMultiTexCoord2iARB",
   "glMultiTexCoord2ivARB",
   "glMultiTexCoord2sARB",
   "glMultiTexCoord2svARB",
   "glMultiTexCoord3dARB",
   "glMultiTexCoord3dvARB",
   "glMultiTexCoord3fARB",
   "glMultiTexCoord3fvARB",
   "glMultiTexCoord3iARB",
   "glMultiTexCoord3ivARB",
   "glMultiTexCoord3sARB",
   "glMultiTexCoord3svARB",
   "glMultiTexCoord4dARB",
   "glMultiTexCoord4dvARB",
   "glMultiTexCoord4fARB",
   "glMultiTexCoord4fvARB",
   "glMultiTexCoord4iARB",
   "glMultiTexCoord4ivARB",
   "glMultiTexCoord4sARB",
   "glMultiTexCoord4svARB",
   "-GL_ARB_transpose_matrix",
   "glLoadTransposeMatrixfARB",
   "glLoadTransposeMatrixdARB",
   "glMultTransposeMatrixfARB",
   "glMultTransposeMatrixdARB",
   "-GL_ARB_multisample",
   "glSampleCoverageARB",
   "-unused",
   "gl__unused413",
   "-GL_ARB_texture_compression",
   "glCompressedTexImage3DARB",
   "glCompressedTexImage2DARB",
   "glCompressedTexImage1DARB",
   "glCompressedTexSubImage3DARB",
   "glCompressedTexSubImage2DARB",
   "glCompressedTexSubImage1DARB",
   "glGetCompressedTexImageARB",
   "-GL_ARB_vertex_blend",
   "glWeightbvARB",
   "glWeightsvARB",
   "glWeightivARB",
   "glWeightfvARB",
   "glWeightdvARB",
   "glWeightubvARB",
   "glWeightusvARB",
   "glWeightuivARB",
   "glWeightPointerARB",
   "glVertexBlendARB",
   "-GL_ARB_matrix_palette",
   "glCurrentPaletteMatrixARB",
   "glMatrixIndexubvARB",
   "glMatrixIndexusvARB",
   "glMatrixIndexuivARB",
   "glMatrixIndexPointerARB",
   "-GL_EXT_blend_color",
   "glBlendColorEXT",
   "-GL_EXT_polygon_offset",
   "glPolygonOffsetEXT",
   "-GL_EXT_texture3D",
   "glTexImage3DEXT",
   "glTexSubImage3DEXT",
   "-GL_SGIS_texture_filter4",
   "glGetTexFilterFuncSGIS",
   "glTexFilterFuncSGIS",
   "-GL_EXT_subtexture",
   "glTexSubImage1DEXT",
   "glTexSubImage2DEXT",
   "-GL_EXT_copy_texture",
   "glCopyTexImage1DEXT",
   "glCopyTexImage2DEXT",
   "glCopyTexSubImage1DEXT",
   "glCopyTexSubImage2DEXT",
   "glCopyTexSubImage3DEXT",
   "-GL_EXT_histogram",
   "glGetHistogramEXT",
   "glGetHistogramParameterfvEXT",
   "glGetHistogramParameterivEXT",
   "glGetMinmaxEXT",
   "glGetMinmaxParameterfvEXT",
   "glGetMinmaxParameterivEXT",
   "glHistogramEXT",
   "glMinmaxEXT",
   "glResetHistogramEXT",
   "glResetMinmaxEXT",
   "-GL_EXT_convolution",
   "glConvolutionFilter1DEXT",
   "glConvolutionFilter2DEXT",
   "glConvolutionParameterfEXT",
   "glConvolutionParameterfvEXT",
   "glConvolutionParameteriEXT",
   "glConvolutionParameterivEXT",
   "glCopyConvolutionFilter1DEXT",
   "glCopyConvolutionFilter2DEXT",
   "glGetConvolutionFilterEXT",
   "glGetConvolutionParameterfvEXT",
   "glGetConvolutionParameterivEXT",
   "glGetSeparableFilterEXT",
   "glSeparableFilter2DEXT",
   "-GL_SGI_color_table",
   "glColorTableSGI",
   "glColorTableParameterfvSGI",
   "glColorTableParameterivSGI",
   "glCopyColorTableSGI",
   "glGetColorTableSGI",
   "glGetColorTableParameterfvSGI",
   "glGetColorTableParameterivSGI",
   "-GL_SGIX_pixel_texture",
   "glPixelTexGenSGIX",
   "-GL_SGIS_pixel_texture",
   "glPixelTexGenParameteriSGIS",
   "glPixelTexGenParameterivSGIS",
   "glPixelTexGenParameterfSGIS",
   "glPixelTexGenParameterfvSGIS",
   "glGetPixelTexGenParameterivSGIS",
   "glGetPixelTexGenParameterfvSGIS",
   "-GL_SGIS_texture4D",
   "glTexImage4DSGIS",
   "glTexSubImage4DSGIS",
   "-GL_EXT_texture_object",
   "glAreTexturesResidentEXT",
   "glBindTextureEXT",
   "glDeleteTexturesEXT",
   "glGenTexturesEXT",
   "glIsTextureEXT",
   "glPrioritizeTexturesEXT",
   "-GL_SGIS_detail_texture",
   "glDetailTexFuncSGIS",
   "glGetDetailTexFuncSGIS",
   "-GL_SGIS_sharpen_texture",
   "glSharpenTexFuncSGIS",
   "glGetSharpenTexFuncSGIS",
   "-GL_SGIS_multisample",
   "glSampleMaskSGIS",
   "glSamplePatternSGIS",
   "-GL_EXT_vertex_array",
   "glArrayElementEXT",
   "glColorPointerEXT",
   "glDrawArraysEXT",
   "glEdgeFlagPointerEXT",
   "glGetPointervEXT",
   "glIndexPointerEXT",
   "glNormalPointerEXT",
   "glTexCoordPointerEXT",
   "glVertexPointerEXT",
   "-GL_EXT_blend_minmax",
   "glBlendEquationEXT",
   "-GL_SGIX_sprite",
   "glSpriteParameterfSGIX",
   "glSpriteParameterfvSGIX",
   "glSpriteParameteriSGIX",
   "glSpriteParameterivSGIX",
   "-GL_ARB_point_parameters",
   "glPointParameterfARB",
   "glPointParameterfvARB",
   "-GL_EXT_point_parameters",
   "glPointParameterfEXT",
   "glPointParameterfvEXT",
   "-GL_SGIS_point_parameters",
   "glPointParameterfSGIS",
   "glPointParameterfvSGIS",
   "-GL_SGIX_instruments",
   "glGetInstrumentsSGIX",
   "glInstrumentsBufferSGIX",
   "glPollInstrumentsSGIX",
   "glReadInstrumentsSGIX",
   "glStartInstrumentsSGIX",
   "glStopInstrumentsSGIX",
   "-GL_SGIX_framezoom",
   "glFrameZoomSGIX",
   "-GL_SGIX_tag_sample_buffer",
   "glTagSampleBufferSGIX",
   "-GL_SGIX_polynomial_ffd",
   "glDeformationMap3dSGIX",
   "glDeformationMap3fSGIX",
   "glDeformSGIX",
   "glLoadIdentityDeformationMapSGIX",
   "-GL_SGIX_reference_plane",
   "glReferencePlaneSGIX",
   "-GL_SGIX_flush_raster",
   "glFlushRasterSGIX",
   "-GL_SGIS_fog_function",
   "glFogFuncSGIS",
   "glGetFogFuncSGIS",
   "-GL_HP_image_transform",
   "glImageTransformParameteriHP",
   "glImageTransformParameterfHP",
   "glImageTransformParameterivHP",
   "glImageTransformParameterfvHP",
   "glGetImageTransformParameterivHP",
   "glGetImageTransformParameterfvHP",
   "-GL_EXT_color_subtable",
   "glColorSubTableEXT",
   "glCopyColorSubTableEXT",
   "-GL_PGI_misc_hints",
   "glHintPGI",
   "-GL_EXT_paletted_texture",
   "glColorTableEXT",
   "glGetColorTableEXT",
   "glGetColorTableParameterivEXT",
   "glGetColorTableParameterfvEXT",
   "-GL_SGIX_list_priority",
   "glGetListParameterfvSGIX",
   "glGetListParameterivSGIX",
   "glListParameterfSGIX",
   "glListParameterfvSGIX",
   "glListParameteriSGIX",
   "glListParameterivSGIX",
   "-GL_EXT_index_material",
   "glIndexMaterialEXT",
   "-GL_EXT_index_func",
   "glIndexFuncEXT",
   "-GL_EXT_compiled_vertex_array",
   "glLockArraysEXT",
   "glUnlockArraysEXT",
   "-GL_EXT_cull_vertex",
   "glCullParameterdvEXT",
   "glCullParameterfvEXT",
   "-GL_SGIX_fragment_lighting",
   "glFragmentColorMaterialSGIX",
   "glFragmentLightfSGIX",
   "glFragmentLightfvSGIX",
   "glFragmentLightiSGIX",
   "glFragmentLightivSGIX",
   "glFragmentLightModelfSGIX",
   "glFragmentLightModelfvSGIX",
   "glFragmentLightModeliSGIX",
   "glFragmentLightModelivSGIX",
   "glFragmentMaterialfSGIX",
   "glFragmentMaterialfvSGIX",
   "glFragmentMaterialiSGIX",
   "glFragmentMaterialivSGIX",
   "glGetFragmentLightfvSGIX",
   "glGetFragmentLightivSGIX",
   "glGetFragmentMaterialfvSGIX",
   "glGetFragmentMaterialivSGIX",
   "glLightEnviSGIX",
   "-GL_EXT_draw_range_elements",
   "glDrawRangeElementsEXT",
   "-GL_EXT_light_texture",
   "glApplyTextureEXT",
   "glTextureLightEXT",
   "glTextureMaterialEXT",
   "-GL_SGIX_async",
   "glAsyncMarkerSGIX",
   "glFinishAsyncSGIX",
   "glPollAsyncSGIX",
   "glGenAsyncMarkersSGIX",
   "glDeleteAsyncMarkersSGIX",
   "glIsAsyncMarkerSGIX",
   "-GL_INTEL_parallel_arrays",
   "glVertexPointervINTEL",
   "glNormalPointervINTEL",
   "glColorPointervINTEL",
   "glTexCoordPointervINTEL",
   "-GL_EXT_pixel_transform",
   "glPixelTransformParameteriEXT",
   "glPixelTransformParameterfEXT",
   "glPixelTransformParameterivEXT",
   "glPixelTransformParameterfvEXT",
   "-GL_EXT_secondary_color",
   "glSecondaryColor3bEXT",
   "glSecondaryColor3bvEXT",
   "glSecondaryColor3dEXT",
   "glSecondaryColor3dvEXT",
   "glSecondaryColor3fEXT",
   "glSecondaryColor3fvEXT",
   "glSecondaryColor3iEXT",
   "glSecondaryColor3ivEXT",
   "glSecondaryColor3sEXT",
   "glSecondaryColor3svEXT",
   "glSecondaryColor3ubEXT",
   "glSecondaryColor3ubvEXT",
   "glSecondaryColor3uiEXT",
   "glSecondaryColor3uivEXT",
   "glSecondaryColor3usEXT",
   "glSecondaryColor3usvEXT",
   "glSecondaryColorPointerEXT",
   "-GL_EXT_texture_perturb_normal",
   "glTextureNormalEXT",
   "-GL_EXT_multi_draw_arrays",
   "glMultiDrawArraysEXT",
   "glMultiDrawElementsEXT",
   "-GL_EXT_fog_coord",
   "glFogCoordfEXT",
   "glFogCoordfvEXT",
   "glFogCoorddEXT",
   "glFogCoorddvEXT",
   "glFogCoordPointerEXT",
   "-GL_EXT_coordinate_frame",
   "glTangent3bEXT",
   "glTangent3bvEXT",
   "glTangent3dEXT",
   "glTangent3dvEXT",
   "glTangent3fEXT",
   "glTangent3fvEXT",
   "glTangent3iEXT",
   "glTangent3ivEXT",
   "glTangent3sEXT",
   "glTangent3svEXT",
   "glBinormal3bEXT",
   "glBinormal3bvEXT",
   "glBinormal3dEXT",
   "glBinormal3dvEXT",
   "glBinormal3fEXT",
   "glBinormal3fvEXT",
   "glBinormal3iEXT",
   "glBinormal3ivEXT",
   "glBinormal3sEXT",
   "glBinormal3svEXT",
   "glTangentPointerEXT",
   "glBinormalPointerEXT",
   "-GL_SUNX_constant_data",
   "glFinishTextureSUNX",
   "-GL_SUN_global_alpha",
   "glGlobalAlphaFactorbSUN",
   "glGlobalAlphaFactorsSUN",
   "glGlobalAlphaFactoriSUN",
   "glGlobalAlphaFactorfSUN",
   "glGlobalAlphaFactordSUN",
   "glGlobalAlphaFactorubSUN",
   "glGlobalAlphaFactorusSUN",
   "glGlobalAlphaFactoruiSUN",
   "-GL_SUN_triangle_list",
   "glReplacementCodeuiSUN",
   "glReplacementCodeusSUN",
   "glReplacementCodeubSUN",
   "glReplacementCodeuivSUN",
   "glReplacementCodeusvSUN",
   "glReplacementCodeubvSUN",
   "glReplacementCodePointerSUN",
   "-GL_SUN_vertex",
   "glColor4ubVertex2fSUN",
   "glColor4ubVertex2fvSUN",
   "glColor4ubVertex3fSUN",
   "glColor4ubVertex3fvSUN",
   "glColor3fVertex3fSUN",
   "glColor3fVertex3fvSUN",
   "glNormal3fVertex3fSUN",
   "glNormal3fVertex3fvSUN",
   "glColor4fNormal3fVertex3fSUN",
   "glColor4fNormal3fVertex3fvSUN",
   "glTexCoord2fVertex3fSUN",
   "glTexCoord2fVertex3fvSUN",
   "glTexCoord4fVertex4fSUN",
   "glTexCoord4fVertex4fvSUN",
   "glTexCoord2fColor4ubVertex3fSUN",
   "glTexCoord2fColor4ubVertex3fvSUN",
   "glTexCoord2fColor3fVertex3fSUN",
   "glTexCoord2fColor3fVertex3fvSUN",
   "glTexCoord2fNormal3fVertex3fSUN",
   "glTexCoord2fNormal3fVertex3fvSUN",
   "glTexCoord2fColor4fNormal3fVertex3fSUN",
   "glTexCoord2fColor4fNormal3fVertex3fvSUN",
   "glTexCoord4fColor4fNormal3fVertex4fSUN",
   "glTexCoord4fColor4fNormal3fVertex4fvSUN",
   "glReplacementCodeuiVertex3fSUN",
   "glReplacementCodeuiVertex3fvSUN",
   "glReplacementCodeuiColor4ubVertex3fSUN",
   "glReplacementCodeuiColor4ubVertex3fvSUN",
   "glReplacementCodeuiColor3fVertex3fSUN",
   "glReplacementCodeuiColor3fVertex3fvSUN",
   "glReplacementCodeuiNormal3fVertex3fSUN",
   "glReplacementCodeuiNormal3fVertex3fvSUN",
   "glReplacementCodeuiColor4fNormal3fVertex3fSUN",
   "glReplacementCodeuiColor4fNormal3fVertex3fvSUN",
   "glReplacementCodeuiTexCoord2fVertex3fSUN",
   "glReplacementCodeuiTexCoord2fVertex3fvSUN",
   "glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN",
   "glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN",
   "glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN",
   "glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN",
   "-GL_EXT_blend_func_separate",
   "glBlendFuncSeparateEXT",
   "glBlendFuncSeparateINGR",
   "-GL_EXT_vertex_weighting",
   "glVertexWeightfEXT",
   "glVertexWeightfvEXT",
   "glVertexWeightPointerEXT",
   "-GL_NV_vertex_array_range",
   "glFlushVertexArrayRangeNV",
   "glVertexArrayRangeNV",
   "-GL_NV_register_combiners",
   "glCombinerParameterfvNV",
   "glCombinerParameterfNV",
   "glCombinerParameterivNV",
   "glCombinerParameteriNV",
   "glCombinerInputNV",
   "glCombinerOutputNV",
   "glFinalCombinerInputNV",
   "glGetCombinerInputParameterfvNV",
   "glGetCombinerInputParameterivNV",
   "glGetCombinerOutputParameterfvNV",
   "glGetCombinerOutputParameterivNV",
   "glGetFinalCombinerInputParameterfvNV",
   "glGetFinalCombinerInputParameterivNV",
   "-GL_MESA_resize_buffers",
   "glResizeBuffersMESA",
   "-GL_MESA_window_pos",
   "glWindowPos2dMESA",
   "glWindowPos2dvMESA",
   "glWindowPos2fMESA",
   "glWindowPos2fvMESA",
   "glWindowPos2iMESA",
   "glWindowPos2ivMESA",
   "glWindowPos2sMESA",
   "glWindowPos2svMESA",
   "glWindowPos3dMESA",
   "glWindowPos3dvMESA",
   "glWindowPos3fMESA",
   "glWindowPos3fvMESA",
   "glWindowPos3iMESA",
   "glWindowPos3ivMESA",
   "glWindowPos3sMESA",
   "glWindowPos3svMESA",
   "glWindowPos4dMESA",
   "glWindowPos4dvMESA",
   "glWindowPos4fMESA",
   "glWindowPos4fvMESA",
   "glWindowPos4iMESA",
   "glWindowPos4ivMESA",
   "glWindowPos4sMESA",
   "glWindowPos4svMESA",
   "-GL_IBM_multimode_draw_arrays",
   "glMultiModeDrawArraysIBM",
   "glMultiModeDrawElementsIBM",
   "-GL_IBM_vertex_array_lists",
   "glColorPointerListIBM",
   "glSecondaryColorPointerListIBM",
   "glEdgeFlagPointerListIBM",
   "glFogCoordPointerListIBM",
   "glIndexPointerListIBM",
   "glNormalPointerListIBM",
   "glTexCoordPointerListIBM",
   "glVertexPointerListIBM",
   "-GL_3DFX_tbuffer",
   "glTbufferMask3DFX",
   "-GL_EXT_multisample",
   "glSampleMaskEXT",
   "glSamplePatternEXT",
   "-GL_SGIS_texture_color_mask",
   "glTextureColorMaskSGIS",
   "-GL_SGIX_igloo_interface",
   "glIglooInterfaceSGIX",
   "-GL_NV_fence",
   "glGenFencesNV",
   "glDeleteFencesNV",
   "glSetFenceNV",
   "glTestFenceNV",
   "glFinishFenceNV",
   "glIsFenceNV",
   "glGetFenceivNV",
   "-GL_NV_evaluators",
   "glMapControlPointsNV",
   "glMapParameterivNV",
   "glMapParameterfvNV",
   "glGetMapControlPointsNV",
   "glGetMapParameterivNV",
   "glGetMapParameterfvNV",
   "glGetMapAttribParameterivNV",
   "glGetMapAttribParameterfvNV",
   "glEvalMapsNV",
   "-GL_NV_register_combiners2",
   "glCombinerStageParameterfvNV",
   "glGetCombinerStageParameterfvNV",
   "-GL_NV_vertex_program",
   "glBindProgramNV",
   "glDeleteProgramsNV",
   "glExecuteProgramNV",
   "glGenProgramsNV",
   "glAreProgramsResidentNV",
   "glRequestResidentProgramsNV",
   "glGetProgramParameterfvNV",
   "glGetProgramParameterdvNV",
   "glGetProgramivNV",
   "glGetProgramStringNV",
   "glGetTrackMatrixivNV",
   "glGetVertexAttribdvNV",
   "glGetVertexAttribfvNV",
   "glGetVertexAttribivNV",
   "glGetVertexAttribPointervNV",
   "glIsProgramNV",
   "glLoadProgramNV",
   "glProgramParameter4fNV",
   "glProgramParameter4dNV",
   "glProgramParameter4dvNV",
   "glProgramParameter4fvNV",
   "glProgramParameters4dvNV",
   "glProgramParameters4fvNV",
   "glTrackMatrixNV",
   "glVertexAttribPointerNV",
   "glVertexAttrib1sNV",
   "glVertexAttrib1fNV",
   "glVertexAttrib1dNV",
   "glVertexAttrib2sNV",
   "glVertexAttrib2fNV",
   "glVertexAttrib2dNV",
   "glVertexAttrib3sNV",
   "glVertexAttrib3fNV",
   "glVertexAttrib3dNV",
   "glVertexAttrib4sNV",
   "glVertexAttrib4fNV",
   "glVertexAttrib4dNV",
   "glVertexAttrib4ubNV",
   "glVertexAttrib1svNV",
   "glVertexAttrib1fvNV",
   "glVertexAttrib1dvNV",
   "glVertexAttrib2svNV",
   "glVertexAttrib2fvNV",
   "glVertexAttrib2dvNV",
   "glVertexAttrib3svNV",
   "glVertexAttrib3fvNV",
   "glVertexAttrib3dvNV",
   "glVertexAttrib4svNV",
   "glVertexAttrib4fvNV",
   "glVertexAttrib4dvNV",
   "glVertexAttrib4ubvNV",
   "glVertexAttribs1svNV",
   "glVertexAttribs1fvNV",
   "glVertexAttribs1dvNV",
   "glVertexAttribs2svNV",
   "glVertexAttribs2fvNV",
   "glVertexAttribs2dvNV",
   "glVertexAttribs3svNV",
   "glVertexAttribs3fvNV",
   "glVertexAttribs3dvNV",
   "glVertexAttribs4svNV",
   "glVertexAttribs4fvNV",
   "glVertexAttribs4dvNV",
   "glVertexAttribs4ubvNV",
   "-GL_ARB_window_pos",
   "glWindowPos2dARB",
   "glWindowPos2fARB",
   "glWindowPos2iARB",
   "glWindowPos2sARB",
   "glWindowPos2dvARB",
   "glWindowPos2fvARB",
   "glWindowPos2ivARB",
   "glWindowPos2svARB",
   "glWindowPos3dARB",
   "glWindowPos3fARB",
   "glWindowPos3iARB",
   "glWindowPos3sARB",
   "glWindowPos3dvARB",
   "glWindowPos3fvARB",
   "glWindowPos3ivARB",
   "glWindowPos3svARB",
   "-EXT_stencil_two_side",
   "glActiveStencilFaceEXT",

   NULL
};


static int
extension_supported(const char *haystack, const char *needle)
{
   if (strstr(haystack, needle))
      return 1;
   else
      return 0;
}


static void
test_functions( const char *extensions )
{
   int failures = 0, passes = 0;
   int doTests;
   int i;

   for (i = 0; functions[i]; i++) {
      if (functions[i][0] == '-') {
         if (functions[i][1] == '1') {
            doTests = 1;
         }
         else {
            /* check if the named extension is available */
            doTests = extension_supported(extensions, functions[i]+1);
         }
         if (doTests)
            printf("Testing %s functions\n", functions[i] + 1);
         failures = 0;
         passes = 0;
      }
      else if (doTests) {
         void *p = (void *) glXGetProcAddressARB((const GLubyte *) functions[i]);
         if (p) {
            passes++;
         }
         else {
            printf("   glXGetProcAddress(%s) failed!\n", functions[i]);
            failures++;
         }
      }

      if (doTests && (!functions[i + 1] || functions[i + 1][0] == '-')) {
         if (failures > 0) {
            printf("   %d failures\n", failures);
         }
         else if (i > 0) {
            printf("   %d passed.\n", passes);
         }
      }
   }
}



static void
print_screen_info(Display *dpy, int scrnum, Bool allowDirect)
{
   Window win;
   int attribSingle[] = {
      GLX_RGBA,
      GLX_RED_SIZE, 1,
      GLX_GREEN_SIZE, 1,
      GLX_BLUE_SIZE, 1,
      None };
   int attribDouble[] = {
      GLX_RGBA,
      GLX_RED_SIZE, 1,
      GLX_GREEN_SIZE, 1,
      GLX_BLUE_SIZE, 1,
      GLX_DOUBLEBUFFER,
      None };

   XSetWindowAttributes attr;
   unsigned long mask;
   Window root;
   GLXContext ctx;
   XVisualInfo *visinfo;
   int width = 100, height = 100;

   root = RootWindow(dpy, scrnum);

   visinfo = glXChooseVisual(dpy, scrnum, attribSingle);
   if (!visinfo) {
      visinfo = glXChooseVisual(dpy, scrnum, attribDouble);
      if (!visinfo) {
         fprintf(stderr, "Error: couldn't find RGB GLX visual\n");
         return;
      }
   }

   attr.background_pixel = 0;
   attr.border_pixel = 0;
   attr.colormap = XCreateColormap(dpy, root, visinfo->visual, AllocNone);
   attr.event_mask = StructureNotifyMask | ExposureMask;
   mask = CWBackPixel | CWBorderPixel | CWColormap | CWEventMask;
   win = XCreateWindow(dpy, root, 0, 0, width, height,
		       0, visinfo->depth, InputOutput,
		       visinfo->visual, mask, &attr);

   ctx = glXCreateContext( dpy, visinfo, NULL, allowDirect );
   if (!ctx) {
      fprintf(stderr, "Error: glXCreateContext failed\n");
      XDestroyWindow(dpy, win);
      return;
   }

   if (glXMakeCurrent(dpy, win, ctx)) {
      test_functions( (const char *) glGetString(GL_EXTENSIONS) );
   }
   else {
      fprintf(stderr, "Error: glXMakeCurrent failed\n");
   }

   glXDestroyContext(dpy, ctx);
   XDestroyWindow(dpy, win);
}


int
main(int argc, char *argv[])
{
   char *displayName = NULL;
   Display *dpy;

   dpy = XOpenDisplay(displayName);
   if (!dpy) {
      fprintf(stderr, "Error: unable to open display %s\n", displayName);
      return -1;
   }

   print_screen_info(dpy, 0, GL_TRUE);

   XCloseDisplay(dpy);

   return 0;
}
