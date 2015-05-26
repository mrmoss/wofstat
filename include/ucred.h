/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_UCRED_H_
#define	_UCRED_H_

#pragma ident	"@(#)ucred.h	1.5	06/05/03 SMI"

#include <sys/types.h>
#include <sys/priv.h>
#include <sys/tsol/label.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct ucred_s ucred_t;

/*
 * library functions prototype.
 */
#if	defined(__STDC__)

extern ucred_t *ucred_get(pid_t pid);

extern void ucred_free(ucred_t *);

extern uid_t ucred_geteuid(const ucred_t *);
extern uid_t ucred_getruid(const ucred_t *);
extern uid_t ucred_getsuid(const ucred_t *);
extern gid_t ucred_getegid(const ucred_t *);
extern gid_t ucred_getrgid(const ucred_t *);
extern gid_t ucred_getsgid(const ucred_t *);
extern int   ucred_getgroups(const ucred_t *, const gid_t **);

extern const priv_set_t *ucred_getprivset(const ucred_t *, priv_ptype_t);
extern uint_t ucred_getpflags(const ucred_t *, uint_t);

extern pid_t ucred_getpid(const ucred_t *); /* for door_cred compatibility */

extern size_t ucred_size(void);

extern int getpeerucred(int, ucred_t **);

extern zoneid_t ucred_getzoneid(const ucred_t *);

extern bslabel_t *ucred_getlabel(const ucred_t *);

extern projid_t ucred_getprojid(const ucred_t *);

#else	/* Non ANSI */

extern ucred_t *ucred_get(/* pid_t pid */);

extern void ucred_free(/* ucred_t * */);

extern uid_t ucred_geteuid(/* ucred_t * */);
extern uid_t ucred_getruid(/* ucred_t * */);
extern uid_t ucred_getsuid(/* ucred_t * */);
extern gid_t ucred_getegid(/* ucred_t * */);
extern gid_t ucred_getrgid(/* ucred_t * */);
extern gid_t ucred_getsgid(/* ucred_t * */);
extern int   ucred_getgroups(/* ucred_t *, gid_t ** */);

extern priv_set_t *ucred_getprivset(/* ucred_t *, priv_ptype_t */);
extern uint_t ucred_getpflags(/* ucred_t *, uint_t */);

extern pid_t ucred_getpid(/* ucred_t * */);

extern size_t ucred_size(/* void */);

extern int getpeerucred(/* int, ucred_t ** */);

extern zoneid_t ucred_getzoneid(/* ucred_t * */);

extern bslabel_t *ucred_getlabel(/* const ucred_t * */);

extern projid_t ucred_getprojid(/* ucred_t * */);

#endif	/* __STDC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _UCRED_H_ */
