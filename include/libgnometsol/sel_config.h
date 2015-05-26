/*
 * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef SEL_CONFIG_H
#define SEL_CONFIG_H

#include <tsol/label.h>

/*
 * The various label combinations
 * Note: The bottom bits specify the il relationship and
 * the top bits specify the sl relationship
 */

typedef enum {
	DGSL = 0,   /* SrcSL > DstSL */
	EQSL = 4,   /* SrcSL = DstSL */
	UGSL = 8,   /* SrcSL < DstSL */
	DJSL = 12,  /* SrcSL # DstSL */
	DGIL = 0,   /* SrcIL > DstIL */
	EQIL = 1,   /* SrcIL = DstIL */
	UGIL = 2,   /* SrcIL < DstIL */
	DJIL = 3    /* SrcIL # DstIL */
} TransferParts;

typedef enum {  
	DGSL_DGIL = DGSL + DGIL,
	DGSL_EQIL = DGSL + EQIL,
	DGSL_UGIL = DGSL + UGIL,
	DGSL_DJIL = DGSL + DJIL,
	EQSL_DGIL = EQSL + DGIL,
	EQSL_EQIL = EQSL + EQIL,
	EQSL_UGIL = EQSL + UGIL,
	EQSL_DJIL = EQSL + DJIL,
	UGSL_DGIL = UGSL + DGIL,
	UGSL_EQIL = UGSL + EQIL,
	UGSL_UGIL = UGSL + UGIL,
	UGSL_DJIL = UGSL + DJIL,
	DJSL_DGIL = DJSL + DGIL,
	DJSL_EQIL = DJSL + EQIL,
	DJSL_UGIL = DJSL + UGIL,
	DJSL_DJIL = DJSL + DJIL
} TransferType;

/*
 * this is the auto confirm structure
 *
 * This structure is loaded from the /etc/gnome/sel_config or
 * /usr/gnome/sel_config file.  It controls the action of the selection
 * manager and the file manager drag and drop confirmer.
 * There is an entry for the 16 possible types of transfer based
 * upon the source label and destination label.
 *
 * For each combination the entry has the following options:
 *
 * do_auto_confirm = true -> confirm transfer without displaying confirmer
 *                           (note: user must still have proper authorizations)
 *                   false -> display confirmer before processing transfer
 * auto_confirm_label = specifies the IL to use if auto_confirm is true.
 *                   's' = use IL of source data (sel_mgr)
 *                         use IL of source file (nautilus)
 *                   'd' = use IL of destination window (sel_mgr)
 *                         use IL of destination directory (nautilus)
 *
 * If ILs are being hidden, it is possible that the IL can be
 * invalid but would not be displayed for the user to correct.
 * The hidden_il_action field specifies the action to be taken
 * in that case.
 *
 * hidden_il_action = See explanation below.
 *                   'c' = show confirmer with ILs displayed
 *                         (nautilus and sel_mgr) - default
 *                   'd' = use IL of destination window (sel_mgr)
 *                         use IL of destination directory (nautilus)
 *                   'l' = set IL to admin_low (sel_mgr and nautilus)
 *
 * When ILs are hidden for a user, it is possible that the IL can be
 * invalid for the destination.  If an auto-confirm is being processed
 * the auto_confirm_label setting will be used if it results in an IL
 * that is valid.  If that is invalid, the hidden_il_label setting will
 * be used.  If it is not an auto-confirm and the IL would be invalid
 * for the destination, the hidden_il_label setting will be used to
 * set the hidden IL.  If the IL is still invalid after the hidden_il_label
 * setting is used, the transfer will not be allowed.
 */

#define TS_IL_FROM_DST  1
#define TS_IL_ADLOW     2
#define TS_IL_CONFIRM   3

typedef struct {
	int do_auto_confirm[16];        /* one for each transfer type */
	int do_auto_cancel[16];     
	int hidden_il_action;           /* see defines above for values */
} AutoConfirm;

#define MAX_AUTO_REPLY          50      /* max no. of auto reply settings */

/*
 * auto reply structure
 */
typedef struct {
	int     enabled;
	int     count;
	char    *selection[MAX_AUTO_REPLY];   /* this is malloced as required */
} AutoReply;

/* Function Prototypes */

extern int tsol_load_sel_config(AutoConfirm *confirm, AutoReply *reply);
extern TransferType tsol_check_transfer_type( bslabel_t *src_sl, 
					      bslabel_t *dst_sl);

#endif 

