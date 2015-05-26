/*
 * Copyright (c) 2010, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _LIBHOTPLUG_H
#define	_LIBHOTPLUG_H

#pragma ident	"@(#)libhotplug.h	1.3	12/06/26 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/types.h>

/*
 * Define node types in hotplug snapshot.
 */
#define	HP_NODE_NONE		0
#define	HP_NODE_DEVICE		1
#define	HP_NODE_CONNECTOR	2
#define	HP_NODE_PORT		3
#define	HP_NODE_USAGE		4

/*
 * Define flags for hp_init().
 */
#define	HPINFOUSAGE		0x1
#define	HPINFOSEARCH		0x2	/* private flag */

/*
 * Define flags for hp_set_state(), hp_install(), and hp_uninstall().
 */
#define	HPFORCE			0x4
#define	HPQUERY			0x8
#define	HPPROBEONE		0x10

/*
 * Define return values for hp_traverse() callbacks.
 */
#define	HP_WALK_CONTINUE	0
#define	HP_WALK_PRUNECHILD	1
#define	HP_WALK_PRUNESIBLING	2
#define	HP_WALK_TERMINATE	3

/*
 * Define opaque handle to hotplug nodes.
 */
typedef struct hp_node *hp_node_t;

/*
 * Interface prototypes.
 */
hp_node_t	hp_init(const char *path, const char *connection, uint_t flags);
void		hp_fini(hp_node_t root);
int		hp_traverse(hp_node_t root, void *arg,
		    int (*hp_callback)(hp_node_t, void *arg));
int		hp_type(hp_node_t node);
char		*hp_name(hp_node_t node);
char		*hp_usage(hp_node_t node);
char		*hp_driver(hp_node_t node);
int		hp_state(hp_node_t node);
char		*hp_description(hp_node_t node);
time_t		hp_last_change(hp_node_t node);
hp_node_t	hp_parent(hp_node_t node);
hp_node_t	hp_child(hp_node_t node);
hp_node_t	hp_sibling(hp_node_t node);
int		hp_path(hp_node_t node, char *path, char *connection);
int		hp_set_state(hp_node_t node, uint_t flags, int state,
		    hp_node_t *resultsp);
int		hp_set_private(hp_node_t node, const char *options,
		    char **resultsp);
int		hp_get_private(hp_node_t node, const char *options,
		    char **resultsp);
int		hp_install(hp_node_t node, uint_t flags, hp_node_t *resultsp);
int		hp_uninstall(hp_node_t node, uint_t flags, hp_node_t *resultsp);
int		hp_create_port(hp_node_t node, const char *cn_name,
		    hp_node_t *resultsp);
int		hp_remove_port(hp_node_t node, hp_node_t *resultsp);
int		hp_state_ceiling(hp_node_t node);
int		hp_set_state_ceiling(hp_node_t node, int state,
		    uint32_t *handlep, hp_node_t *resultsp);
int		hp_clear_state_ceiling(hp_node_t node, uint32_t handle,
		    int flags, hp_node_t *resultsp);
int		hp_pack(hp_node_t root, char **bufp, size_t *lenp);
int		hp_unpack(char *packed_buf, size_t packed_len, hp_node_t *retp);

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBHOTPLUG_H */
