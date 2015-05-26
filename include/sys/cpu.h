/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_CPU_H
#define	_SYS_CPU_H

#pragma ident	"@(#)cpu.h	1.13	08/05/10 SMI"

/*
 * WARNING:
 *	This header file is Obsolete and may be deleted in a
 *	future release of Solaris.
 */

/*
 * Include generic bustype cookies.
 */
#include <sys/bustypes.h>
#if defined(__GNUC__) && defined(_ASM_INLINES) && defined(_KERNEL)
#include <asm/cpu.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(_KERNEL)
extern void ht_pause(void);
extern void cli(void);
extern void sti(void);
extern void i86_halt(void);
extern void i86_monitor(volatile uint32_t *addr, uint32_t extensions,
    uint32_t hints);
extern void i86_mwait(uint32_t data, uint32_t extensions);

/*
 * Used to insert cpu-dependent instructions into spin loops
 */
#define	SMT_PAUSE()		ht_pause()

/*
 * C-state defines for the idle_state_transition DTrace probe
 *
 * The probe fires when the CPU undergoes an idle state change (e.g. C-state)
 * The agument passed is the C-state to which the CPU is transitioning.
 *
 * The states are defined here.
 */
#define	IDLE_STATE_C0 0
#define	IDLE_STATE_C1 1

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_CPU_H */
