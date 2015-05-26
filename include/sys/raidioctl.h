/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_RAIDIOCTL_H
#define	_SYS_RAIDIOCTL_H

#pragma ident	"@(#)raidioctl.h	1.3	06/01/03 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * map ioctls
 */
#define	RAID_IOC (('R' << 16) | ('D' << 8))
#define	RAID_GETCONFIG		(RAID_IOC|1)	/* Get raid information */
#define	RAID_CREATE		(RAID_IOC|2)	/* Create raid mirror */
#define	RAID_DELETE		(RAID_IOC|3)	/* Delete raid mirror */
#define	RAID_UPDATEFW		(RAID_IOC|4)	/* Update IOC firmware */
#define	RAID_GETDEVID		(RAID_IOC|5)	/* Retrieve devid of chip */
#define	RAID_NUMVOLUMES		(RAID_IOC|6)	/* Retrieve max RAID volumes */

/*
 * define raid status flags
 */
#define	RAID_FLAG_ENABLED				0x01
#define	RAID_FLAG_QUIESCED				0x02
#define	RAID_FLAG_RESYNCING				0x04
#define	RAID_STATE_OPTIMAL				0x00
#define	RAID_STATE_DEGRADED				0x01
#define	RAID_STATE_FAILED				0x02

/*
 * define disk status flags
 */
#define	RAID_DISKSTATUS_GOOD				0x0
#define	RAID_DISKSTATUS_FAILED				0x1
#define	RAID_DISKSTATUS_MISSING				0x2

/*
 * maximum number of disks allowed in a raid volume
 */
#define	RAID_MAXDISKS					32

typedef struct raid_config {
	int targetid;
	uint8_t	state;
	uint8_t	flags;
	int raid_level;
	int ndisks;
	int disk[RAID_MAXDISKS];
	int diskstatus[RAID_MAXDISKS];
	diskaddr_t raid_capacity;
	int unitid;
} raid_config_t;

/*
 * Defines for type
 */
#define	FW_TYPE_UCODE			0x1;
#define	FW_TYPE_FCODE			0x2;

typedef struct update_flash {
	caddr_t ptrbuffer;
	uint_t size;
	uint8_t type;
} update_flash_t;

#if defined(_SYSCALL32)
typedef struct update_flash_32 {
	caddr32_t ptrbuffer;
	uint32_t size;
	uint8_t type;
} update_flash_32_t;
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_RAIDIOCTL_H */
