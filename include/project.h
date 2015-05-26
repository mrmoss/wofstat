/*
 * Copyright (c) 1999-2001 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef _PROJECT_H
#define	_PROJECT_H

#pragma ident	"@(#)project.h	1.3	01/09/14 SMI"

#include <stdio.h>
#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	PROJF_PATH	"/etc/project"	/* pathname of the "project" file */
#define	PROJNAME_MAX	64		/* maximum project name size */
#define	PROJECT_BUFSZ	4096		/* default buffer size */

#define	SETPROJ_ERR_TASK	(-1)	/* error creating new task */
#define	SETPROJ_ERR_POOL	(-2)	/* error binding to pool */

struct project {
	char	*pj_name;	/* name of the project */
	projid_t pj_projid;	/* numerical project id */
	char	*pj_comment;	/* project description */
	char	**pj_users;	/* vector of pointers to project user names */
	char	**pj_groups;	/* vector of pointers to project group names */
	char	*pj_attr;	/* project attributes string */
};

extern void setprojent(void);
extern void endprojent(void);
extern struct project *getprojent(struct project *, void *, size_t);
extern struct project *getprojbyname(const char *,
    struct project *, void *, size_t);
extern struct project *getprojbyid(projid_t, struct project *, void *, size_t);
extern struct project *getdefaultproj(const char *,
    struct project *, void *, size_t);
extern struct project *fgetprojent(FILE *, struct project *, void *, size_t);
extern int inproj(const char *, const char *, void *, size_t);
extern projid_t getprojidbyname(const char *);

extern projid_t getprojid(void);

extern projid_t setproject(const char *, const char *, int);
extern int project_walk(int (*)(projid_t, void *), void *);

#ifdef	__cplusplus
}
#endif

#endif /* _PROJECT_H */
