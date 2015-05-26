/*
 * Copyright (c) 2010, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _LIBHOTPLUG_IMPL_H
#define	_LIBHOTPLUG_IMPL_H

#pragma ident	"@(#)libhotplug_impl.h	1.3	12/06/26 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/param.h>
#include <libhotplug.h>

/*
 * Definition of a node in a hotplug information snapshot.
 */
struct hp_node {
	int		hp_type;
	char		*hp_name;
	char		*hp_usage;
	char		*hp_description;
	char		*hp_basepath;
	char		*hp_driver;
	int		hp_state;
	int		hp_state_ceiling;
	time_t		hp_last_change;
	hp_node_t	hp_parent;
	hp_node_t	hp_child;
	hp_node_t	hp_sibling;
};

/*
 * Definitions used for packing/unpacking snapshots.
 */
#define	HP_INFO_BASE		"hp_info.basepath"
#define	HP_INFO_NODE		"hp_info.node"
#define	HP_INFO_BRANCH		"hp_info.branch"
#define	HP_INFO_TYPE		"hp_info.type"
#define	HP_INFO_NAME		"hp_info.name"
#define	HP_INFO_USAGE		"hp_info.usage"
#define	HP_INFO_STATE		"hp_info.state"
#define	HP_INFO_DESC		"hp_info.description"
#define	HP_INFO_TIME		"hp_info.last_change"
#define	HP_INFO_DRIVER		"hp_info.driver"
#define	HP_INFO_STATE_CEILING	"hp_info.state_ceiling"

/*
 * Definitions for the door interface to hotplugd(1m).
 */
#define	HOTPLUGD_PID	"/var/run/hotplugd.pid"
#define	HOTPLUGD_DOOR	"/var/run/hotplugd_door"

typedef enum {
	HP_CMD_NONE = 0,
	HP_CMD_GETINFO,
	HP_CMD_CHANGESTATE,
	HP_CMD_SETPRIVATE,
	HP_CMD_GETPRIVATE,
	HP_CMD_INSTALL,
	HP_CMD_UNINSTALL,
	HP_CMD_CREATE_PORT,
	HP_CMD_REMOVE_PORT,
	HP_CMD_SET_CEILING,
	HP_CMD_CLEAR_CEILING
} hp_cmd_t;

#define	HPD_CMD		"hp_door.cmd"
#define	HPD_PATH	"hp_door.path"
#define	HPD_CONNECTION	"hp_door.connection"
#define	HPD_FLAGS	"hp_door.flags"
#define	HPD_STATE	"hp_door.state"
#define	HPD_OPTIONS	"hp_door.options"
#define	HPD_INFO	"hp_door.info"
#define	HPD_STATUS	"hp_door.status"
#define	HPD_SEQNUM	"hp_door.seqnum"
#define	HPD_HANDLE	"hp_door.handle"

/*
 * Definition of macros to validate flags.
 */
#define	HP_INIT_FLAGS_VALID(f)	((f & ~(HPINFOUSAGE)) == 0)
#define	HP_SET_STATE_FLAGS_VALID(f)	\
	((f & ~(HPFORCE | HPQUERY | HPPROBEONE)) == 0)
#define	HP_CLEAR_STATE_CEILING_VALID_FLAGS(f)	\
	((f & ~(HPFORCE)) == 0)

/*
 * Definition of global flag to enable debug.
 */
extern int	libhotplug_debug;

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBHOTPLUG_IMPL_H */
