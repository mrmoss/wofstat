/*
 * Copyright 2002 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_IPP_IPGPC_IPGPC_H
#define	_IPP_IPGPC_IPGPC_H

#pragma ident	"@(#)ipgpc.h	1.2	02/05/09 SMI"

#include <sys/types.h>
#include <sys/kmem.h>
#include <sys/socket.h>
#include <netinet/ip6.h>
#include <net/if.h>
#include <inet/common.h>
#include <inet/ip.h>

#ifdef	__cplusplus
extern "C" {
#endif

/* Header file for IP Generic Packet Classifier (ipgpc) ipp kernel module */

/* names for single ipgpc action and module name */
#define	IPGPC_CLASSIFY		"ipgpc.classify"
#define	IPGPC_NAME		"ipgpc"

/* config names of name-value pairs and type */
#define	IPGPC_IF_GROUPNAME	"ipgpc.if_groupname" /* string */
#define	IPGPC_UID		"ipgpc.user" /* int32_t */
#define	IPGPC_PROJID		"ipgpc.projid" /* int32_t */
#define	IPGPC_IF_INDEX		"ipgpc.if_index" /* uint32_t */
#define	IPGPC_DIR		"ipgpc.direction" /* uint32_t */
#define	IPGPC_PROTO		"ipgpc.protocol" /* byte */
#define	IPGPC_DSFIELD		"ipgpc.dsfield"	/* byte */
#define	IPGPC_DSFIELD_MASK	"ipgpc.dsfield_mask" /* byte */
#define	IPGPC_SPORT		"ipgpc.sport" /* uint16_t */
#define	IPGPC_SPORT_MASK	"ipgpc.sport_mask" /* uint16_t */
#define	IPGPC_DPORT		"ipgpc.dport" /* uint16_t */
#define	IPGPC_DPORT_MASK	"ipgpc.dport_mask" /* uint16_t */
#define	IPGPC_SADDR		"ipgpc.saddr" /* uint32_t[4] */
#define	IPGPC_SADDR_MASK	"ipgpc.saddr_mask" /* uint32_t[4] */
#define	IPGPC_SADDR_HOSTNAME	"ipgpc.saddr_hostname" /* string */
#define	IPGPC_DADDR		"ipgpc.daddr" /* uint32_t[4] */
#define	IPGPC_DADDR_MASK	"ipgpc.daddr_mask" /* uint32_t[4] */
#define	IPGPC_DADDR_HOSTNAME	"ipgpc.daddr_hostname" /* string */
#define	IPGPC_PRECEDENCE	"ipgpc.precedence" /* uint32_t */
#define	IPGPC_PRIORITY		"ipgpc.priority" /* uint32_t */
#define	IPGPC_FILTER_TYPE	"ipgpc.filter_type" /* byte */
#define	IPGPC_FILTER_INSTANCE	"ipgpc.filter_instance"	/* int32_t */
#define	IPGPC_FILTER_PRIVATE	"ipgpc.filter_private" /* string */

/* Filter Types for IPGPC_FILTER_TYPE */
#define	IPGPC_GENERIC_FLTR	0
#define	IPGPC_V4_FLTR		1
#define	IPGPC_V6_FLTR		2

#ifdef	__cplusplus
}
#endif

#endif	/* _IPP_IPGPC_IPGPC_H */
