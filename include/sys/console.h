/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_CONSOLE_H
#define	_SYS_CONSOLE_H

#pragma ident	"@(#)console.h	1.24	07/02/01 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Sun private interface for cn driver
 */
#define	_CNIOC		(('C'<<24)|('N'<<16))
#define	_CNIOC_MASK	(~0xffff)
#define	CONS_GETTERM	(_CNIOC | 0)

#define	MAX_TERM_TYPE_LEN	10

struct cons_getterm {
	uint_t	cn_term_len;
	char	*cn_term_type;
};

#ifdef _KERNEL

#include <sys/vnode.h>
#include <sys/taskq.h>
#include <sys/varargs.h>

#ifdef _SYSCALL32
struct cons_getterm32 {
	uint32_t  cn_term_len;
	caddr32_t cn_term_type;
};
#endif /* _SYSCALL32 */
extern void console_get_size(ushort_t *r, ushort_t *c,
	ushort_t *x, ushort_t *y);
/*PRINTFLIKE1*/
extern void console_printf(const char *, ...) __KPRINTFLIKE(1);
extern void console_vprintf(const char *, va_list) __KVPRINTFLIKE(1);

extern void console_puts(const char *, size_t);

extern void console_gets(char *, size_t);
extern int console_getc(void);

extern int console_enter(int);
extern void console_exit(int, int);

extern vnode_t *console_vnode;
extern taskq_t *console_taskq;

/*
 * PROM interface callback routine
 */
#ifdef _HAVE_TEM_FIRMWARE
#include <sys/promif.h>
extern ssize_t console_prom_write_cb(promif_redir_arg_t, uchar_t *, size_t);
#endif /* _HAVE_TEM_FIRMWARE */

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_CONSOLE_H */
