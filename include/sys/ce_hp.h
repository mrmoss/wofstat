/*
 * Copyright (c) 2002 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#pragma	ident	"@(#)ce_hp.h 1.6	03/02/04 SMI"

#ifndef _CE_HP_H
#define _CE_HP_H


#ifdef  __cplusplus
extern "C" {
#endif

/*
 * Flow simulator for cassini.
 */

/* Comparison opcodes */
#define	OP_EQ	0	/* pkt == val */
#define	OP_LT	1	/* pkt < val */
#define	OP_GT	2	/* pkt > val */
#define	OP_NP	3	/*
			 * new packet. True when a new packet is awaiting
			 * parsing, false otherwise. Thus it is not
			 * based on the mask or val in the instruction.
			 */

/* Output opcodes */
#define	CL_REG	0
#define	LD_FID	1
#define	LD_SEQ	2
#define	LD_CTL	3
#define	LD_SAP	4
#define	LD_R1	5
#define	LD_L3	6
#define	LD_SUM	7
#define	LD_HDR	8
#define	IM_FID	9
#define	IM_SEQ	10
#define	IM_SAP	11
#define	IM_R1	12
#define	IM_CTL	13
#define	LD_LEN	14
#define	ST_FLG	15

typedef enum {
	ip46tcp4tab,
	ip46tcp4nohttptab,
	ip4fragtab,
	ip46tcp4batchtab,
	workaroundtab,
	encriptiontab,
	no_hp
} hp_programs_t, *p_hp_programs_t;

typedef struct _prog_inst_t {
	char *note;
	unsigned short	mask;
	unsigned short	val;
	unsigned char	op;	/* Use OP_* defs above */

	/* if match succeeds, new offset and match */
	unsigned char	soff;	/* offset in 16 bit words */
	unsigned char	snext;

	/* if match fails, new offset and match */
	unsigned char	foff;	/* offset in 16 bit words */
	unsigned char	fnext;

	/* output info */
	unsigned char	outop;		/* Output opcode */
	unsigned short	outarg;		/* argument, 10 bits */
	unsigned char	outenab;	/* output enable */
					/* 0=not enabled, 1=if match, */
					/* 2=if !match, 3=always */
	unsigned char	outshift;	/* barrel shift right. 4 bits */
	unsigned short	outmask;	/* 16 bit mask */
} prog_inst_t, *p_prog_inst_t;

typedef struct _hp_progs_t {
	p_prog_inst_t program;
	uint_t	progam_sz; 
} hp_progs_t, *p_hp_progs_t;

/* Generic match step #s */

/* match step #s for IP4TCP4 */
#define	S1_PCKT		0
#define	S1_VLAN		1
#define	S1_CFI		2
#define	S1_8023		3
#define	S1_LLC		4
#define	S1_LLCc		5
#define	S1_IPV4		6
#define	S1_IPV4c	7
#define	S1_IPV4F	8
#define	S1_TCP44	9
#define	S1_IPV6		10
#define	S1_IPV6L	11
#define	S1_IPV6c	12
#define	S1_TCP64	13
#define	S1_TCPSQ	14
#define	S1_TCPFG	15
#define	S1_TCPHL	16
#define	S1_TCPHc	17
#define	S1_CLNP		18
#define	S1_CLNP2	19
#define	S1_DROP		20
#define	S2_HTTP		21
#define	S1_ESP4		22
#define	S1_AH4		23
#define	S1_ESP6		24
#define	S1_AH6		25


