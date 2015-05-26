#ifndef XST_FONTPATH_H
#define XST_FONTPATH_H

#define XST_SET_FONT_PATH	1
#define XST_ADD_FONT_PATH	2
#define XST_REMOVE_FONT_PATH	3

#define XSTsysMax               1
#ifdef XST_GET_SYS_CTL_STRINGS
char *XSTsysCtlString[] = {{"fontserver.emboldenbitmaps"}};
#endif

#endif
