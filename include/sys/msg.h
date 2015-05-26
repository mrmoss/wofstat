/*
 * Copyright 1999-2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef _SYS_MSG_H
#define	_SYS_MSG_H

#pragma ident	"@(#)msg.h	1.34	03/02/05 SMI"

#include <sys/ipc.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * IPC Message Facility.
 */

/*
 * Implementation Constants.
 */

/*
 * Permission Definitions.
 */
#define	MSG_R	0400	/* read permission */
#define	MSG_W	0200	/* write permission */

/*
 * ipc_perm Mode Definitions.
 */
#define	MSG_RWAIT	01000	/* a reader is waiting for a message */
#define	MSG_WWAIT	02000	/* a writer is waiting to send */

/*
 * Message Operation Flags.
 */
#define	MSG_NOERROR	010000	/* no error if big message */

typedef unsigned long msgqnum_t;
typedef unsigned long msglen_t;

struct msg;
struct msqid_ds {
	struct ipc_perm	msg_perm;	/* operation permission struct */
	struct msg	*msg_first;	/* ptr to first message on q */
	struct msg	*msg_last;	/* ptr to last message on q */
	msglen_t	msg_cbytes;	/* current # bytes on q */
	msgqnum_t	msg_qnum;	/* # of messages on q */
	msglen_t	msg_qbytes;	/* max # of bytes on q */
	pid_t		msg_lspid;	/* pid of last msgsnd */
	pid_t		msg_lrpid;	/* pid of last msgrcv */
#if defined(_LP64)
	time_t		msg_stime;	/* last msgsnd time */
	time_t		msg_rtime;	/* last msgrcv time */
	time_t		msg_ctime;	/* last change time */
#else
	time_t		msg_stime;	/* last msgsnd time */
	int32_t		msg_pad1;	/* reserved for time_t expansion */
	time_t		msg_rtime;	/* last msgrcv time */
	int32_t		msg_pad2;	/* time_t expansion */
	time_t		msg_ctime;	/* last change time */
	int32_t		msg_pad3;	/* time_t expansion */
#endif
	short		msg_cv;
	short		msg_qnum_cv;
	long		msg_pad4[3];	/* reserve area */
};

/*
 * User message buffer template for msgsnd and msgrecv system calls.
 */

#ifdef _KERNEL
struct ipcmsgbuf {
#else
struct msgbuf {
#endif /* _KERNEL */
#if defined(_XOPEN_SOURCE)
	long	_mtype;		/* message type */
	char	_mtext[1];	/* message text */
#else
	long	mtype;		/* message type */
	char	mtext[1];	/* message text */
#endif
};

/*
 * Header and message header structures for msgsnap() system call.
 */
struct msgsnap_head {
	size_t	msgsnap_size;	/* bytes consumed/required in the buffer */
	size_t	msgsnap_nmsg;	/* number of messages in the buffer */
};

struct msgsnap_mhead {
	size_t	msgsnap_mlen;	/* number of bytes in message that follows */
	long	msgsnap_mtype;	/* message type */
};

#if !defined(_KERNEL)
#if defined(__STDC__)
int msgctl(int, int, struct msqid_ds *);
int msgget(key_t, int);
int msgids(int *, uint_t, uint_t *);
int msgsnap(int, void *, size_t, long);
ssize_t msgrcv(int, void *, size_t, long, int);
int msgsnd(int, const void *, size_t, int);
#else /* __STDC__ */
int msgctl();
int msgget();
int msgids();
int msgsnap();
int msgrcv();
int msgsnd();
#endif /* __STDC__ */
#endif /* ! _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_MSG_H */
