/*
 * Copyright 1999,2002-2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_PROF_ATTR_H
#define	_PROF_ATTR_H

#pragma ident	"@(#)prof_attr.h	1.3	03/02/27 SMI"

#ifdef	__cplusplus
extern "C" {
#endif


#include <sys/types.h>
#include <secdb.h>


#define	PROFATTR_FILENAME		"/etc/security/prof_attr"
#define	PROFATTR_DB_NAME		"prof_attr.org_dir"
#define	PROFATTR_DB_NCOL		5	/* total columns */
#define	PROFATTR_DB_NKEYCOL		1	/* total searchable columns */
#define	PROFATTR_DB_TBLT		"prof_attr_tbl"
#define	PROFATTR_NAME_DEFAULT_KW	"nobody"

#define	PROFATTR_COL0_KW		"name"
#define	PROFATTR_COL1_KW		"res1"
#define	PROFATTR_COL2_KW		"res2"
#define	PROFATTR_COL3_KW		"desc"
#define	PROFATTR_COL4_KW		"attr"

#define	DEF_PROF			"PROFS_GRANTED="

#define	MAXPROFS			4096

/*
 * indices of searchable columns
 */
#define	PROFATTR_KEYCOL0		0	/* name */


/*
 * Key words used in the prof_attr database
 */
#define	PROFATTR_AUTHS_KW		"auths"
#define	PROFATTR_PROFS_KW		"profiles"
#define	PROFATTR_PRIVS_KW		"privs"


/*
 * Nsswitch representation of profile attributes.
 */

typedef struct profstr_s {
	char   *name;	/* proforization name */
	char   *res1;	/* RESERVED */
	char   *res2;	/* RESERVED */
	char   *desc;	/* description */
	char   *attr;	/* string of key-value pair attributes */
} profstr_t;

typedef struct profattr_s {
	char   *name;	/* proforization name */
	char   *res1;	/* RESERVED */
	char   *res2;	/* RESERVED */
	char   *desc;	/* description */
	kva_t  *attr;	/* array of key-value pair attributes */
} profattr_t;

#ifdef    __STDC__
extern profattr_t *getprofnam(const char *);
extern profattr_t *getprofattr(void);
extern void getproflist(const char *, char **, int *);
extern void setprofattr(void);
extern void endprofattr(void);
extern void free_profattr(profattr_t *);
extern void free_proflist(char **, int);

#else				/* not __STDC__ */

extern profattr_t *getprofnam();
extern profattr_t *getprofattr();
extern void getproflist();
extern int setprofattr();
extern int endprofattr();
extern void free_profattr();
extern void free_proflist();

#endif

#ifdef __cplusplus
}
#endif

#endif	/* _PROF_ATTR_H */
