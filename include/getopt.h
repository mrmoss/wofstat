/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
 * GNU-like getopt_long(), getopt_long_only().
 * Solaris-specific getopt_clip().
 */

#ifndef	_GETOPT_H
#define	_GETOPT_H

#pragma ident	"@(#)getopt.h	1.1	04/03/29 SMI"

#ifdef	__cplusplus
extern "C" {
#endif


/*
 * Values for has_arg field.
 *
 * optional_argument is not supported by getopt_clip()
 */
#define	no_argument		0
#define	required_argument	1
#define	optional_argument	2

struct option {
	char *name;	/* name of long option */
	int has_arg;	/* whether option takes an argument */
	int *flag;	/* if not NULL, set *flag to val when option found */
	int val;	/* if flag is not NULL, value to set *flag to. */
			/* if flag is NULL, return value */
};

/*
 * External variables used by these routines.
 */
extern char *optarg;
extern int  opterr;
extern int  optind;
extern int  optopt;

/*
 * The use of getopt_long_only in new development is strongly discouraged.
 */
#ifdef __STDC__
extern int	getopt_long(int, char * const *, const char *,
		    const struct option *, int *);
extern int	getopt_long_only(int, char * const *, const char *,
		    const struct option *, int *);
extern int	getopt_clip(int, char * const *, const char *,
		    const struct option *, int *);
#else   /* __STDC__ */
extern int	getopt_long();
extern int	getopt_long_only();
extern int	getopt_clip();
#endif  /* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif	/* _GETOPT_H */
