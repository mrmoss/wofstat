/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_FRAME_H
#define	_SYS_FRAME_H

#pragma ident	"@(#)frame.h	1.7	04/09/28 SMI"

#include <sys/regset.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * In the Intel world, a stack frame looks like this:
 *
 * %fp0->|				 |
 *	 |-------------------------------|
 *	 |  Args to next subroutine	 |
 *	 |-------------------------------|-\
 * %sp0->|  One word struct-ret address	 | |
 *	 |-------------------------------|  > minimum stack frame
 * %fp1->|  Previous frame pointer (%fp0)| |
 *	 |-------------------------------|-/
 *	 |  Local variables		 |
 * %sp1->|-------------------------------|
 *
 * For amd64, the minimum stack frame is 16 bytes and the frame pointer must
 * be 16-byte aligned.
 */

struct frame {
	greg_t	fr_savfp;		/* saved frame pointer */
	greg_t	fr_savpc;		/* saved program counter */
};

#ifdef _SYSCALL32

/*
 * Kernel's view of a 32-bit stack frame.
 */
struct frame32 {
	greg32_t fr_savfp;		/* saved frame pointer */
	greg32_t fr_savpc;		/* saved program counter */
};

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_FRAME_H */