prog_inst_t hp_prog_1[] = {
/*mask  val     op   soff, snext, foff,  fnext,    outop, otarg, en,  os,  omask */
"packet arrival?",
0xffff, 0x0000, OP_NP,  6, S1_VLAN,  0, S1_PCKT,  CL_REG, 0x3ff,  1, 0x0, 0x0000,

"VLAN?",
0xffff, 0x8100, OP_EQ,  1, S1_CFI,   0, S1_8023,  IM_CTL, 0x00a,  3, 0x0, 0xffff,

"CFI?",
0x1000, 0x1000, OP_EQ,  0, S1_DROP,  1, S1_8023,  CL_REG, 0x000,  0, 0x0, 0x0000,

"8023?",
0xffff, 0x0600, OP_LT,  1, S1_LLC,   0, S1_IPV4,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLC?",
0xffff, 0xaaaa, OP_EQ,  1, S1_LLCc,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLCc?",
0xff00, 0x0300, OP_EQ,  2, S1_IPV4,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"IPV4?",
0xffff, 0x0800, OP_EQ,  1, S1_IPV4c, 0, S1_IPV6,  LD_SAP, 0x100,  3, 0x0, 0xffff,

"IPV4 cont?",
0xff00, 0x4500, OP_EQ,  3, S1_IPV4F, 0, S1_CLNP,  LD_SUM, 0x00a,  1, 0x0, 0x0000,

"IPV4 frag?",
0x3fff, 0x0000, OP_EQ,  1, S1_TCP44, 0, S1_CLNP,  LD_LEN, 0x03e,  1, 0x0, 0xffff,

"TCP44?",
0x00ff, 0x0006, OP_EQ,  7, S1_TCPSQ, 0, S1_CLNP,  LD_FID, 0x182,  1, 0x0, 0xffff, /* FID IP4&TCP src+dst */

"IPV6?",
0xffff, 0x86dd, OP_EQ,  1, S1_IPV6L, 0, S1_CLNP,  LD_SUM, 0x015,  1, 0x0, 0x0000,

"IPV6 len",
0xf000, 0x6000, OP_EQ,  0, S1_IPV6c, 0, S1_CLNP,  IM_R1,  0x128,  1, 0x0, 0xffff,

"IPV6 cont?",
0x0000, 0x0000, OP_EQ,  3, S1_TCP64, 0, S1_CLNP,  LD_FID, 0x484,  1, 0x0, 0xffff, /* FID IP6&TCP src+dst */

"TCP64?",
0xff00, 0x0600, OP_EQ, 18, S1_TCPSQ, 0, S1_CLNP,  LD_LEN, 0x03f,  1, 0x0, 0xffff,

"TCP seq",	/* DADDR should point to dest port */
0x0000, 0x0000, OP_EQ,  0, S1_TCPFG, 4, S1_TCPFG, LD_SEQ, 0x081,  3, 0x0, 0xffff, /* Load TCP seq # */

"TCP control flags",
0x0000, 0x0000, OP_EQ,  0, S1_TCPHL, 0, S1_TCPHL, ST_FLG, 0x045,  3, 0x0, 0x002f, /* Load TCP flags */

"TCP length",
0x0000, 0x0000, OP_EQ,  0, S1_TCPHc, 0, S1_TCPHc, LD_R1,  0x205,  3, 0xB, 0xf000,

"TCP length cont",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  LD_HDR, 0x0ff,  3, 0x0, 0xffff,

"Cleanup",
0x0000, 0x0000, OP_EQ,  0, S1_CLNP2,  0, S1_CLNP2,  IM_CTL, 0x001,  3, 0x0, 0x0001,

"Cleanup2",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x000,  0, 0x0, 0x0000,

"Drop packet",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x080,  3, 0x0, 0xffff,
};

/*
 * Alternate table load which excludes HTTP server traffic from reassembly.
 * It is substantially similar to the basic table, with one extra state
 * and a few extra compares.
 */
