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

/* @(#)Xst_colors.h	1.6 04/07/27 SMI */

#ifndef _XST_COLORS_DEF
#define _XST_COLORS_DEF

#define XST_COLOR_TEXT_MASK				0x00000001
#define XST_COLOR_HIGHLIGHT_TEXT_MASK			0x00000002
#define XST_COLOR_HIGHLIGHT_BACKGROUND_TEXT_MASK	0x00000004
#define XST_COLOR_STRIKETHROUGH_MASK			0x00000008
#define XST_COLOR_HIGHLIGHT_STRIKETHROUGH_MASK		0x00000010
#define XST_COLOR_UNDERLINE_MASK			0x00000020
#define XST_COLOR_HIGHLIGHT_UNDERLINE_MASK		0x00000040
#define XST_COLOR_UNDERLINE2_MASK			0x00000080
#define XST_COLOR_HIGHLIGHT_UNDERLINE2_MASK		0x00000100

#define XST_COLOR_ALL_MASK				0x000001FF

#define XST_COLOR_TEXT					0
#define XST_COLOR_HIGHLIGHT_TEXT			1
#define XST_COLOR_HIGHLIGHT_BACKGROUND_TEXT		2
#define XST_COLOR_STRIKETHROUGH				3
#define XST_COLOR_HIGHLIGHT_STRIKETHROUGH		4
#define XST_COLOR_UNDERLINE				5
#define XST_COLOR_HIGHLIGHT_UNDERLINE			6
#define XST_COLOR_UNDERLINE2				7
#define XST_COLOR_HIGHLIGHT_UNDERLINE2			8

#endif
