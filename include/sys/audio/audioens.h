/*
 * Copyright 2001, 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_AUDIOENS_H
#define	_SYS_AUDIOENS_H

#pragma ident	"@(#)audioens.h	1.2	03/02/07 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Header file for the audioens device driver.
 */

/*
 * Values returned by the AUDIO_GETDEV ioctl()
 */
#define	ENS_DEV_NAME		"SUNW,audioens"
#define	ENS_DEV_CONFIG		"PCI bus card"
#define	ENS_DEV_VERSION_1370	"1370"
#define	ENS_DEV_VERSION_1371	"1371"
#define	ENS_DEV_VERSION_1373	"1373"
#define	ENS_DEV_VERSION_5880	"5880"

/*
 * Driver supported configuration information
 */
#define	ENS_NAME		"audioens"
#define	ENS_MOD_NAME		"mixer audio driver"

#define	ENS_SAMPR4000		(4000)
#define	ENS_SAMPR5510		(5510)
#define	ENS_SAMPR6620		(6620)
#define	ENS_SAMPR8000		(8000)
#define	ENS_SAMPR9600		(9600)
#define	ENS_SAMPR11025		(11025)
#define	ENS_SAMPR16000		(16000)
#define	ENS_SAMPR18900		(18900)
#define	ENS_SAMPR22050		(22050)
#define	ENS_SAMPR27420		(27420)
#define	ENS_SAMPR32000		(32000)
#define	ENS_SAMPR33075		(33075)
#define	ENS_SAMPR37800		(37800)
#define	ENS_SAMPR44100		(44100)
#define	ENS_SAMPR48000		(48000)

#define	ENS_DEFAULT_SR		ENS_SAMPR8000
#define	ENS_DEFAULT_CH		AUDIO_CHANNELS_MONO
#define	ENS_DEFAULT_PREC	AUDIO_PRECISION_8
#define	ENS_DEFAULT_ENC		AUDIO_ENCODING_ULAW
#define	ENS_DEFAULT_PGAIN	(AUDIO_MAX_GAIN * 3 / 4)
#define	ENS_DEFAULT_RGAIN	(127)
#define	ENS_DEFAULT_MONITOR_GAIN (0)
#define	ENS_DEFAULT_BAL		AUDIO_MID_BALANCE /* MUST be mid */
#define	ENS_INTS		(50)		/* default interrupt rate */
#define	ENS_MIN_INTS		(25)		/* minimum interrupt rate */
#define	ENS_MAX_INTS		(250)		/* maximum interrupt rate */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_AUDIOENS_H */
