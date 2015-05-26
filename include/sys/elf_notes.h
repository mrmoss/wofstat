/*
 * Copyright (c) 1993, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_ELF_NOTES_H
#define	_SYS_ELF_NOTES_H

#pragma ident	"@(#)elf_notes.h	1.5	11/01/11 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Sun defined names for elf note sections.
 */
#define	ELF_NOTE_SOLARIS		"SUNW Solaris"

/*
 * Describes the desired pagesize of elf PT_LOAD segments.
 * Descriptor is 1 word in length, and contains the desired pagesize.
 */
#define	ELF_NOTE_PAGESIZE_HINT		1

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_ELF_NOTES_H */
