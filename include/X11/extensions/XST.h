/*
 * Copyright © 2001, 2002, Sun Microsystems, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Sun Microsystems, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * This software is provided "AS IS," without a warranty of any kind.
 *
 * ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED.
 * SUN AND ITS LICENSORS SHALL NOT BE LIABLE FOR ANY DAMAGES OR
 * LIABILITIES  SUFFERED BY LICENSEE AS A RESULT OF  OR RELATING TO USE,
 * MODIFICATION OR DISTRIBUTION OF THE SOFTWARE OR ITS DERIVATIVES.
 * IN NO EVENT WILL SUN OR ITS LICENSORS BE LIABLE FOR ANY LOST REVENUE,
 * PROFIT OR DATA, OR FOR DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL,
 * INCIDENTAL OR PUNITIVE DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE
 * THEORY OF LIABILITY, ARISING OUT OF THE USE OF OR INABILITY TO USE
 * SOFTWARE, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 */

/* @(#)XST.h	1.5	04/07/27 SMI */

Bool XSTQueryExtension(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status XSTQueryVersion(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Bool XSTCapable(
#if NeedFunctionPrototypes
Display *
#endif
);

Bool XSTEnable(
#if NeedFunctionPrototypes
Display *, 
int
#endif
);

Status XSTDisable(
#if NeedFunctionPrototypes
Display *
#endif
);

Status XSTInfo(
#if NeedFunctionPrototypes
Display *, 
CARD16 *, 
BOOL *
#endif
);


Status  XSTTypeEnvNewCopy(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvDispose(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvAddCertificate(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvRemoveCertificate(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvSetFontFallbacks(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvGetFontFallbacks(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvFindFontsByName(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvCreateFont(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvCreateFontFromStream(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvDestroyFont(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvRemoveFont(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvAddFontCertificates(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvRemoveFontCertificates(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTTypeEnvGetFontCertificates(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTFontGetNameTags(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTFontGetNameString(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTFontGetType(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTFontGetBaselines(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTFontGetFeatures(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleNewCopy(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleDispose(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleCompare(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleIsEmpty(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleClear(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleSetAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleGetAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleResetAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleCopyAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleOverwriteAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleUnderwriteAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTStyleGetBaselines(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutNewEmpty(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutNewCopy(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutDispose(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutClear(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutSetAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutGetAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutCopyAttribute(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutResetAttributes(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutSetText(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutGetText(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutTextChanged(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutSetStyle(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutGetStyle(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutGetCommonStyle(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutHitTest(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutOffsetToCaret(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutMoveCaret(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutSetLineBreak(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTLayoutCountLineChars(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTGetTypographicBounds(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTGetOpticalBounds(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTRenderLayout(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTSetFontSubstitutionList(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTGetFontSubstitutionList(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

Status  XSTFindMissingChars(
#if NeedFunctionPrototypes
Display *, 
int *, 
int *
#endif
);