prog_inst_t hp_prog_2[] = {
/*mask  val     op   soff, snext, foff,  fnext,    outop, otarg, en,  os,  omask */
"packet arrival?",
0xffff, 0x0000, OP_NP,  6, S1_VLAN,  0, S1_PCKT,  CL_REG, 0x3ff,  1, 0x0, 0x0000,

"VLAN?",
0xffff, 0x8100, OP_EQ,  1, S1_CFI,   0, S1_8023,  IM_CTL, 0x00a,  3, 0x0, 0xffff,

"CFI?",
0x1000, 0x1000, OP_EQ,  0, S1_DROP,  1, S1_8023,  CL_REG, 0x000,  0, 0x0, 0x0000,

"8023?",
0xffff, 0x0600, OP_LT,  1, S1_LLC,   0, S1_IPV4,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLC?",
0xffff, 0xaaaa, OP_EQ,  1, S1_LLCc,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLCc?",
0xff00, 0x0300, OP_EQ,  2, S1_IPV4,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"IPV4?",
0xffff, 0x0800, OP_EQ,  1, S1_IPV4c, 0, S1_IPV6,  LD_SAP, 0x100,  3, 0x0, 0xffff,

"IPV4 cont?",
0xff00, 0x4500, OP_EQ,  3, S1_IPV4F, 0, S1_CLNP,  LD_SUM, 0x00a,  1, 0x0, 0x0000,

"IPV4 frag?",
0x3fff, 0x0000, OP_EQ,  1, S1_TCP44, 0, S1_CLNP,  LD_LEN, 0x03e,  1, 0x0, 0xffff,

"TCP44?",
0x00ff, 0x0006, OP_EQ,  7, S1_TCPSQ, 0, S1_CLNP,  LD_FID, 0x182,  1, 0x0, 0xffff, /* 
FID IP4&TCP src+dst */

"IPV6?",
0xffff, 0x86dd, OP_EQ,  1, S1_IPV6L, 0, S1_CLNP,  LD_SUM, 0x015,  1, 0x0, 0x0000,

"IPV6 len",
0xf000, 0x6000, OP_EQ,  0, S1_IPV6c, 0, S1_CLNP,  IM_R1,  0x128,  1, 0x0, 0xffff,

"IPV6 cont?",
0x0000, 0x0000, OP_EQ,  3, S1_TCP64, 0, S1_CLNP,  LD_FID, 0x484,  1, 0x0, 0xffff, /* 
FID IP6&TCP src+dst */

"TCP64?",
0xff00, 0x0600, OP_EQ, 18, S1_TCPSQ, 0, S1_CLNP,  LD_LEN, 0x03f,  1, 0x0, 0xffff,

"TCP seq",      /* DADDR should point to dest port */
0xFFFF, 0x0080, OP_EQ,  0, S2_HTTP,  0, S1_TCPFG, LD_SEQ, 0x081,  3, 0x0, 0xffff, /* 
Load TCP seq # */

"TCP control flags",
0xFFFF, 0x8080, OP_EQ,  0, S2_HTTP,  0, S1_TCPHL, ST_FLG, 0x145,  2, 0x0, 0x002f, /* 
Load TCP flags */

"TCP length",
0x0000, 0x0000, OP_EQ,  0, S1_TCPHc, 0, S1_TCPHc, LD_R1,  0x205,  3, 0xB, 0xf000,

"TCP length cont",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  LD_HDR, 0x0ff,  3, 0x0, 0xffff,

"Cleanup",
0x0000, 0x0000, OP_EQ,  0, S1_CLNP2,  0, S1_CLNP2,  IM_CTL, 0x001,  3, 0x0, 0x0001,

"Cleanup 2",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  CL_REG, 0x002,  3, 0x0, 0x0000,

"Drop packet",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x080,  3, 0x0, 0xffff,

"No HTTP",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x044,  3, 0x0, 0xffff,
};

/* match step #s for IP4FRAG */
#define	S3_IPV6c	11
#define	S3_TCP64	12
#define	S3_TCPSQ	13
#define	S3_TCPFG	14
#define	S3_TCPHL	15
#define	S3_TCPHc	16
#define	S3_FRAG		17
#define	S3_FOFF		18
#define	S3_CLNP		19

