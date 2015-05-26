/*
 * Copyright (c) 2010, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_DDI_HP_IMPL_H
#define	_SYS_DDI_HP_IMPL_H

#pragma ident	"@(#)ddi_hp_impl.h	1.3	12/06/26 SMI"

/*
 * Sun DDI hotplug implementation specific definitions
 */

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef _KERNEL

/* Flags for sync request and async hotplug request */
#define	DDI_HP_REQ_SYNC 0x0001
#define	DDI_HP_REQ_ASYNC 0x0002

/* Check if a handle represents a port or a connector */
#define	DDI_HP_IS_VIRTUAL_PORT(hdlp)		\
	!(hdlp->cn_info.cn_type & DDI_HP_CN_TYPE_CONNECTOR_MASK)

/*
 * ddi_hp_cn_handle_t
 *
 * DDI handle for a registered Hotplug Connection (CN)
 */
typedef struct ddi_hp_cn_handle {
	dev_info_t		*cn_dip; /* The dip that the handle is linked */
	ddi_hp_cn_info_t	cn_info; /* Connection info */
	struct ddi_hp_cn_handle	*next;	 /* Next Connector/Port. */
} ddi_hp_cn_handle_t;

typedef struct ddi_hp_cn_change_state_arg
{
	ddi_hp_cn_state_t	target_state;
	int			type;
} ddi_hp_cn_change_state_arg_t;

typedef enum {
	ARG_PRIV_KERNEL_SYNC,
	ARG_PRIV_KERNEL_ASYNC
} changestate_arg_type_t;

typedef struct ddi_hp_cn_async_event_entry {
	dev_info_t			*dip;
	char				*cn_name;
	ddi_hp_cn_change_state_arg_t	karg;
} ddi_hp_cn_async_event_entry_t;

/*
 * ddi_hp_op_t
 *
 * Typedef for Hotplug OPS commands used with bus_hp_op()
 */
typedef enum {
	DDI_HPOP_CN_GET_STATE = 1,	/* Get Connection state */
	DDI_HPOP_CN_CHANGE_STATE,	/* Change Connection state */
	DDI_HPOP_CN_SET_STATE_CEILING,	/* Set state-ceiling */
	DDI_HPOP_CN_CLEAR_STATE_CEILING, /* Clear state-ceiling */
	DDI_HPOP_CN_PROBE,		/* Probe Connection */
	DDI_HPOP_CN_UNPROBE,		/* Unprobe Connection */
	DDI_HPOP_CN_GET_PROPERTY,	/* Get bus specific property */
	DDI_HPOP_CN_SET_PROPERTY,	/* Set bus specific property */
	DDI_HPOP_CN_CREATE_PORT,	/* Create a port for virtual hotplug */
	DDI_HPOP_CN_REMOVE_PORT		/* Remove an empty port */
} ddi_hp_op_t;

#define	DDIHP_CN_OPS(hdlp, op, arg, result, ret)		\
	if (DDI_HP_IS_VIRTUAL_PORT(hdlp))			\
		ret = ddihp_port_ops(hdlp, op, arg, result);	\
	else							\
		ret = ddihp_connector_ops(hdlp, op, arg, result);

#define	NEXUS_HAS_HP_OP(dip)						\
	((DEVI(dip)->devi_ops->devo_bus_ops) &&				\
	(DEVI(dip)->devi_ops->devo_bus_ops->busops_rev >= BUSO_REV_10) && \
	(DEVI(dip)->devi_ops->devo_bus_ops->bus_hp_op))

/*
 * ddi_hp_cn_sysevent_t
 *
 * The following correspond to sysevent defined subclasses
 */
typedef enum {
	DDI_HP_CN_STATE_CHANGE,
	DDI_HP_CN_REQ
} ddi_hp_cn_sysevent_t;

/*
 * Misc
 */

/* Append a node to list */
#define	DDIHP_LIST_APPEND(type, head, node)				\
if (node) {								\
	type *curr, *prev = NULL;					\
	(node)->next = NULL;						\
	for (curr = (head); curr; prev = curr, curr = curr->next);	\
	if (prev == NULL)						\
		(head) = (node);					\
	else								\
		prev->next = (node);					\
}

/* Remove a node from a list */
#define	DDIHP_LIST_REMOVE(type, head, node)				\
if (node) {								\
	type *curr, *prev = NULL;					\
	for (curr = (head); curr; prev = curr, curr = curr->next) {	\
		if (curr == (node))					\
			break;						\
	}								\
    if (curr) {								\
	if (prev == NULL)						\
		(head) = (head)->next;					\
	else								\
		prev->next = curr->next;				\
	}								\
}

int ddihp_modctl(int hp_op, char *path, char *cn_name, uintptr_t arg,
    uintptr_t rval);
ddi_hp_cn_handle_t *ddihp_cn_name_to_handle(dev_info_t *dip, char *cn_name);
int ddihp_cn_getstate(ddi_hp_cn_handle_t *hdlp);
int ddihp_port_ops(ddi_hp_cn_handle_t *hdlp, ddi_hp_op_t op,
    void *arg, void *result);
int ddihp_connector_ops(ddi_hp_cn_handle_t *hdlp,
    ddi_hp_op_t op, void *arg, void *result);
void ddihp_cn_gen_sysevent(ddi_hp_cn_handle_t *hdlp,
    ddi_hp_cn_sysevent_t event_sub_class, int hint, int kmflag);
int ddihp_cn_unregister(ddi_hp_cn_handle_t *hdlp);

#endif /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DDI_HP_IMPL_H */
