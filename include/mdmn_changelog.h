/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_MDMN_CHANGELOG_H
#define	_MDMN_CHANGELOG_H

#pragma ident	"@(#)mdmn_changelog.h	1.1	04/07/13 SMI"

#include <sys/lvm/mdmn_commd.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	MD_MN_CHANGELOG_RECORD_REVISION 0x00010000;

/* flags for log record entries */
#define	MD_MN_LR_INUSE  0x00000001U	/* Log entry is in use */

#define	MDMN_CLF_SNARFED	0x1
#define	MDMN_CLF_RESETCACHE	0x2
#define	MDMN_CLF_RESETLOG	0x4
#define	MDMN_CLF_RESETALL	(MDMN_CLF_RESETCACHE | MDMN_CLF_RESETLOG)


/* changelog record entry */
typedef struct mdmn_changelog_record {
	uint_t				lr_revision;
	uint_t				lr_flags;
	mddb_recid_t			lr_selfid;
	md_mn_msgclass_t		lr_class;
	size32_t			lr_msglen;
	md_mn_msg_t			lr_msg;
} mdmn_changelog_record_t;

#define	lr_msgtype	lr_msg.msg_type
#define	lr_msgid	lr_msg.msg_msgid
#define	lr_setno	lr_msg.msg_setno

/* ondisk version */
typedef struct mdmn_changelog_record_od {
	uint_t				lr_revision;
	uint_t				lr_flags;
	mddb_recid_t			lr_selfid;
	md_mn_msgclass_t		lr_class;
	size32_t			lr_msglen;
	int				spare[5];
	md_mn_msg_od_t			lr_od_msg;
} mdmn_changelog_record_od_t;

#define	lr_od_msgtype	lr_od_msg.msg_type
#define	lr_od_msgid	lr_od_msg.msg_msgid
#define	lr_od_setno	lr_od_msg.msg_setno


extern	int	mdmn_allocate_changelog(mdsetname_t *, md_error_t *);
extern	int	mdmn_reset_changelog(mdsetname_t *, md_error_t *, int flags);
extern	int	mdmn_log_msg(md_mn_msg_t *);
extern	int	mdmn_unlog_msg(md_mn_msg_t *);
extern	int	mdmn_snarf_changelog(set_t, md_error_t *);
extern	mdmn_changelog_record_t	*mdmn_get_changelogrec(set_t,
							md_mn_msgclass_t);

#ifdef	__cplusplus
}
#endif

#endif	/* _MDMN_CHANGELOG_H */
