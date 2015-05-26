/* $Id: api.h,v 1.27 2003/03/05 23:25:02 miyayama Exp $ */
/*
 * Copyright (c) 2001,2002 Japan Network Information Center.
 * All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set forth bellow.
 *
 * 			LICENSE TERMS AND CONDITIONS
 *
 * The following License Terms and Conditions apply, unless a different
 * license is obtained from Japan Network Information Center ("JPNIC"),
 * a Japanese association, Kokusai-Kougyou-Kanda Bldg 6F, 2-3-4 Uchi-Kanda,
 * Chiyoda-ku, Tokyo 101-0047, Japan.
 *
 * 1. Use, Modification and Redistribution (including distribution of any
 *    modified or derived work) in source and/or binary forms is permitted
 *    under this License Terms and Conditions.
 *
 * 2. Redistribution of source code must retain the copyright notices as they
 *    appear in each source code file, this License Terms and Conditions.
 *
 * 3. Redistribution in binary form must reproduce the Copyright Notice,
 *    this License Terms and Conditions, in the documentation and/or other
 *    materials provided with the distribution.  For the purposes of binary
 *    distribution the "Copyright Notice" refers to the following language:
 *    "Copyright (c) 2000-2002 Japan Network Information Center.  All rights reserved."
 *
 * 4. The name of JPNIC may not be used to endorse or promote products
 *    derived from this Software without specific prior written approval of
 *    JPNIC.
 *
 * 5. Disclaimer/Limitation of Liability: THIS SOFTWARE IS PROVIDED BY JPNIC
 *    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 *    PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL JPNIC BE LIABLE
 *    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 *    ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 */

/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _IDN_API_H
#define	_IDN_API_H

#pragma ident	"@(#)api.h	1.1	03/09/03 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * libidnkit result code.
 */
typedef enum {
	idn_success,
	idn_notfound,
	idn_invalid_encoding,
	idn_invalid_syntax,
	idn_invalid_name,
	idn_invalid_message,
	idn_invalid_action,
	idn_invalid_codepoint,
	idn_invalid_length,
	idn_buffer_overflow,
	idn_noentry,
	idn_nomemory,
	idn_nofile,
	idn_nomapping,
	idn_context_required,
	idn_prohibited,
	idn_failure	/* !!This must be the last one!! */
} idn_result_t;

/*
 * Actions
 */
#define	IDN_LOCALCONV	0x00000001 /* Local encoding <-> UTF-8 conversion */
#define	IDN_DELIMMAP	0x00000002 /* Delimiter mapping */
#define	IDN_LOCALMAP	0x00000004 /* Local mapping */
#define	IDN_MAP		0x00000008 /* NAMEPREP map */
#define	IDN_NORMALIZE	0x00000010 /* NAMEPREP normalize */
#define	IDN_PROHCHECK	0x00000020 /* NAMEPREP prohibited character check */
#define	IDN_UNASCHECK	0x00000040 /* Unassigned code point check */
#define	IDN_BIDICHECK	0x00000080 /* bidirectional string check */
#define	IDN_ASCCHECK	0x00000100 /* Non-LDH ASCII check */
#define	IDN_IDNCONV	0x00000200 /* UTF-8 <-> IDN encoding conversion */
#define	IDN_LENCHECK	0x00000400 /* Label length check */
#define	IDN_RTCHECK	0x00000800 /* Round trip check */
#define	IDN_UNDOIFERR	0x00001000 /* Option: undo if error occurs */

#define	IDN_ENCODE_QUERY	0x00002000 /* Encode query string */
#define	IDN_DECODE_QUERY	0x00004000 /* Decode query string */

#define	IDN_ENCODE_APP \
(IDN_ENCODE_QUERY | IDN_ASCCHECK)	/* Standard encode */
#define	IDN_DECODE_APP \
(IDN_DECODE_QUERY | IDN_ASCCHECK)	/* Standard decode */

#define	IDN_ENCODE_STORED \
(IDN_ENCODE_QUERY | IDN_ASCCHECK | IDN_UNASCHECK) /* Encode query string */
#define	IDN_DECODE_STORED \
(IDN_DECODE_QUERY | IDN_ASCCHECK | IDN_UNASCHECK) /* Decode query string */

#define	IDN_NAMEPREP \
(IDN_MAP | IDN_NORMALIZE | IDN_PROHCHECK | IDN_BIDICHECK)

/*
 * Application Programming Interface for Internationalized Domain Name
 * Handling.  This module provides high-level APIs for ordinary applications.
 */

#if defined(__STDC__)

extern void idn_enable(int on_off);
extern idn_result_t idn_nameinit(int load_file);
extern idn_result_t idn_encodename(int actions, const char *from, char *to,
	size_t tolen);
extern idn_result_t idn_decodename(int actions, const char *from, char *to,
	size_t tolen);
extern idn_result_t idn_decodename2(int actions, const char *from, char *to,
	size_t tolen, const char *auxencoding);

#else

extern void idn_enable();
extern idn_result_t idn_nameinit();
extern idn_result_t idn_encodename();
extern idn_result_t idn_decodename();
extern idn_result_t idn_decodename2();

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif /* _IDN_API_H */
