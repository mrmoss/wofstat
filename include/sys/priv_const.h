/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Privilege constant definitions; these constants are subject to
 * change, including renumbering, without notice and should not be
 * used in any code.  Privilege names must be used instead.
 * Privileges and privilege sets must not be stored in binary
 * form; privileges and privileges sets must be converted to
 * textual representation before being committed to persistent store.
 *
 * THIS FILE WAS GENERATED; DO NOT EDIT
 */



#ifndef _SYS_PRIV_CONST_H
#define	_SYS_PRIV_CONST_H

#pragma ident	"@(#)priv_defs	1.14	10/03/18 SMI"


#include <sys/types.h>


#ifdef __cplusplus
extern "C" {
#endif

#if defined(_KERNEL) || defined(_KMEMUSER)
#define	PRIV_NSET			  4
#define	PRIV_SETSIZE			  3
#endif

#ifdef _KERNEL
#define	__PRIV_CONST_IMPL

extern const char *priv_names[];
extern const char *priv_setnames[];
extern int nprivs;
extern int privbytes;
extern int maxprivbytes;
extern size_t privinfosize;
extern char *priv_str;
extern struct priv_set *priv_basic;
extern struct priv_impl_info *priv_info;
extern struct priv_info_names *priv_ninfo;

/* Privileges */
#define	PRIV_CONTRACT_EVENT	  0
#define	PRIV_CONTRACT_OBSERVER	  1
#define	PRIV_CPC_CPU		  2
#define	PRIV_DTRACE_KERNEL	  3
#define	PRIV_DTRACE_PROC	  4
#define	PRIV_DTRACE_USER	  5
#define	PRIV_FILE_CHOWN		  6
#define	PRIV_FILE_CHOWN_SELF	  7
#define	PRIV_FILE_DAC_EXECUTE	  8
#define	PRIV_FILE_DAC_READ	  9
#define	PRIV_FILE_DAC_SEARCH	 10
#define	PRIV_FILE_DAC_WRITE	 11
#define	PRIV_FILE_DOWNGRADE_SL	 12
#define	PRIV_FILE_LINK_ANY	 13
#define	PRIV_FILE_OWNER		 14
#define	PRIV_FILE_SETID		 15
#define	PRIV_FILE_UPGRADE_SL	 16
#define	PRIV_GRAPHICS_ACCESS	 17
#define	PRIV_GRAPHICS_MAP	 18
#define	PRIV_IPC_DAC_READ	 19
#define	PRIV_IPC_DAC_WRITE	 20
#define	PRIV_IPC_OWNER		 21
#define	PRIV_NET_BINDMLP	 22
#define	PRIV_NET_ICMPACCESS	 23
#define	PRIV_NET_MAC_AWARE	 24
#define	PRIV_NET_PRIVADDR	 25
#define	PRIV_NET_RAWACCESS	 26
#define	PRIV_PROC_AUDIT		 27
#define	PRIV_PROC_CHROOT	 28
#define	PRIV_PROC_CLOCK_HIGHRES	 29
#define	PRIV_PROC_EXEC		 30
#define	PRIV_PROC_FORK		 31
#define	PRIV_PROC_INFO		 32
#define	PRIV_PROC_LOCK_MEMORY	 33
#define	PRIV_PROC_OWNER		 34
#define	PRIV_PROC_PRIOCNTL	 35
#define	PRIV_PROC_SESSION	 36
#define	PRIV_PROC_SETID		 37
#define	PRIV_PROC_TASKID	 38
#define	PRIV_PROC_ZONE		 39
#define	PRIV_SYS_ACCT		 40
#define	PRIV_SYS_ADMIN		 41
#define	PRIV_SYS_AUDIT		 42
#define	PRIV_SYS_CONFIG		 43
#define	PRIV_SYS_DEVICES	 44
#define	PRIV_SYS_IPC_CONFIG	 45
#define	PRIV_SYS_LINKDIR	 46
#define	PRIV_SYS_MOUNT		 47
#define	PRIV_SYS_IP_CONFIG	 48
#define	PRIV_SYS_NET_CONFIG	 49
#define	PRIV_SYS_NFS		 50
#define	PRIV_SYS_RES_CONFIG	 51
#define	PRIV_SYS_RESOURCE	 52
#define	PRIV_SYS_SUSER_COMPAT	 53
#define	PRIV_SYS_TIME		 54
#define	PRIV_SYS_TRANS_LABEL	 55
#define	PRIV_WIN_COLORMAP	 56
#define	PRIV_WIN_CONFIG		 57
#define	PRIV_WIN_DAC_READ	 58
#define	PRIV_WIN_DAC_WRITE	 59
#define	PRIV_WIN_DEVICES	 60
#define	PRIV_WIN_DGA		 61
#define	PRIV_WIN_DOWNGRADE_SL	 62
#define	PRIV_WIN_FONTPATH	 63
#define	PRIV_WIN_MAC_READ	 64
#define	PRIV_WIN_MAC_WRITE	 65
#define	PRIV_WIN_SELECTION	 66
#define	PRIV_WIN_UPGRADE_SL	 67
#define	PRIV_NET_ACCESS		 68

/* Privilege sets */
#define	PRIV_EFFECTIVE		  0
#define	PRIV_INHERITABLE	  1
#define	PRIV_PERMITTED		  2
#define	PRIV_LIMIT		  3

#define	MAX_PRIVILEGE			 96

#define	PRIV_UNSAFE_ASSERT(set)\
		PRIV_ASSERT((set), PRIV_PROC_AUDIT);\
		PRIV_ASSERT((set), PRIV_PROC_SETID);\
		PRIV_ASSERT((set), PRIV_SYS_RESOURCE)

#define	PRIV_BASIC_ASSERT(set)\
		PRIV_ASSERT((set), PRIV_FILE_LINK_ANY);\
		PRIV_ASSERT((set), PRIV_PROC_EXEC);\
		PRIV_ASSERT((set), PRIV_PROC_FORK);\
		PRIV_ASSERT((set), PRIV_PROC_INFO);\
		PRIV_ASSERT((set), PRIV_PROC_SESSION);\
		PRIV_ASSERT((set), PRIV_NET_ACCESS)

#endif /* _KERNEL */

#ifdef __cplusplus
}
#endif

#endif /* _SYS_PRIV_CONST_H */
