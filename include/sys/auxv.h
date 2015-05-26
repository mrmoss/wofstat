/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * Copyright (c) 1998, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_AUXV_H
#define	_SYS_AUXV_H

#pragma ident	"@(#)auxv.h	1.39	12/02/06 SMI"	/* SVr4.0 1.2	*/

#include <sys/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(_ASM)
typedef struct
{
	int	a_type;
	union {
		long	a_val;
#ifdef __STDC__
		void	*a_ptr;
#else
		char	*a_ptr;
#endif
		void	(*a_fcn)();
	} a_un;
} auxv_t;

#if defined(_SYSCALL32)

typedef struct {
	int32_t	a_type;
	union	{
		int32_t	a_val;
		caddr32_t a_ptr;
		caddr32_t a_fcn;
	} a_un;
} auxv32_t;

#endif	/* _SYSCALL32 */

#endif /* _ASM */

#define	AT_NULL		0
#define	AT_IGNORE	1
#define	AT_EXECFD	2
#define	AT_PHDR		3	/* &phdr[0] */
#define	AT_PHENT	4	/* sizeof(phdr[0]) */
#define	AT_PHNUM	5	/* # phdr entries */
#define	AT_PAGESZ	6	/* getpagesize(2) */
#define	AT_BASE		7	/* ld.so base addr */
#define	AT_FLAGS	8	/* processor flags */
#define	AT_ENTRY	9	/* a.out entry point */

/*
 * These relate to the original PPC ABI document; Linux reused
 * the values for other things (see below), so disambiguation of
 * these values may require additional context in PPC binaries.
 *
 * AT_DCACHEBSIZE	10	smallest data cache block size
 * AT_ICACHEBSIZE	11	smallest instruction cache block size
 * AT_UCACHEBSIZE	12	smallest unified cache block size
 *
 * These are the values from LSB 1.3, the first five are also described
 * in the draft amd64 ABI.
 *
 * AT_CLKTCK is placed on the aux vector for lx branded processes; also, we
 * do similar things via AT_SUN_ values.
 *
 * AT_NOTELF		10	program is not ELF?
 * AT_UID		11	real user id
 * AT_EUID		12	effective user id
 * AT_GID		13	real group id
 * AT_EGID		14	effective group id
 *
 * AT_PLATFORM		15
 * AT_HWCAP		16
 * AT_CLKTCK		17	c.f. _SC_CLK_TCK
 * AT_FPUCW		18
 *
 * AT_DCACHEBSIZE	19	(moved from 10)
 * AT_ICACHEBSIZE	20	(moved from 11)
 * AT_UCACHEBSIZE	21	(moved from 12)
 *
 * AT_IGNOREPPC		22
 */

/*
 * Sun extensions begin here
 */
#define	AT_SUN_UID	2000	/* effective user id */
#define	AT_SUN_RUID	2001	/* real user id */
#define	AT_SUN_GID	2002	/* effective group id */
#define	AT_SUN_RGID	2003	/* real group id */

/*
 * The following attributes are specific to the
 * kernel implementation of the linker/loader.
 */
#define	AT_SUN_LDELF	2004	/* dynamic linker's ELF header */
#define	AT_SUN_LDSHDR	2005	/* dynamic linker's section headers */
#define	AT_SUN_LDNAME	2006	/* name of dynamic linker */
#define	AT_SUN_LPAGESZ	2007	/* large pagesize */
/*
 * The following aux vector provides a null-terminated platform
 * identification string. This information is the same as provided
 * by sysinfo(2) when invoked with the command SI_PLATFORM.
 */
#define	AT_SUN_PLATFORM	2008	/* platform name */

/*
 * These attributes communicate performance -hints- about processor
 * hardware capabilities that might be useful to library implementations.
 */
#define	AT_SUN_CAP_HW1	2009

#define	AT_SUN_HWCAP	AT_SUN_CAP_HW1 /* deprecated; for backward compat */

#if defined(_KERNEL)
/*
 * User info regarding machine attributes, respectively reported to native and
 * non-native user apps.
 */
extern uint_t auxv_cap_hw[];
#if defined(_SYSCALL32)
extern uint_t auxv_cap32_hw[];
#endif /* _SYSCALL32 */
#else
extern uint_t getisax(uint32_t *, uint_t);
#endif	/* _KERNEL */

#define	AT_SUN_IFLUSH	2010	/* flush icache? */
#define	AT_SUN_CPU	2011	/* cpu name */

/*
 * The following aux vector provides a pointer to a null-terminated
 * path name, a copy of the path name passed to the exec() system
 * call but that has had all symlinks resolved (see resolvepath(2)).
 */
#define	AT_SUN_EXECNAME	2014	/* exec() path name */

#define	AT_SUN_MMU	2015	/* mmu module name */
#define	AT_SUN_LDDATA	2016	/* dynamic linkers data segment */

#define	AT_SUN_AUXFLAGS	2017	/* AF_SUN_ flags passed from the kernel */

/*
 * Used to indicate to the runtime linker the name of the emulation binary,
 * if one is being used. For brands, this is the name of the brand library.
 */
#define	AT_SUN_EMULATOR		2018

#define	AT_SUN_BRANDNAME	2019

/*
 * Aux vectors available for brand modules.
 */
#define	AT_SUN_BRAND_AUX1	2020
#define	AT_SUN_BRAND_AUX2	2021
#define	AT_SUN_BRAND_AUX3	2022

#define	AT_SUN_CAP_HW2		2023

/* Number of hw capability entries in the aux vector */
#define	AT_SUN_CAP_HW_MAX	2

/* Used for indexing entries in auxv_cap_hw and corresponding arrays */
#define	AV_HW1_IDX	0
#define	AV_HW2_IDX	1

/*
 * The kernel is in a better position to determine whether a process needs to
 * ignore dangerous LD environment variables.  If set, this flags tells
 * ld.so.1 to run "secure" and ignore the the environment.
 */
#define	AF_SUN_SETUGID		0x00000001

/*
 * If set, this flag indicates that hardware capabilites can be verified
 * against the AT_SUN_CAP_HW* values.
 */
#define	AF_SUN_HWCAPVERIFY	0x00000002

/*
 * If set, this flag indicates that the the linker should not initialize
 * any of its link maps as primary link wrt the unified libc threading
 * interfaces.
 */
#define	AF_SUN_NOPLM		0x00000004

#ifdef	__cplusplus
}
#endif

#if defined(_AUXV_TARGET_ALL) || defined(_AUXV_TARGET_SPARC) || defined(__sparc)
#include <sys/auxv_SPARC.h>
#endif

#if defined(_AUXV_TARGET_ALL) || defined(_AUXV_TARGET_386) || defined(__x86)
#include <sys/auxv_386.h>
#endif

#endif	/* _SYS_AUXV_H */
