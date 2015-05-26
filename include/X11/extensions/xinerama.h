/******************************************************************

              Copyright 1990, 1991, by Sun Microsystems, Inc.

Permission to use, copy, modify, distribute, and sell this software
and its documentation for any purpose is hereby granted without fee,
provided that the above copyright notice appear in all copies and
that both that copyright notice and this permission notice appear
in supporting documentation, and that the name of Sun Microsystems, Inc.
not be used in advertising or publicity pertaining to distribution
of the software without specific, written prior permission.
Sun Microsystems, Inc. makes no representations about the suitability of
this software for any purpose.  It is provided "as is" without
express or implied warranty.

Sun Microsystems Inc. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS
SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS,
IN NO EVENT SHALL Sun Microsystems, Inc. BE LIABLE FOR ANY SPECIAL, INDIRECT
OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE
OR PERFORMANCE OF THIS SOFTWARE.

  Author: John McKernan (jmck@Sun.COM)
                                             Sun Microsystems, Inc.
******************************************************************/

/* Xinerama header file */

#ifndef _XINERAMA_H_
#define _XINERAMA_H_

#define MAXFRAMEBUFFERS       16
#define XINERAMA_PLACE_TOP    1
#define XINERAMA_PLACE_BOTTOM 2
#define XINERAMA_PLACE_RIGHT  4
#define XINERAMA_PLACE_LEFT   8

Bool XineramaGetState(Display*, int);
Status XineramaGetInfo(Display*, int, XRectangle*, unsigned char*, int*);
Status XineramaGetCenterHint(Display*, int, int*, int*);

#endif /* _XINERAMA_H_ */