prog_inst_t hp_prog_3[] = {
/*mask  val     op   soff, snext, foff,  fnext,    outop, otarg, en,  os,  omask */
"packet arrival?",
0xffff, 0x0000, OP_NP,  6, S1_VLAN,  0, S1_PCKT,  CL_REG, 0x3ff,  1, 0x0, 0x0000,

"VLAN?",
0xffff, 0x8100, OP_EQ,  1, S1_CFI,   0, S1_8023,  IM_CTL, 0x00a,  3, 0x0, 0xffff,

"CFI?",
0x1000, 0x1000, OP_EQ,  0, S3_CLNP,  1, S1_8023,  CL_REG, 0x000,  0, 0x0, 0x0000,

"8023?",
0xffff, 0x0600, OP_LT,  1, S1_LLC,   0, S1_IPV4,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLC?",
0xffff, 0xaaaa, OP_EQ,  1, S1_LLCc,  0, S3_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLCc?",
0xff00, 0x0300, OP_EQ,  2, S1_IPV4,  0, S3_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"IPV4?",
0xffff, 0x0800, OP_EQ,  1, S1_IPV4c, 0, S1_IPV6,  LD_SAP, 0x100,  3, 0x0, 0xffff,

"IPV4 cont?",
0xff00, 0x4500, OP_EQ,  3, S1_IPV4F, 0, S3_CLNP,  LD_SUM, 0x00a,  1, 0x0, 0x0000,

"IPV4 frag?",
0x3fff, 0x0000, OP_EQ,  1, S1_TCP44, 0, S3_FRAG,  LD_LEN, 0x03e,  3, 0x0, 0xffff,

"TCP44?",
0x00ff, 0x0006, OP_EQ,  7, S3_TCPSQ, 0, S3_CLNP,  LD_FID, 0x182,  3, 0x0, 0xffff, /* FID IP4&TCP src+dst */

"IPV6?",
0xffff, 0x86dd, OP_EQ,  1, S3_IPV6c, 0, S3_CLNP,  LD_SUM, 0x015,  1, 0x0, 0x0000,

"IPV6 cont?",
0xf000, 0x6000, OP_EQ,  3, S3_TCP64, 0, S3_CLNP,  LD_FID, 0x484,  1, 0x0, 0xffff, /* FID IP6&TCP src+dst */

"TCP64?",
0xff00, 0x0600, OP_EQ, 18, S3_TCPSQ, 0, S3_CLNP,  LD_LEN, 0x03f,  1, 0x0, 0xffff,

"TCP seq",	/* DADDR should point to dest port */
0x0000, 0x0000, OP_EQ,  0, S3_TCPFG, 4, S3_TCPFG, LD_SEQ, 0x081,  3, 0x0, 0xffff, /* Load TCP seq # */

"TCP control flags",
0x0000, 0x0000, OP_EQ,  0, S3_TCPHL, 0, S3_TCPHL, ST_FLG, 0x045,  3, 0x0, 0x002f, /* Load TCP flags */

"TCP length",
0x0000, 0x0000, OP_EQ,  0, S3_TCPHc, 0, S3_TCPHc, LD_R1,  0x205,  3, 0xB, 0xf000,

"TCP length cont",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  LD_HDR, 0x0ff,  3, 0x0, 0xffff,

"IP4 Fragment",
0x0000, 0x0000, OP_EQ,  0, S3_FOFF,  0, S3_FOFF,  LD_FID, 0x103,  3, 0x0, 0xffff, /* FID IP4 src+dst */

"IP4 frag offset",
0x0000, 0x0000, OP_EQ,  0, S3_FOFF,  0, S3_FOFF,  LD_SEQ, 0x040,  1, 0xD, 0xfff8,

"Cleanup",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x001,  3, 0x0, 0x0001,
};

/*
 * Alternate table which does batching without reassembly
 */
prog_inst_t hp_prog_4[] = {
/*mask  val     op   soff, snext, foff,   fnext,   outop, otarg, en,  os,  omask */
"packet arrival?",
0xffff, 0x0000, OP_NP,  6, S1_VLAN,  0, S1_PCKT,  CL_REG, 0x3ff,  1, 0x0, 0x0000,

"VLAN?",
0xffff, 0x8100, OP_EQ,  1, S1_CFI,   0, S1_8023,  IM_CTL, 0x00a,  3, 0x0, 0xffff,

"CFI?",
0x1000, 0x1000, OP_EQ,  0, S1_DROP,  1, S1_8023,  CL_REG, 0x000,  0, 0x0, 0x0000,

"8023?",
0xffff, 0x0600, OP_LT,  1, S1_LLC,   0, S1_IPV4,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLC?",
0xffff, 0xaaaa, OP_EQ,  1, S1_LLCc,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLCc?",
0xff00, 0x0300, OP_EQ,  2, S1_IPV4,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"IPV4?",
0xffff, 0x0800, OP_EQ,  1, S1_IPV4c, 0, S1_IPV6,  LD_SAP, 0x100,  3, 0x0, 0xffff,

"IPV4 cont?",
0xff00, 0x4500, OP_EQ,  3, S1_IPV4F, 0, S1_CLNP,  LD_SUM, 0x00a,  1, 0x0, 0x0000,

"IPV4 frag?",
0x3fff, 0x0000, OP_EQ,  1, S1_TCP44, 0, S1_CLNP,  LD_LEN, 0x03e,  1, 0x0, 0xffff,

"TCP44?",
0x00ff, 0x0006, OP_EQ,  7, S1_TCPSQ, 0, S1_CLNP,  LD_FID, 0x182,  1, 0x0, 0xffff, /* FID IP4&TCP src+dst */

"IPV6?",
0xffff, 0x86dd, OP_EQ,  1, S1_IPV6L, 0, S1_CLNP,  LD_SUM, 0x015,  1, 0x0, 0x0000,

"IPV6 len",
0xf000, 0x6000, OP_EQ,  0, S1_IPV6c, 0, S1_CLNP,  IM_R1,  0x128,  1, 0x0, 0xffff,

"IPV6 cont?",
0x0000, 0x0000, OP_EQ,  3, S1_TCP64, 0, S1_CLNP,  LD_FID, 0x484,  1, 0x0, 0xffff, /* FID IP6&TCP src+dst */

"TCP64?",
0xff00, 0x0600, OP_EQ, 18, S1_TCPSQ, 0, S1_CLNP,  LD_LEN, 0x03f,  1, 0x0, 0xffff,

"TCP seq",	/* DADDR should point to dest port */
0x0000, 0x0000, OP_EQ,  0, S1_TCPFG, 0, S1_TCPFG, LD_SEQ, 0x081,  3, 0x0, 0xffff, /* Load TCP seq # */

"TCP control flags",
0x0000, 0x0000, OP_EQ,  0, S1_TCPHL, 0, S1_TCPHL, ST_FLG, 0x000,  3, 0x0, 0x0000, /* Load TCP flags */

"TCP length",
0x0000, 0x0000, OP_EQ,  0, S1_TCPHc, 0, S1_TCPHc, LD_R1,  0x205,  3, 0xB, 0xf000,

"TCP length cont",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x040,  3, 0x0, 0xffff, /* set batch bit */

"Cleanup",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x001,  3, 0x0, 0x0001,

"Drop packet",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x080,  3, 0x0, 0xffff,
};

