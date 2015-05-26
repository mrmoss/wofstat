/*
 * Copyright 1998-2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_APPTRACE_IMPL_H
#define	_APPTRACE_IMPL_H

#pragma ident	"@(#)apptrace_impl.h	1.4	03/01/03 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct abisym {
	void	*a_real;
	int	a_vflag;
	int	a_tflag;
} abisym_t;

/*
 * From the apptrace auditing object
 */
extern FILE *__abi_outfile;
extern struct liblist *__abi_pflib_list;

extern sigset_t abisigset;

#ifdef	__STDC__

extern void abilock(sigset_t *);
extern void abiunlock(sigset_t *);

extern size_t	strnlen(char const *, size_t);
extern int	is_empty_string(char const *);

extern int (*abi_thr_main)(void);
extern thread_t (*abi_thr_self)(void);
extern int (*abi_sigsetmask)(int, const sigset_t *, sigset_t *);
extern int (*abi_sigaction)(int, const struct sigaction *, struct sigaction *);
extern int (*abi_mutex_lock)(mutex_t *);
extern int (*abi_mutex_unlock)(mutex_t *);

#else	/* __STDC__ */

extern void abilock();
extern void abiunlock();
extern size_t	strnlen();
extern int	is_empty_string();
extern int (*abi_thr_main)();
extern thread_t (*abi_thr_self)();
extern int (*abi_sigsetmask)();
extern int (*abi_sigaction)();
extern int (*abi_mutex_lock)();
extern int (*abi_mutex_unlock)();

#endif	/* __STDC__ */

#ifdef	__cplusplus
}
#endif

#endif	/* _APPTRACE_IMPL_H */
