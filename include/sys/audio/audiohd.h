/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_AUDIOHD_H_
#define	_SYS_AUDIOHD_H_

#pragma ident	"@(#)audiohd.h	1.2	06/09/09 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/thread.h>
#include <sys/synch.h>
#include <sys/kstat.h>
#include <sys/ddi.h>
#include <sys/sunddi.h>
#include <sys/audio.h>
#include <sys/audio/audio_support.h>
#include <sys/mixer.h>
#include <sys/audio/audio_mixer.h>


#define	AUDIOHD_SAMPR5510		5510
#define	AUDIOHD_SAMPR6620		6620
#define	AUDIOHD_SAMPR8000		8000
#define	AUDIOHD_SAMPR9600		9600
#define	AUDIOHD_SAMPR11025		11025
#define	AUDIOHD_SAMPR16000		16000
#define	AUDIOHD_SAMPR18900		18900
#define	AUDIOHD_SAMPR22050		22050
#define	AUDIOHD_SAMPR27420		27420
#define	AUDIOHD_SAMPR32000		32000
#define	AUDIOHD_SAMPR33075		33075
#define	AUDIOHD_SAMPR37800		37800
#define	AUDIOHD_SAMPR44100		44100
#define	AUDIOHD_SAMPR48000		48000

#define	AUDIOHD_SAMPLER_MAX	AUDIOHD_SAMPR48000
#define	AUDIOHD_MIN_INTS	32
#define	AUDIOHD_MAX_INTS	1500
#define	AUDIOHD_INTS	50
#define	AUDIOHD_MAX_PRECISION	AUDIO_PRECISION_16
#define	AUDIOHD_MAX_CHANNELS	AUDIO_CHANNELS_STEREO
#define	AUDIOHD_MAX_OUT_CHANNELS	32
#define	AUDIOHD_MAX_IN_CHANNELS		AUDIOHD_MAX_OUT_CHANNELS

#define	AUDIOHD_BSIZE		8192
#define	AUDIOHD_DEFAULT_SR	8000
#define	AUDIOHD_DEFAULT_CH	AUDIO_CHANNELS_MONO
#define	AUDIOHD_DEFAULT_PREC	AUDIO_PRECISION_8
#define	AUDIOHD_DEFAULT_ENC		AUDIO_ENCODING_ULAW
#define	AUDIOHD_DEFAULT_PGAIN	(AUDIO_MAX_GAIN * 3 / 4)
#define	AUDIOHD_DEFAULT_RGAIN	127
#define	AUDIOHD_DEFAULT_BAL			AUDIO_MID_BALANCE
#define	AUDIOHD_DEFAULT_MONITOR_GAIN		0

#define	AUDIOHD_DEV_NAME	"audiohd"
#define	AUDIOHD_DEV_CONFIG	"hda audio config"
#define	AUDIOHD_DEV_VERSION	"a"

#ifdef __cplusplus
}
#endif

#endif	/* _SYS_AUDIOHD_H_ */
