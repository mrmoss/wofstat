/*
 * Copyright (c) 1996, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_AIOCB_H
#define	_SYS_AIOCB_H

#pragma ident	"@(#)aiocb.h	1.13	11/11/17 SMI"

#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/siginfo.h>
#include <sys/aio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct aiocb {
	int 		aio_fildes;
#if	defined(__STDC__)
	volatile void	*aio_buf;		/* buffer location */
#else
	void		*aio_buf;		/* buffer location */
#endif
	size_t 		aio_nbytes;		/* length of transfer */
	off_t 		aio_offset;		/* file offset */
	int		aio_reqprio;		/* request priority offset */
	struct sigevent	aio_sigevent;		/* signal number and offset */
	int 		aio_lio_opcode;		/* listio operation */
	aio_result_t	aio_resultp;		/* results */
	char		aio_state;		/* state flag for List I/O */
	char		aio_returned;		/* aio_return() was called */
	char		aio__pad1[2];		/* extension padding */
	int		aio__pad2[1];
} aiocb_t;

#ifdef _LARGEFILE64_SOURCE
#if	!defined(_KERNEL)
typedef struct aiocb64 {
	int 		aio_fildes;
#if	defined(__STDC__)
	volatile void	*aio_buf;		/* buffer location */
#else
	void		*aio_buf;		/* buffer location */
#endif
	size_t 		aio_nbytes;		/* length of transfer */
	off64_t		aio_offset;		/* file offset */
	int		aio_reqprio;		/* request priority offset */
	struct sigevent	aio_sigevent;		/* signal number and offset */
	int 		aio_lio_opcode;		/* listio operation */
	aio_result_t	aio_resultp;		/* results */
	char 		aio_state;		/* state flag for List I/O */
	char		aio_returned;		/* aio_return() was called */
	char		aio__pad1[2];		/* extension padding */
	int		aio__pad2[1];
} aiocb64_t;
#else

#if _LONG_LONG_ALIGNMENT == 8 && _LONG_LONG_ALIGNMENT_32 == 4
#pragma pack(4)
#endif

typedef struct aiocb64_32 {
	int 		aio_fildes;
	caddr32_t	aio_buf;		/* buffer location */
	uint32_t 	aio_nbytes;		/* length of transfer */
	off64_t 	aio_offset;		/* file offset */
	int		aio_reqprio;		/* request priority offset */
	struct sigevent32 aio_sigevent;		/* signal number and offset */
	int 		aio_lio_opcode;		/* listio operation */
	aio_result32_t	aio_resultp;		/* results */
	char 		aio_state;		/* state flag for List I/O */
	char		aio_returned;		/* aio_return() was called */
	char		aio__pad1[2];		/* extension padding */
	int		aio__pad2[1];
} aiocb64_32_t;

#if _LONG_LONG_ALIGNMENT == 8 && _LONG_LONG_ALIGNMENT_32 == 4
#pragma pack()
#endif

#endif /* !defined(_KERNEL) */
#endif /* _LARGEFILE64_SOURCE */

#ifdef	_SYSCALL32
typedef struct aiocb32 {
	int 		aio_fildes;
	caddr32_t	aio_buf;		/* buffer location */
	uint32_t	aio_nbytes;		/* length of transfer */
	uint32_t	aio_offset;		/* file offset */
	int		aio_reqprio;		/* request priority offset */
	struct sigevent32 aio_sigevent;		/* signal number and offset */
	int 		aio_lio_opcode;		/* listio operation */
	aio_result32_t	aio_resultp;		/* results */
	char 		aio_state;		/* state flag for List I/O */
	char		aio_returned;		/* aio_return() was called */
	char		aio__pad1[2];		/* extension padding */
	int		aio__pad2[1];
} aiocb32_t;

#endif /* _SYSCALL32 */
/*
 * return values for aiocancel()
 */
#define	AIO_CANCELED	0
#define	AIO_ALLDONE	1
#define	AIO_NOTCANCELED	2

/*
 * mode values for lio_listio()
 */
#define	LIO_NOWAIT	0
#define	LIO_WAIT	1


/*
 * listio operation codes
 *
 * LIO_READ and LIO_WRITE were previously defined as FREAD and FWRITE as
 * defined in <sys/file.h>.  However, inclusion of <sys/file.h> results
 * in X/Open namespace pollution and as such is no longer included in
 * this header.  The values of LIO_READ and LIO_WRITE must be identical
 * to the values of FREAD and FWRITE in <sys/file.h>.  Any change to one
 * will require a change to the other.
 */

#define	LIO_NOP		0
#define	LIO_READ	0x01	/* Must match value of FREAD in sys/file.h */
#define	LIO_WRITE	0x02	/* Must match value of FWRITE in sys/file.h */

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_AIOCB_H */