/* Workaround for Cassini rev2 descriptor corruption problem.
 * Does batching without reassembly, and sets the SAP to a known
 * data pattern for all packets. */

prog_inst_t  hp_prog_5[] = {
/*mask  val     op   soff, snext, foff,  fnext,    outop, otarg, en,  os,  omask 
*/
"packet arrival?",
0xffff, 0x0000, OP_NP,  6, S1_VLAN,  0, S1_PCKT,  CL_REG, 0x3ff,  1, 0x0, 0x0000,

"VLAN?",
0xffff, 0x8100, OP_EQ,  1, S1_CFI,   0, S1_8023,  IM_CTL, 0x04a,  3, 0x0, 0xffff,

"CFI?",
0x1000, 0x1000, OP_EQ,  0, S1_CLNP,  1, S1_8023,  CL_REG, 0x000,  0, 0x0, 0x0000,

"8023?",
0xffff, 0x0600, OP_LT,  1, S1_LLC,   0, S1_IPV4,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLC?",
0xffff, 0xaaaa, OP_EQ,  1, S1_LLCc,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"LLCc?",
0xff00, 0x0300, OP_EQ,  2, S1_IPV4,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000,

"IPV4?",
0xffff, 0x0800, OP_EQ,  1, S1_IPV4c, 0, S1_IPV6,  IM_SAP, 0x6AE,  3, 0x0, 0xffff,

"IPV4 cont?",
0xff00, 0x4500, OP_EQ,  3, S1_IPV4F, 0, S1_CLNP,  LD_SUM, 0x00a,  1, 0x0, 0x0000,

"IPV4 frag?",
0x3fff, 0x0000, OP_EQ,  1, S1_TCP44, 0, S1_CLNP,  LD_LEN, 0x03e,  1, 0x0, 0xffff,

"TCP44?",
0x00ff, 0x0006, OP_EQ,  7, S1_TCPSQ, 0, S1_CLNP,  LD_FID, 0x182,  3, 0x0, 0xffff, /* FID IP4&TCP src+dst */

"IPV6?",
0xffff, 0x86dd, OP_EQ,  1, S1_IPV6L, 0, S1_CLNP,  LD_SUM, 0x015,  1, 0x0, 0x0000,

"IPV6 len",
0xf000, 0x6000, OP_EQ,  0, S1_IPV6c, 0, S1_CLNP,  IM_R1,  0x128,  1, 0x0, 0xffff,

"IPV6 cont?",
0x0000, 0x0000, OP_EQ,  3, S1_TCP64, 0, S1_CLNP,  LD_FID, 0x484,  1, 0x0, 0xffff, /* FID IP6&TCP src+dst */

"TCP64?",
0xff00, 0x0600, OP_EQ, 18, S1_TCPSQ, 0, S1_CLNP,  LD_LEN, 0x03f,  1, 0x0, 0xffff,

"TCP seq",      /* DADDR should point to dest port */
0x0000, 0x0000, OP_EQ,  0, S1_TCPFG, 4, S1_TCPFG, LD_SEQ, 0x081,  3, 0x0, 0xffff, /* Load TCP seq # */

"TCP control flags",
0x0000, 0x0000, OP_EQ,  0, S1_TCPHL, 0, S1_TCPHL, ST_FLG, 0x045,  3, 0x0, 0x002f, /* Load TCP flags */

"TCP length",
0x0000, 0x0000, OP_EQ,  0, S1_TCPHc, 0, S1_TCPHc, LD_R1,  0x205,  3, 0xB, 0xf000,

"TCP length cont",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  LD_HDR, 0x0ff,  3, 0x0, 0xffff,

"Cleanup",
0x0000, 0x0000, OP_EQ,  0, S1_CLNP2, 0, S1_CLNP2, IM_SAP, 0x6AE,  3, 0x0, 0xffff,

"Cleanup 2",
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x001,  3, 0x0, 0x0001,
};

