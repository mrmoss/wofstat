/*	Copyright (C) 1989 AT&T					*/
/*	  All Rights Reserved  					*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _FLOATINGPOINT_H
#define	_FLOATINGPOINT_H

#pragma ident	"@(#)floatingpoint.h	2.10	09/05/19 SMI"

#include <sys/ieeefp.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *	@(#)floatingpoint.h	2.10 09/05/19 ICL version  2.2	(88/11/03)
 *		Copyright ICL 1988
 */

/*
 * <floatingpoint.h> contains definitions for constants, types, variables,
 * and functions for:
 *	IEEE floating-point arithmetic base conversion;
 *	IEEE floating-point arithmetic modes;
 *	IEEE floating-point arithmetic exception handling.
 */

#ifndef __P
#ifdef __STDC__
#define	__P(p)	p
#else
#define	__P(p)	()
#endif
#endif	/* !defined(__P) */

#ifdef __STDC__
#include <stdio_tag.h>
#if __cplusplus >= 199711L
namespace std {
#endif
#if !defined(_FILEDEFED) || __cplusplus >= 199711L
#define	_FILEDEFED
typedef	__FILE FILE;
#endif
#if __cplusplus >= 199711L
} // namespace std
#define	_FLOATINGPOINT_FILE	std::FILE
#else
#define	_FLOATINGPOINT_FILE	FILE
#endif
#endif	/* defined(__STDC__) */

#define	N_IEEE_EXCEPTION 5	/* Number of floating-point exceptions. */

typedef int sigfpe_code_type;	/* Type of SIGFPE code. */

typedef void (*sigfpe_handler_type)();	/* Pointer to exception handler */

#define	SIGFPE_DEFAULT (void (*)())0	/* default exception handling */
#define	SIGFPE_IGNORE  (void (*)())1  	/* ignore this exception or code */
#define	SIGFPE_ABORT   (void (*)())2  	/* force abort on exception */

extern sigfpe_handler_type sigfpe __P((sigfpe_code_type, sigfpe_handler_type));

/*
 * Types for IEEE floating point.
 */
typedef float single;

#ifndef _EXTENDED
#define	_EXTENDED
typedef unsigned extended[3];
#endif

typedef long double quadruple;	/* Quadruple-precision type. */

typedef unsigned fp_exception_field_type;
				/*
				 * A field containing fp_exceptions OR'ed
				 * together.
				 */
/*
 * Definitions for base conversion.
 */
#define	DECIMAL_STRING_LENGTH 512	/* Size of buffer in decimal_record. */

typedef char decimal_string[DECIMAL_STRING_LENGTH];
				/* Decimal significand. */

typedef struct {
	enum fp_class_type fpclass;
	int	sign;
	int	exponent;
	decimal_string ds;	/* Significand - each char contains an ascii */
				/* digit, except the string-terminating */
				/* ascii null. */
	int	more;		/* On conversion from decimal to binary, != 0 */
				/* indicates more non-zero digits following */
				/* ds. */
	int 	ndigits;	/* On fixed_form conversion from binary to */
				/* decimal, contains number of digits */
				/* required for ds. */
} decimal_record;

enum decimal_form {
	fixed_form,		/* Fortran F format: ndigits specifies number */
				/* of digits after point; if negative, */
				/* specifies rounding to occur to left of */
				/* point. */
	floating_form		/* Fortran E format: ndigits specifies number */
				/* of significant digits. */
};

typedef struct {
	enum fp_direction_type rd;
				/* Rounding direction. */
	enum decimal_form df;	/* Format for conversion from binary to */
				/* decimal. */
	int ndigits;		/* Number of digits for conversion. */
} decimal_mode;

enum decimal_string_form {	/* Valid decimal number string formats. */
	invalid_form,		/* Not a valid decimal string format. */
	whitespace_form,	/* All white space - valid in Fortran! */
	fixed_int_form,		/* <digs> 		*/
	fixed_intdot_form,	/* <digs>. 		*/
	fixed_dotfrac_form,	/* .<digs>		*/
	fixed_intdotfrac_form,	/* <digs>.<frac>	*/
	floating_int_form,	/* <digs><exp>		*/
	floating_intdot_form,	/* <digs>.<exp>		*/
	floating_dotfrac_form,	/* .<digs><exp>		*/
	floating_intdotfrac_form, /* <digs>.<digs><exp>	*/
	inf_form,		/* inf			*/
	infinity_form,		/* infinity		*/
	nan_form,		/* nan			*/
	nanstring_form		/* nan(string)		*/
};

extern void single_to_decimal __P((single *, decimal_mode *, decimal_record *,
				fp_exception_field_type *));
extern void double_to_decimal __P((double *, decimal_mode *, decimal_record *,
				fp_exception_field_type *));
extern void extended_to_decimal __P((extended *, decimal_mode *,
				decimal_record *, fp_exception_field_type *));
extern void quadruple_to_decimal __P((quadruple *, decimal_mode *,
				decimal_record *, fp_exception_field_type *));

extern void decimal_to_single __P((single *, decimal_mode *, decimal_record *,
				fp_exception_field_type *));
extern void decimal_to_double __P((double *, decimal_mode *, decimal_record *,
				fp_exception_field_type *));
extern void decimal_to_extended __P((extended *, decimal_mode *,
				decimal_record *, fp_exception_field_type *));
extern void decimal_to_quadruple __P((quadruple *, decimal_mode *,
				decimal_record *, fp_exception_field_type *));

extern void string_to_decimal __P((char **, int, int, decimal_record *,
				enum decimal_string_form *, char **));
extern void func_to_decimal __P((char **, int, int, decimal_record *,
				enum decimal_string_form *, char **,
				int (*)(void), int *, int (*)(int)));
extern void file_to_decimal __P((char **, int, int, decimal_record *,
				enum decimal_string_form *, char **,
				_FLOATINGPOINT_FILE *, int *));

extern char *seconvert __P((single *, int, int *, int *, char *));
extern char *sfconvert __P((single *, int, int *, int *, char *));
extern char *sgconvert __P((single *, int, int, char *));
extern char *econvert __P((double, int, int *, int *, char *));
extern char *fconvert __P((double, int, int *, int *, char *));
extern char *gconvert __P((double, int, int, char *));
extern char *qeconvert __P((quadruple *, int, int *, int *, char *));
extern char *qfconvert __P((quadruple *, int, int *, int *, char *));
extern char *qgconvert __P((quadruple *, int, int, char *));

extern char *ecvt __P((double, int, int *, int *));
extern char *fcvt __P((double, int, int *, int *));
extern char *gcvt __P((double, int, char *));

/*
 * ANSI C Standard says the following entry points should be
 * prototyped in <stdlib.h>.  They are now, but weren't before.
 */
extern double atof __P((const char *));
extern double strtod __P((const char *, char **));

#undef	_FLOATINGPOINT_FILE

#ifdef __cplusplus
}
#endif

#endif /* _FLOATINGPOINT_H */
