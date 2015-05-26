/*
 * Copyright (c) 2008, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_FMD_AGENT_H
#define	_FMD_AGENT_H

#pragma ident	"@(#)fmd_agent.h	1.2	11/01/10 SMI"

#include <inttypes.h>
#include <libnvpair.h>
#include <umem.h>
#include <sys/types.h>
#include <sys/processor.h>


#ifdef	__cplusplus
extern "C" {
#endif

/*
 * libfmd_agent Interfaces
 *
 * Note: The contents of this file are private to the implementation of the
 * Solaris system and FMD subsystem and are subject to change at any time
 * without notice.  Applications and drivers using these interfaces will fail
 * to run on future releases.  These interfaces should not be used for any
 * purpose until they are publicly documented for use outside of Sun.
 */

#define	FMD_AGENT_VERSION		1

#define	FMD_AGENT_RETIRE_DONE		0	/* synchronous success */
#define	FMD_AGENT_RETIRE_ASYNC		1	/* asynchronous complete */
#define	FMD_AGENT_RETIRE_FAIL		2	/* failure */

typedef struct fmd_agent_hdl fmd_agent_hdl_t;

extern fmd_agent_hdl_t *fmd_agent_open(int);
extern void fmd_agent_close(fmd_agent_hdl_t *);
extern int fmd_agent_errno(fmd_agent_hdl_t *);
extern const char *fmd_agent_errmsg(fmd_agent_hdl_t *);
extern const char *fmd_agent_strerr(int);

extern int fmd_agent_page_retire(fmd_agent_hdl_t *, nvlist_t *);
extern int fmd_agent_page_unretire(fmd_agent_hdl_t *, nvlist_t *);
extern int fmd_agent_page_isretired(fmd_agent_hdl_t *, nvlist_t *);

#ifdef __x86
extern int fmd_agent_physcpu_info(fmd_agent_hdl_t *, nvlist_t ***cpusp,
    uint_t *ncpu);
extern int fmd_agent_cpu_retire(fmd_agent_hdl_t *, int, int, int);
extern int fmd_agent_cpu_unretire(fmd_agent_hdl_t *, int, int, int);
extern int fmd_agent_cpu_isretired(fmd_agent_hdl_t *, int, int, int);
#endif /* __x86 */

#ifdef __sparc
extern int fmd_agent_cache_retire(fmd_agent_hdl_t *, uint32_t, nvlist_t *);
extern int fmd_agent_cache_unretire(fmd_agent_hdl_t *, uint32_t,
    nvlist_t *);
extern int fmd_agent_cache_isretired(fmd_agent_hdl_t *, uint32_t,
    nvlist_t *);
#endif /* __sparc */

#ifdef	__cplusplus
}
#endif

#endif	/* _FMD_AGENT_H */