prog_inst_t  hp_prog_6[] = {
/*mask  val     op   soff, snext, foff,  fnext,    outop, otarg, en,  os,  omask 
*/
"packet arrival?", /* 00 */
0xffff, 0x0000, OP_NP,  6, S1_VLAN,  0, S1_PCKT,  CL_REG, 0x3ff,  1, 0x0, 0x0000
,

"VLAN?", /* 01 */
0xffff, 0x8100, OP_EQ,  1, S1_CFI,   0, S1_8023,  IM_CTL, 0x00a,  3, 0x0, 0xffff
,
#if 0
//"CFI?", /* 02 FIND CFI and If FIND go to S1_DROP */
//0x1000, 0x1000, OP_EQ,  0, S1_DROP,  1, S1_8023,  CL_REG, 0x000,  0, 0x0, 0x00
00,
#endif
"CFI?", /* 02 FIND CFI and If FIND go to CleanUP1 (ignore and send to host) */
0x1000, 0x1000, OP_EQ,  0, S1_CLNP,  1, S1_8023,  CL_REG, 0x000,  0, 0x0, 0x0000
,

"8023?", /* 03 */
0xffff, 0x0600, OP_LT,  1, S1_LLC,   0, S1_IPV4,  CL_REG, 0x000,  0, 0x0, 0x0000
,

"LLC?", /* 04 */
0xffff, 0xaaaa, OP_EQ,  1, S1_LLCc,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000
,

"LLCc?", /* 05 */
0xff00, 0x0300, OP_EQ,  2, S1_IPV4,  0, S1_CLNP,  CL_REG, 0x000,  0, 0x0, 0x0000
,

"IPV4?", /* 06 */
0xffff, 0x0800, OP_EQ,  1, S1_IPV4c, 0, S1_IPV6,  LD_SAP, 0x100,  3, 0x0, 0xffff
,

"IPV4 cont?", /* 07 */
0xff00, 0x4500, OP_EQ,  3, S1_IPV4F, 0, S1_CLNP,  LD_SUM, 0x00a,  1, 0x0, 0x0000
,

"IPV4 frag?", /* 08 */
0x3fff, 0x0000, OP_EQ,  1, S1_TCP44, 0, S1_CLNP,  LD_LEN, 0x03e,  1, 0x0, 0xffff
,

"TCP44?", /* 09 */
0x00ff, 0x0006, OP_EQ,  7, S1_TCPSQ, 0, S1_ESP4,  LD_FID, 0x182,  1, 0x0, 0xffff
, /* FID IP4&TCP src+dst */


"IPV6?", /* 10 */
0xffff, 0x86dd, OP_EQ,  1, S1_IPV6L, 0, S1_CLNP,  LD_SUM, 0x015,  1, 0x0, 0x0000
,

"IPV6 len", /* 11 */
0xf000, 0x6000, OP_EQ,  0, S1_IPV6c, 0, S1_CLNP,  IM_R1,  0x128,  1, 0x0, 0xffff
,

"IPV6 cont?", /* 12 */
0x0000, 0x0000, OP_EQ,  3, S1_TCP64, 0, S1_CLNP,  LD_FID, 0x484,  1, 0x0, 0xffff
, /*  FID IP6&TCP src+dst */
"TCP64?", /* 13 */
#if 0
//@@@0xff00, 0x0600, OP_EQ, 18, S1_TCPSQ, 0, S1_ESP6,  LD_LEN, 0x03f,  1, 0x0, 0xffff,
#endif
0xff00, 0x0600, OP_EQ, 12, S1_TCPSQ, 0, S1_ESP6,  LD_LEN, 0x03f,  1, 0x0, 0xffff
,
"TCP seq", /* 14:DADDR should point to dest port */
0xFFFF, 0x0080, OP_EQ,  0, S2_HTTP,  0, S1_TCPFG, LD_SEQ, 0x081,  3, 0x0, 0xffff
, /* Load TCP seq # */

"TCP control flags", /* 15 */
0xFFFF, 0x8080, OP_EQ,  0, S2_HTTP,  0, S1_TCPHL, ST_FLG, 0x145,  2, 0x0, 0x002f
, /* Load TCP flags */

"TCP length", /* 16 */
0x0000, 0x0000, OP_EQ,  0, S1_TCPHc, 0, S1_TCPHc, LD_R1,  0x205,  3, 0xB, 0xf000
,
"TCP length cont", /* 17 */
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  LD_HDR, 0x0ff,  3, 0x0, 0xffff
,
"Cleanup", /* 18 */
0x0000, 0x0000, OP_EQ,  0, S1_CLNP2,  0, S1_CLNP2,  IM_CTL, 0x001,  3, 0x0, 0x0001,
"Cleanup 2", /* 19 */
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  CL_REG, 0x002,  3, 0x0, 0x0000
,
"Drop packet", /* 20 */
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x080,  3, 0x0, 0xffff
,
"No HTTP", /* 21 */
0x0000, 0x0000, OP_EQ,  0, S1_PCKT,  0, S1_PCKT,  IM_CTL, 0x044,  3, 0x0, 0xffff
,
"IPV4 ESP encrypted?",  /* 22: S1_ESP4 */
0x00ff, 0x0032, OP_EQ,  0, S1_CLNP2, 0, S1_AH4, IM_CTL, 0x021, 1,  0x0, 0xffff,
"IPV4 AH encrypted?",   /* 23:S1_AH4 */
0x00ff, 0x0033, OP_EQ,  0, S1_CLNP2, 0, S1_CLNP, IM_CTL, 0x021, 1,  0x0, 0xffff,
"IPV6 ESP encrypted?",  /* 24:S1_ESP6 */
#if 0
//@@@0x00ff, 0x0032, OP_EQ,  0, S1_CLNP2, 0, S1_AH6, IM_CTL, 0x021, 1,  0x0, 0xffff,
#endif
0xff00, 0x3200, OP_EQ,  0, S1_CLNP2, 0, S1_AH6, IM_CTL, 0x021, 1,  0x0, 0xffff,

"IPV6 AH encrypted?",   /* 25:S1_AH6 */
#if 0
//@@@0x00ff, 0x0033, OP_EQ,  0, S1_CLNP2, 0, S1_CLNP, IM_CTL, 0x021, 1,  0x0, 0xffff,
#endif
0xff00, 0x3300, OP_EQ,  0, S1_CLNP2, 0, S1_CLNP, IM_CTL, 0x021, 1,  0x0, 0xffff,
};

prog_inst_t hp_prog_null[] = {NULL};
/*
"null instruction", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
*/

hp_progs_t hp_progs[] = {hp_prog_1, sizeof(hp_prog_1)/sizeof(prog_inst_t),
			hp_prog_2, sizeof(hp_prog_2)/sizeof(prog_inst_t),
			hp_prog_3, sizeof(hp_prog_3)/sizeof(prog_inst_t),
			hp_prog_4, sizeof(hp_prog_4)/sizeof(prog_inst_t),
			hp_prog_5, sizeof(hp_prog_5)/sizeof(prog_inst_t),
			hp_prog_6, sizeof(hp_prog_6)/sizeof(prog_inst_t),
			hp_prog_null, 0};
#ifdef  __cplusplus
}
#endif

#endif
