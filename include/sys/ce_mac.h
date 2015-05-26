/*
 * Copyright (c) 2002 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#pragma ident	"@(#)ce_mac.h 1.26	03/11/11 SMI"

#ifndef	_CE_MAC_H
#define	_CE_MAC_H

#ifdef	__cplusplus
extern "C" {
#endif

#define NO_OF_TX_RINGS 0x4
#define NO_OF_RX_RINGS 0x4
#define CE_1GETHERMIN 255
#define CE_ETHERMIN 97
#define	CE_MAX_HEADER 250

/*
 * Saturn chip has a Half duplex issue, which can be
 * worked around by increasing the pre-amble to 65 bytes
 * we're using the rev-id to insure that this workaround
 * applies only to the SaturnB2. Great care must 
 * therefore be taken insure that if this problem is
 * fixed in a next generation and that the rev-id is also
 * iterated or the driver patched to support that new
 * chip. Note it's expected that with silicon revisions
 * that the rev-id is changed to allow reasonable version
 * control.
 */
#define SATURNB2 0x30

/*
 * Need to override the compiler structure packing
 * since the hardware is not compatible with the compiler 
 * packing.
 */
#pragma pack(2)

#define CE_MAX_FLOWS	64
	
typedef struct _pci_cfg_t {
	uint16_t vendorid;
	uint16_t devid;
	uint16_t command;
	uint16_t status;
	uint8_t  revid;
	uint8_t  res0;
	uint16_t junk1;
	uint8_t  cache_line;
	uint8_t  latency;
	uint8_t  header;
	uint8_t  bist;
	uint32_t base;
	uint32_t base14;
	uint32_t base18;
	uint32_t base1c;
	uint32_t base20;
	uint32_t base24;
	uint32_t base28;
	uint32_t base2c;
	uint32_t base30;
	uint32_t res1[2];
	uint8_t int_line;
	uint8_t int_pin;
	uint8_t	min_gnt;
	uint8_t max_lat;
} pci_cfg_t, *p_pci_cfg_t;

typedef union _core_arb_wt_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:27;
		uint32_t wtd_rr_disable:1;
		uint32_t tx_dma_wt:2;
		uint32_t rx_dma_wt:2;
#else
		uint32_t rx_dma_wt:2;
		uint32_t tx_dma_wt:2;
		uint32_t wtd_rr_disable:1;
		uint32_t res0:27;
#endif
	} bits;
} core_arb_wt_t, *p_core_arb_wt_t;

typedef union _glob_stat_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t tx_comp_reg:13;
		uint32_t pci_err:1;
		uint32_t mif:1;
		uint32_t mac_ctrl:1;
		uint32_t rx_mac:1;
		uint32_t tx_mac:1;
		uint32_t pcs:1;
		uint32_t summary_int:1;
		uint32_t res0:1;
		uint32_t rx_len_mismatch:1;
		uint32_t rx_comp_a_full:1;
		uint32_t rx_almost_no_buf:1;
		uint32_t rx_comp_full:1;
		uint32_t rx_tag_err:1;
		uint32_t rx_no_buf:1;
		uint32_t rx_done:1;
		uint32_t tx_tag_err:1;
		uint32_t tx_done:1;
		uint32_t tx_all:1;
		uint32_t tx_int_me:1;
#else
		uint32_t tx_int_me:1;
		uint32_t tx_all:1;
		uint32_t tx_done:1;
		uint32_t tx_tag_err:1;
		uint32_t rx_done:1;
		uint32_t rx_no_buf:1;
		uint32_t rx_tag_err:1;
		uint32_t rx_comp_full:1;
		uint32_t rx_almost_no_buf:1;
		uint32_t rx_comp_a_full:1;
		uint32_t rx_len_mismatch:1;
		uint32_t res0:1;
		uint32_t summary_int:1;
		uint32_t pcs:1;
		uint32_t tx_mac:1;
		uint32_t rx_mac:1;
		uint32_t mac_ctrl:1;
		uint32_t mif:1;
		uint32_t pci_err:1;
		uint32_t tx_comp_reg:13;
#endif
	} bits;
} glob_stat_t, *p_glob_stat_t;

typedef union _glob_rstat_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res1:24;
		uint32_t int_enable:1;
		uint32_t res0:2;
		uint32_t rx_almost_no_buf:1;
		uint32_t rx_no_buf:1;
		uint32_t rx_comp_a_full:1;
		uint32_t rx_comp_full:1;
		uint32_t rx_done:1;
#else
		uint32_t rx_done:1;
		uint32_t rx_comp_full:1;
		uint32_t rx_comp_a_full:1;
		uint32_t rx_no_buf:1;
		uint32_t rx_almost_no_buf:1;
		uint32_t res0:2;
		uint32_t int_enable:1;
		uint32_t res1:24;
#endif
	} bits;
} glob_rstat_t, *p_glob_rstat_t;

typedef union _pin_cfg_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res2:20;
		uint32_t lad:1;
		uint32_t res1:1;
		uint32_t fsi:1;
		uint32_t gmo:1;
		uint32_t mtp:1;
		uint32_t res0:1;
		uint32_t pds:1;
		uint32_t rla:1;
		uint32_t lla:1;
		uint32_t cla:1;
		uint32_t fla:1;
		uint32_t tla:1;
#else
		uint32_t tla:1;
		uint32_t fla:1;
		uint32_t cla:1;
		uint32_t lla:1;
		uint32_t rla:1;
		uint32_t pds:1;
		uint32_t res0:1;
		uint32_t mtp:1;
		uint32_t gmo:1;
		uint32_t fsi:1;
		uint32_t res1:1;
		uint32_t lad:1;
		uint32_t res2:20;
#endif
	} bits;
} pin_cfg_t, *p_pin_cfg_t;

typedef union _bim_stat_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:26;
		uint32_t rtry_cnt_tout:1;
		uint32_t dmar_zero_cnt_err_sy:1;
		uint32_t dmaw_zero_cnt_err_sy:1;
		uint32_t other:1;
		uint32_t drto:1;
		uint32_t badack:1;
#else
		uint32_t badack:1;
		uint32_t drto:1;
		uint32_t other:1;
		uint32_t dmaw_zero_cnt_err_sy:1;
		uint32_t dmar_zero_cnt_err_sy:1;
		uint32_t rtry_cnt_tout:1;
		uint32_t res0:26;
#endif
	} bits;
} bim_stat_t, *p_bim_stat_t;

typedef union _bim_cfg_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res3:20;
		uint32_t block_perr:1;
		uint32_t bim_disabled:1;
		uint32_t disable_bim:1;
		uint32_t res0:1;
		uint32_t rta_int_en:1;
		uint32_t rma_int_en:1;
		uint32_t parity_err_en:1;
		uint32_t bus32wide:1;
		uint32_t m66en:1;
		uint32_t bd64_dis:1;
		uint32_t res1:2;
#else
		uint32_t res1:2;
		uint32_t bd64_dis:1;
		uint32_t m66en:1;
		uint32_t bus32wide:1;
		uint32_t parity_err_en:1;
		uint32_t rma_int_en:1;
		uint32_t rta_int_en:1;
		uint32_t res0:1;
		uint32_t disable_bim:1;
		uint32_t bim_disabled:1;
		uint32_t block_perr:1;
		uint32_t res3:20;
#endif
	} bits;
} bim_cfg_t, *p_bim_cfg_t;

typedef union _bim_diag_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t state_mch:8;
		uint32_t res0:1;
		uint32_t burst_ctrl:7;
		uint32_t res1:16;
#else
		uint32_t res1:16;
		uint32_t burst_ctrl:7;
		uint32_t res0:1;
		uint32_t state_mch:8;
#endif
	} bits;
} bim_diag_t, *p_bim_diag_t;

typedef union _bim_ldo_en_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:27;
		uint32_t soft_bit_1:1;
		uint32_t soft_bit_0:1;
		uint32_t lb_ext_tri_l:1;
		uint32_t lb_pcs_tri_l:1;
		uint32_t lb_pad_tri_l:1;
#else
		uint32_t lb_pad_tri_l:1;
		uint32_t lb_pcs_tri_l:1;
		uint32_t lb_ext_tri_l:1;
		uint32_t soft_bit_0:1;
		uint32_t soft_bit_1:1;
		uint32_t res0:27;
#endif
	} bits;
} bim_ldo_en_t, *p_bim_ldo_en_t;

typedef union _tx_stat_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
                uint32_t res0:23;
                uint32_t peek_attempt_cnt_exp:1;
                uint32_t defer_timer_exp:1;
                uint32_t first_coll_cnt_exp:1;
                uint32_t late_coll_cnt_exp:1;
                uint32_t excess_coll_cnt_exp:1;
                uint32_t normal_coll_cnt_exp:1;
                uint32_t max_pkt_err:1;
                uint32_t uflo:1;
		uint32_t frame_txd:1;
#else
		uint32_t frame_txd:1;
                uint32_t uflo:1;
                uint32_t max_pkt_err:1;
                uint32_t normal_coll_cnt_exp:1;
                uint32_t excess_coll_cnt_exp:1;
                uint32_t late_coll_cnt_exp:1;
                uint32_t first_coll_cnt_exp:1;
                uint32_t defer_timer_exp:1;
                uint32_t peek_attempt_cnt_exp:1;
                uint32_t res0:23;
#endif
        } bits;
} tx_stat_t, *p_tx_stat_t;

typedef union _rx_stat_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:25;
		uint32_t viol_err_cnt_exp:1;
		uint32_t len_err_cnt_exp:1;
		uint32_t crc_err_cnt_exp:1;
		uint32_t align_err_exp:1;
		uint32_t frame_cnt_exp:1;
		uint32_t oflo:1;
		uint32_t frame_rxd:1;
#else
		uint32_t frame_rxd:1;
		uint32_t oflo:1;
		uint32_t frame_cnt_exp:1;
		uint32_t align_err_exp:1;
		uint32_t crc_err_cnt_exp:1;
		uint32_t len_err_cnt_exp:1;
		uint32_t viol_err_cnt_exp:1;
		uint32_t res0:25;
#endif
        } bits;
} rx_stat_t, *p_rx_stat_t;

typedef union _ctrl_stat_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t pause_time:16;
		uint32_t res0:13;
		uint32_t pause_off:1;
		uint32_t pause_on:1;
		uint32_t pause_received:1;
#else
		uint32_t pause_received:1;
		uint32_t pause_on:1;
		uint32_t pause_off:1;
		uint32_t res0:13;
		uint32_t pause_time:16;
#endif
        } bits;
} ctrl_stat_t, *p_ctrl_stat_t;

typedef union _ctrl_cfg_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:29;
		uint32_t pass_mac_ctrl:1;
		uint32_t rx_pause_en:1;
                uint32_t tx_pause_en:1;
#else
                uint32_t tx_pause_en:1;
		uint32_t rx_pause_en:1;
		uint32_t pass_mac_ctrl:1;
		uint32_t res0:29;
#endif
        } bits;
} ctrl_cfg_t, *p_ctrl_cfg_t;

typedef union _etx_cfg_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
                uint32_t res0:11;
                uint32_t paced_mode:1;
                uint32_t res1:2;
                uint32_t desc_ring_sz_4:4;
                uint32_t desc_ring_sz_3:4;
                uint32_t desc_ring_sz_2:4;
                uint32_t desc_ring_sz_1:4;
                uint32_t fifi_pio_sel:1;
                uint32_t dma_en:1;
#else
                uint32_t dma_en:1;
                uint32_t fifi_pio_sel:1;
                uint32_t desc_ring_sz_1:4;
                uint32_t desc_ring_sz_2:4;
                uint32_t desc_ring_sz_3:4;
                uint32_t desc_ring_sz_4:4;
                uint32_t res1:2;
                uint32_t paced_mode:1;
                uint32_t res0:11;
#endif
        } bits;
} etx_cfg_t, *p_etx_cfg_t;

typedef union _tx_state_mch1_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
                uint32_t cbg_arbiter:6;
                uint32_t cache_ctrl:4;
                uint32_t fifo_unload:4;
                uint32_t fifo_load:6;
                uint32_t checksum:2;
                uint32_t chain:10;
#else
                uint32_t chain:10;
                uint32_t checksum:2;
                uint32_t fifo_load:6;
                uint32_t fifo_unload:4;
                uint32_t cache_ctrl:4;
                uint32_t cbg_arbiter:6;
#endif
        } bits;
} tx_state_mch1_t, *p_tx_state_mch1_t;

typedef union _tx_state_mch2_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
                uint32_t res0:29;
                uint32_t comp_wb:3;
#else
                uint32_t comp_wb:3;
                uint32_t res0:29;
#endif
        } bits;
} tx_state_mch2_t, *p_tx_state_mch2_t;

typedef union _erx_cfg_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:19;
		uint32_t swivel_offset:3;
		uint32_t batch_disable:1;
		uint32_t rx_comp_sz:4;
		uint32_t rx_buf_sz:4;
		uint32_t dma_en:1;
#else
		uint32_t dma_en:1;
		uint32_t rx_buf_sz:4;
		uint32_t rx_comp_sz:4;
		uint32_t batch_disable:1;
		uint32_t swivel_offset:3;
		uint32_t res0:19;
#endif
	} bits;
} erx_cfg_t, *p_erx_cfg_t;

typedef union _page_sz_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t mtu_buf_off:2;
		uint32_t res0:1;
		uint32_t mtu_buf_stride:2;
		uint32_t res1:12;
		uint32_t mtu_buf_cnt:4;
		uint32_t res2:9;
		uint32_t size:2;
#else
		uint32_t size:2;
		uint32_t res2:9;
		uint32_t mtu_buf_cnt:4;
		uint32_t res1:12;
		uint32_t mtu_buf_stride:2;
		uint32_t res0:1;
		uint32_t mtu_buf_off:2;
#endif
	} bits;
} page_sz_t, *p_page_sz_t;

typedef union _rx_state_mch_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:14;
		uint32_t xfr_state:1;
		uint32_t desc_state:4;
		uint32_t data_state:4;
		uint32_t fc_state:2;
		uint32_t lm_state:3;
		uint32_t load_state:4;
#else
		uint32_t load_state:4;
		uint32_t lm_state:3;
		uint32_t fc_state:2;
		uint32_t data_state:4;
		uint32_t desc_state:4;
		uint32_t xfr_state:1;
		uint32_t res0:14;
#endif
	} bits;
} rx_state_mch_t, *p_rx_state_mch_t;

typedef union _pause_thresh_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:11;
		uint32_t on_threshold:9;
		uint32_t res1:3;
		uint32_t off_threshold:9;
#else
		uint32_t off_threshold:9;
		uint32_t res1:3;
		uint32_t on_threshold:9;
		uint32_t res0:11;
#endif
	} bits;
} pause_thresh_t, *p_pause_thresh_t;

typedef union _blanking_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:2;
		uint32_t intr_time:18;
		uint32_t res1:3;
		uint32_t intr_pkts:9;
#else
		uint32_t intr_pkts:9;
		uint32_t res1:3;
		uint32_t intr_time:18;
		uint32_t res0:2;
#endif
	} bits;
} blanking_t, *p_blanking_t;

typedef union _red_en_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t dv_10_12k:8;
		uint32_t dv_8_10k:8;
		uint32_t dv_6_8k:8;
		uint32_t dv_4_6k:8;
#else
		uint32_t dv_4_6k:8;
		uint32_t dv_6_8k:8;
		uint32_t dv_8_10k:8;
		uint32_t dv_10_12k:8;
#endif
	} bits;
} red_en_t, *p_red_en_t;

typedef union _fifo_fullness_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t dv_10_12k:2;
		uint32_t rx_fifo_level:11;
		uint32_t ipp_fifo_level:11;
		uint32_t fifo_pkt_cnt:8;
#else
		uint32_t fifo_pkt_cnt:8;
		uint32_t ipp_fifo_level:11;
		uint32_t rx_fifo_level:11;
		uint32_t dv_10_12k:2;
#endif
	} bits;
} fifo_fullness_t, *p_fifo_fullness_t;

typedef union _tx_cfg_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
                uint32_t res0:22;
                uint32_t tx_carrier_ext:1;
                uint32_t no_fcs:1;
                uint32_t slow_down:1;
                uint32_t no_backoff:1;
                uint32_t never_give_up_limit:1;
                uint32_t never_give_up:1;
                uint32_t enable_ipg0:1;
                uint32_t ignore_collisions:1;
                uint32_t ignore_carrier_sense:1;
		uint32_t tx_mac_en:1;
#else
		uint32_t tx_mac_en:1;
                uint32_t ignore_carrier_sense:1;
                uint32_t ignore_collisions:1;
                uint32_t enable_ipg0:1;
                uint32_t never_give_up:1;
                uint32_t never_give_up_limit:1;
                uint32_t no_backoff:1;
                uint32_t slow_down:1;
                uint32_t no_fcs:1;
                uint32_t tx_carrier_ext:1;
                uint32_t res0:22;
#endif
        } bits;
} tx_cfg_t, *p_tx_cfg_t;

typedef union _rx_cfg_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:23;
		uint32_t rx_carrier_ext:1;
		uint32_t disable_discard_on_err:1;
		uint32_t addr_filter_en:1;
		uint32_t hash_filter_en:1;
		uint32_t promisc_group:1;
		uint32_t promiscuous:1;
		uint32_t strip_fcs:1;
		uint32_t strip_pad:1;
		uint32_t rx_mac_en:1;
#else
		uint32_t rx_mac_en:1;
		uint32_t strip_pad:1;
		uint32_t strip_fcs:1;
		uint32_t promiscuous:1;
		uint32_t promisc_group:1;
		uint32_t hash_filter_en:1;
		uint32_t addr_filter_en:1;
		uint32_t disable_discard_on_err:1;
		uint32_t rx_carrier_ext:1;
		uint32_t res0:23;
#endif
	} bits;
} rx_cfg_t, *p_rx_cfg_t;

typedef union _xif_cfg_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:25;
		uint32_t fdplxled:1;
		uint32_t linkled:1;
		uint32_t mii_buff_oe:1;
		uint32_t gmii_mode:1;
		uint32_t disable_echo:1;
		uint32_t mii_int_loopback:1;
		uint32_t tx_mii_oe:1;
#else
		uint32_t tx_mii_oe:1;
		uint32_t mii_int_loopback:1;
		uint32_t disable_echo:1;
		uint32_t gmii_mode:1;
		uint32_t mii_buff_oe:1;
		uint32_t linkled:1;
		uint32_t fdplxled:1;
		uint32_t res0:25;
#endif
        } bits;
} xif_cfg_t, *p_xif_cfg_t;

typedef union _max_b_f_sz_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:1;
		uint32_t burst:15;
		uint32_t res1:1;
                uint32_t frame:15;
#else
                uint32_t frame:15;
		uint32_t res1:1;
		uint32_t burst:15;
		uint32_t res0:1;
#endif
        } bits;
} max_b_f_sz_t, *p_max_b_f_sz_t;

typedef union _mac_state_mch_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:5;
		uint32_t rlm:4;
		uint32_t rxfc:3;
		uint32_t tlm:4;
		uint32_t tx_encap:4;
		uint32_t tx_req:2;
		uint32_t tx_fc:4;
		uint32_t fifo_wr_sel:3;
                uint32_t tx_fifo_empty:3;
#else
                uint32_t tx_fifo_empty:3;
		uint32_t fifo_wr_sel:3;
		uint32_t tx_fc:4;
		uint32_t tx_req:2;
		uint32_t tx_encap:4;
		uint32_t tlm:4;
		uint32_t rxfc:3;
		uint32_t rlm:4;
		uint32_t res0:5;
#endif
        } bits;
} mac_state_mch_t, *p_mac_state_mch_t;

typedef union _glob_swr_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:28;
		uint32_t blk_rst_to_pcs:1;
		uint32_t rstout:1;
		uint32_t rx_swr:1;
		uint32_t tx_swr:1;
#else
		uint32_t tx_swr:1;
		uint32_t rx_swr:1;
		uint32_t rstout:1;
		uint32_t blk_rst_to_pcs:1;
		uint32_t res0:28;
#endif
	} bits;
} glob_swr_t, *p_glob_swr_t;

typedef struct _global_t {
	uint32_t core_arb_state;
	core_arb_wt_t core_arb_wt;
	uint32_t infinite_burst_en;
	glob_stat_t status;
	glob_stat_t mask;
	glob_stat_t sel_clear_mask;
	uint32_t res0;
	glob_stat_t status_alias;
	uint32_t res1[1016];
	bim_stat_t pci_err_status;
	bim_stat_t pci_err_mask;
	bim_cfg_t bim_cfg;
	bim_diag_t bim_diag;
	glob_swr_t soft_reset;
	uint32_t res2;
	uint32_t bim_dp_test;
	uint32_t res3;
	bim_ldo_en_t bim_ldo_en;
	uint32_t bim_buf_addr;
	uint64_t bim_data_reg;
	uint32_t bim_ram_cs;

	uint32_t probe_mux_sel;

	glob_rstat_t mask_intb;
	glob_rstat_t status_intb;
	glob_rstat_t sel_clr_mask_intb;
	glob_rstat_t status_alias_intb;

	glob_rstat_t mask_intc;
	glob_rstat_t status_intc;
	glob_rstat_t sel_clr_mask_intc;
	glob_rstat_t status_alias_intc;

	glob_rstat_t mask_intd;
	glob_rstat_t status_intd;
	glob_rstat_t sel_clr_mask_intd;
	glob_rstat_t status_alias_intd;

	uint32_t res4;

	pin_cfg_t pin_cfg;
	
} global_t, *p_global_t;

typedef struct _tx_dma_t {
	etx_cfg_t config;
	uint32_t res0[3];
	uint32_t fifo_wr_ptr;
	uint32_t fifo_swr_ptr;
	uint32_t fifo_rd_ptr;
	uint32_t fifo_srd_ptr;
	uint32_t fifo_pkt_cntr;
	tx_state_mch1_t state_mch1;
	tx_state_mch2_t state_mch2;
	uint64_t data_ptr;
	uint32_t kick[NO_OF_TX_RINGS];
	uint32_t completion[NO_OF_TX_RINGS];
	uint64_t comp_wb;
	uint64_t descriptors_pp[NO_OF_TX_RINGS];
	uint32_t max_burst[NO_OF_TX_RINGS];
	uint32_t res1[29];
	uint32_t fifo_addr;
	uint32_t fifo_tag;
	uint32_t fifo_data_l;
	uint32_t fifo_data_ht1;
	uint32_t fifo_data_ht0;
	uint32_t fifo_size;
	uint32_t rambist_c_s;
} tx_dma_t, *p_tx_dma_t;

typedef struct _rx_dma_t {
	erx_cfg_t config;
	page_sz_t page_size;
	uint32_t fifo_wr_ptr;
	uint32_t fifo_rd_ptr;
	uint32_t ipp_fifo_wr_ptr;
	uint32_t ipp_fifo_swr_ptr;
	uint32_t ipp_fifo_rd_ptr;
	rx_state_mch_t state_mch;
	pause_thresh_t pause_threshold;
	uint32_t kick;
	uint64_t descriptors_pp;
	uint64_t completion_pp;
	uint32_t completion;
	uint32_t completion_head;
	uint32_t completion_tail;
	blanking_t blanking;
	uint32_t almost_empty_thresholds;
	red_en_t random_early_detect_en;
	fifo_fullness_t fifo_fullness;
	uint32_t ipp_pkt_cnt;
	uint64_t working_dma_ptr;
	uint32_t bist;
	uint32_t ctrl_fifo_wp;
	uint32_t ctrl_fifo_rp;
	uint32_t blanking_for_ar;
	uint32_t res0[4];
	uint32_t fifo_addr;
	uint32_t fifo_tag;
	uint32_t fifo_data_l;
	uint32_t fifo_data_ht0;
	uint32_t fifo_data_ht1;
	uint32_t c_b_fifo_addr;
	uint32_t ctrl_fifo_data_l;
	uint32_t ctrl_fifo_data_m;
	uint32_t res1[24];
	uint32_t ctrl_fifo_data_h_flowid;
	uint32_t ipp_fifo_addr;
	uint32_t ipp_fifo_tag;
	uint32_t ipp_fifo_data_l;
	uint32_t ipp_fifo_data_ht0;
	uint32_t ipp_fifo_data_ht1;
	uint64_t hdr_page_ptr;
	uint64_t mtu_page_ptr;
	uint32_t ra_dma_tab_addr;
	uint32_t ra_dma_data_l;
	uint32_t ra_dma_data_m;
	uint32_t ra_dma_data_h;
} rx_dma_t, *p_rx_dma_t;

typedef struct _rx_dmaplus_t {
	uint64_t descriptors_pp;
	uint64_t completion1_pp;
	uint64_t completion2_pp;
	uint64_t completion3_pp;
	uint32_t kick;
	uint32_t completion;
	uint32_t completion1_head;
	uint32_t completion1_tail;
	uint32_t completion2_head;
	uint32_t completion2_tail;
	uint32_t completion3_head;
	uint32_t completion3_tail;
	uint32_t almost_empty_thresholds;
} rx_dmaplus_t, *p_rx_dmaplus_t;

typedef union _hp_cfg_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res1:12;
		uint32_t tcp_payload_threshold:11;
		uint32_t syn_inc_mask:1;
		uint32_t no_of_cpu:6;
		uint32_t res0:1;
		uint32_t parsing_en:1;
#else
		uint32_t parsing_en:1;
		uint32_t res0:1;
		uint32_t no_of_cpu:6;
		uint32_t syn_inc_mask:1;
		uint32_t tcp_payload_threshold:11;
		uint32_t res1:12;
#endif
	} bits;
} hp_cfg_t, *p_hp_cfg_t;

typedef union _hp_state_mch_t {
        uint32_t value;
        struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:12;
		uint32_t hp_bist:4;
		uint32_t hp_inst:3;
		uint32_t hp_ipp_ack:2;
		uint32_t hp_pkt_dest:2;
		uint32_t fdbm_lru:3;
		uint32_t fdbm_cam:3;
		uint32_t fdbm_main_st:3;
#else
		uint32_t fdbm_main_st:3;
		uint32_t fdbm_cam:3;
		uint32_t fdbm_lru:3;
		uint32_t hp_pkt_dest:2;
		uint32_t hp_ipp_ack:2;
		uint32_t hp_inst:3;
		uint32_t hp_bist:4;
		uint32_t res0:12;
#endif
	} bits;
} hp_state_mch_t, *p_hp_state_mch_t;

typedef struct _hp_t {
	hp_cfg_t config;
	uint32_t inst_ram_addr;
	uint32_t inst_ram_dl;
	uint32_t inst_ram_dm;
	uint32_t inst_ram_dh;
	uint32_t data_fdb_ram_addr;
	uint32_t data_ram_addr;
	uint32_t flow_database[12];
	hp_state_mch_t state_mch;
	uint32_t state[3];
	uint32_t ram_bist;
} hp_t, *p_hp_t;

typedef struct _mac_t {
	uint32_t tx_reset;
	uint32_t rx_reset;
	uint32_t snd_pause_cmd;
	uint32_t res1;
	tx_stat_t tx_stat;
	rx_stat_t rx_stat;
	ctrl_stat_t ctrl_status;
	uint32_t res2;
	tx_stat_t tx_mask;
	rx_stat_t rx_mask;
	ctrl_stat_t ctrl_mask;
	uint32_t res3;
	tx_cfg_t tx_cfg;
	rx_cfg_t rx_cfg;
	ctrl_cfg_t ctrl_cfg;
	xif_cfg_t xif_cfg;
	uint32_t interpktgap0;
	uint32_t interpktgap1;
	uint32_t interpktgap2;
	uint32_t slot_time;
	uint32_t minfrmsize;
	max_b_f_sz_t max_b_f_sz;
	uint32_t pa_size;
	uint32_t jam_size;
	uint32_t attempt_limit;
	uint32_t ctrl_type;
	uint32_t res4[6];
	uint32_t addr_regs[45];
	uint32_t res5[6];
	uint32_t filter_reg[3];
	uint32_t addr_filter_2_1;
	uint32_t addr_filter_0;
	uint32_t hash_table[16];
	uint32_t nor_col_cntr;
	uint32_t fas_col_cntr;
	uint32_t ex_col_cnt;
	uint32_t late_col_cntr;
	uint32_t defer_timer;
	uint32_t peak_attempts;
	uint32_t rx_frm_cntr;
	uint32_t len_err_cntr;
	uint32_t align_err_cntr;
	uint32_t fcs_err_cntr;
	uint32_t rx_cv_cntr;
	uint32_t random_no_seed;
	mac_state_mch_t state_mch;
} mac_t, *p_mac_t;

typedef union _mif_cfg_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:18;
		uint32_t phy_addr:4;
		uint32_t mdi1:1;
		uint32_t mdi0:1;
		uint32_t poll_reg:5;
		uint32_t bb_mode:1;
		uint32_t poll_en:1;
		uint32_t phy_sel:1;
#else
		uint32_t phy_sel:1;
		uint32_t poll_en:1;
		uint32_t bb_mode:1;
		uint32_t poll_reg:5;
		uint32_t mdi0:1;
		uint32_t mdi1:1;
		uint32_t phy_addr:4;
		uint32_t res0:18;
#endif
	} bits;
} mif_cfg_t, *p_mif_cfg_t;

typedef union _mif_stat_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint16_t data;
		uint16_t status;
#else
		uint16_t status;
		uint16_t data;
#endif
	} bits;
} mif_stat_t, *p_mif_stat_t;

typedef union _mif_frame_t {
	uint32_t value;
	struct {
#ifdef _BIT_FIELDS_HTOL
		uint32_t st:2;
		uint32_t op:2;
		uint32_t phyad:5;
		uint32_t regad:5;
		uint32_t ta_msb:1;
		uint32_t ta_lsb:1;
		uint32_t data:16;
#else
		uint32_t data:16;
		uint32_t ta_lsb:1;
		uint32_t ta_msb:1;
		uint32_t regad:5;
		uint32_t phyad:5;
		uint32_t op:2;
		uint32_t st:2;
#endif
	} bits;
} mif_frame_t, *p_mif_frame_t;

typedef struct _mif_t {
	uint32_t bb_clock;
	uint32_t bb_data;
	uint32_t bb_output_en;
	mif_frame_t frame;
	mif_cfg_t config;
	uint32_t mask;
	mif_stat_t status;
	uint32_t state_mch;
} mif_t, *p_mif_t;

typedef union _pcs_ctrl_t {
	uint32_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:16;
		uint32_t reset:1;
		uint32_t res1:1;
		uint32_t sel_10_100:1;
		uint32_t an_enable:1;
		uint32_t pwr_down:1;
		uint32_t isolate:1;
		uint32_t restart_an:1;
		uint32_t duplex:1;
		uint32_t col_test:1;
		uint32_t sel_1000:1;
		uint32_t res2:6;
#else
		uint32_t res2:6;
		uint32_t sel_1000:1;
		uint32_t col_test:1;
		uint32_t duplex:1;
		uint32_t restart_an:1;
		uint32_t isolate:1;
		uint32_t pwr_down:1;
		uint32_t an_enable:1;
		uint32_t sel_10_100:1;
		uint32_t res1:1;
		uint32_t reset:1;
		uint32_t res0:16;
#endif
	} bits;
} pcs_ctrl_t, *p_pcs_ctrl_t;

typedef union _pcs_stat_t {
	uint32_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:23;
		uint32_t ext_stat:1;
		uint32_t res1:2;
		uint32_t an_complete:1;
		uint32_t remote_fault:1;
		uint32_t an_able:1;
		uint32_t link_stat:1;
		uint32_t jabber_detect:1;
		uint32_t ext_cap:1;
#else
		uint32_t ext_cap:1;
		uint32_t jabber_detect:1;
		uint32_t link_stat:1;
		uint32_t an_able:1;
		uint32_t remote_fault:1;
		uint32_t an_complete:1;
		uint32_t res1:2;
		uint32_t ext_stat:1;
		uint32_t res0:23;
#endif
	} bits;
} pcs_stat_t, *p_pcs_stat_t;

typedef union _pcs_anar_t {
	uint32_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:16;
		uint32_t next_page:1;
		uint32_t ack:1;
		uint32_t remore_fault:2;
		uint32_t res1:3;
		uint32_t asm_pause:1;
		uint32_t pause:1;
		uint32_t half_duplex:1;
		uint32_t full_duplex:1;
		uint32_t res2:5;
#else
		uint32_t res2:5;
		uint32_t full_duplex:1;
		uint32_t half_duplex:1;
		uint32_t pause:1;
		uint32_t asm_pause:1;
		uint32_t res1:3;
		uint32_t remore_fault:2;
		uint32_t ack:1;
		uint32_t next_page:1;
		uint32_t res0:16;
#endif
	} bits;
} pcs_anar_t, *p_pcs_anar_t;

typedef union _pcs_cfg_t {
	uint32_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:26;
		uint32_t override_10ms_timer:1;
		uint32_t jitter_study:2;
		uint32_t sig_det_a_low:1;
		uint32_t sig_det_override:1;
		uint32_t enable:1;
#else
		uint32_t enable:1;
		uint32_t sig_det_override:1;
		uint32_t sig_det_a_low:1;
		uint32_t jitter_study:2;
		uint32_t override_10ms_timer:1;
		uint32_t res0:26;
#endif
	} bits;
} pcs_cfg_t, *p_pcs_cfg_t;

typedef union _pcs_stat_mc_t {
	uint32_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res2:2;
		uint32_t lnk_dwn_ni:1;
		uint32_t lnk_dwn_wc:1;
		uint32_t lnk_dwn_ls:1;
		uint32_t lnk_dwn_nc:1;
		uint32_t lnk_dwn_ser:1;
		uint32_t lnk_loss_bc:1;
		uint32_t res1:1;
		uint32_t loss_sd:1;
		uint32_t lnk_loss_sync:1;
		uint32_t lnk_loss_c:1;
		uint32_t res0:3;
		uint32_t link_cfg_stat:4;
		uint32_t seq_detc_stat:2;
		uint32_t word_sync:3;
		uint32_t rx_ctrl:4;
		uint32_t tx_ctrl:4;
#else
		uint32_t tx_ctrl:4;
		uint32_t rx_ctrl:4;
		uint32_t word_sync:3;
		uint32_t seq_detc_stat:2;
		uint32_t link_cfg_stat:4;
		uint32_t res0:3;
		uint32_t lnk_loss_c:1;
		uint32_t lnk_loss_sync:1;
		uint32_t loss_sd:1;
		uint32_t res1:1;
		uint32_t lnk_loss_bc:1;
		uint32_t lnk_dwn_ser:1;
		uint32_t lnk_dwn_nc:1;
		uint32_t lnk_dwn_ls:1;
		uint32_t lnk_dwn_wc:1;
		uint32_t lnk_dwn_ni:1;
		uint32_t res2:2;
#endif
	} bits;
} pcs_stat_mc_t, *p_pcs_stat_mc_t;

typedef union _dp_mode_t {
	uint32_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:30;
		uint32_t mii_serdes:1;
		uint32_t res1:1;
#else
		uint32_t res1:1;
		uint32_t mii_serdes:1;
		uint32_t res0:30;
#endif
	} bits;
} dp_mode_t, *p_dp_mode_t;

typedef union _serdes_ctrl_t {
	uint32_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint32_t res0:29;
		uint32_t lockref:1;
		uint32_t ensyncdet:1;
		uint32_t loopback:1;
#else
		uint32_t loopback:1;
		uint32_t ensyncdet:1;
		uint32_t lockref:1;
		uint32_t res0:29;
#endif
	} bits;
} serdes_ctrl_t, *p_serdes_ctrl_t;

typedef struct _pcs_t {
	pcs_ctrl_t control;
	pcs_stat_t status;
	pcs_anar_t anar;
	pcs_anar_t anlpar;
	pcs_cfg_t config;
	pcs_stat_mc_t state_mch;
	uint32_t int_status;
	uint32_t res0[13];
	dp_mode_t dp_mode;
	serdes_ctrl_t serdes_ctrl;
	uint32_t shared_output_sel;
	uint32_t serdes_state;
	uint32_t pcs_pkt_cntr;
} pcs_t, p_pcs_t;

typedef union _vms_stc_t {
	uint8_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint8_t res0:3;
		uint8_t bypass:2;
		uint8_t cipher:1;
		uint8_t busy:1;
		uint8_t drdy:1;
#else
		uint8_t drdy:1;
		uint8_t busy:1;
		uint8_t cipher:1;
		uint8_t bypass:2;
		uint8_t res0:3;
#endif
	} bits;
} vms_stc_t, *p_vms_stc_t;

typedef union _vms_mode_t {
	uint8_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint8_t res1:1;
		uint8_t encrypt:1;
		uint8_t res0:3;
		uint8_t key:3;
#else
		uint8_t key:3;
		uint8_t res0:3;
		uint8_t encrypt:1;
		uint8_t res1:1;
#endif
	} bits;
} vms_mode_t, *p_vms_mode_t;

typedef union _vms_rst_t {
	uint8_t value;
	struct  {
#ifdef _BIT_FIELDS_HTOL
		uint8_t res0:4;
		uint8_t iv:1;
		uint8_t key_cache:1;
		uint8_t stc_mode:1;
		uint8_t des_io:1;
#else
		uint8_t des_io:1;
		uint8_t stc_mode:1;
		uint8_t key_cache:1;
		uint8_t iv:1;
		uint8_t res0:4;
#endif
	} bits;
} vms_rst_t, *p_vms_rst_t;

typedef struct _vms_t {
	uint32_t data_io;
	vms_stc_t status;
	vms_mode_t mode;
	uint8_t rand_reg;
	vms_rst_t reset;
	uint32_t iv;
	uint32_t res1;
	uint32_t key[4];
} vms_t, *p_vms_t;

typedef struct _ce_regs_t{
	global_t global;
	uint32_t res0[997];
	tx_dma_t tx_dma;
	uint32_t res1[1976];
	rx_dma_t rx_dma;
	uint32_t res2[2];
	hp_t hp;
	uint32_t res3[24];
        rx_dmaplus_t rx_dmaplus;
	uint32_t res4[1903];
	mac_t mac;
	uint32_t res5[11];
	mif_t mif;
	uint32_t res6[2936];
	pcs_t pcs;
	uint32_t res7[252903];
	uchar_t promp[524288];
	uchar_t secondary[524287];

	kmutex_t vir_ce_lock;
	void *cep;

} ce_regs_t, *p_ce_regs_t;

typedef union _ce_tdes0_t{
	uint64_t value;
	struct {
#ifdef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t res0:30;
			uint32_t no_crc:1;
			uint32_t int_me:1;
#else
			uint32_t int_me:1;
			uint32_t no_crc:1;
			uint32_t res0:30;
#endif
		} hw;
#endif
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t fs:1;
			uint32_t ls:1;
			uint32_t cs_en:1;
			uint32_t cs_off:8;
			uint32_t cs_s_off:6;
			uint32_t mbz:1;
			uint32_t tbs:14;
#else
			uint32_t tbs:14;
			uint32_t mbz:1;
			uint32_t cs_s_off:6;
			uint32_t cs_off:8;
			uint32_t cs_en:1;
			uint32_t ls:1;
			uint32_t fs:1;
#endif
		} lw;
#ifndef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t res0:30;
			uint32_t no_crc:1;
			uint32_t int_me:1;
#else
			uint32_t int_me:1;
			uint32_t no_crc:1;
			uint32_t res0:30;
#endif
		} hw;
#endif
	} bits;
} ce_tdes0_t, *p_ce_tdes0_t;

typedef struct _tx_desc_t {
	ce_tdes0_t tdes0;
	uint64_t tdes1;
} tx_desc_t, *p_tx_desc_t;

typedef union _rbdes0_t{
	uint64_t value;
	struct {
#ifdef _BIG_ENDIAN
		uint32_t hw;
#endif
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t res0:18;
			uint32_t index:14;
#else
			uint32_t index:14;
			uint32_t res0:18;
#endif
		} lw;
#ifndef _BIG_ENDIAN
		uint32_t hw;
#endif
	} bits;
} rbdes0_t, *p_rbdes0_t;

typedef struct _rx_b_desc_t {
	rbdes0_t rdes0;
	uint64_t rdes1;
} rx_b_desc_t, *p_rx_b_desc_t;

typedef union _rcdes0_t {
	uint64_t value;
	struct {
#ifdef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t type:2;
			uint32_t rel_hdr:1;
			uint32_t rel_data:1;
			uint32_t rel_flow:1;
			uint32_t split_pkt:1;
			uint32_t rel_nxt:1;
			uint32_t skip:2;
			uint32_t data_index:14;
			uint32_t data_offset:9;
#else
			uint32_t data_offset:9;
			uint32_t data_index:14;
			uint32_t skip:2;
			uint32_t rel_nxt:1;
			uint32_t split_pkt:1;
			uint32_t rel_flow:1;
			uint32_t rel_data:1;
			uint32_t rel_hdr:1;
			uint32_t type:2;
#endif
		} hw;
#endif
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t data_offset:5;
			uint32_t data_size:14;
			uint32_t res0:13;
#else
			uint32_t res0:13;
			uint32_t data_size:14;
			uint32_t data_offset:5;
#endif
		} lw;
#ifndef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t type:2;
			uint32_t rel_hdr:1;
			uint32_t rel_data:1;
			uint32_t rel_flow:1;
			uint32_t split_pkt:1;
			uint32_t rel_nxt:1;
			uint32_t skip:2;
			uint32_t data_index:14;
			uint32_t data_offset:9;
#else
			uint32_t data_offset:9;
			uint32_t data_index:14;
			uint32_t skip:2;
			uint32_t rel_nxt:1;
			uint32_t split_pkt:1;
			uint32_t rel_flow:1;
			uint32_t rel_data:1;
			uint32_t rel_hdr:1;
			uint32_t type:2;
#endif
		} hw;
#endif
	} bits;
} rcdes0_t, *p_rcdes0_t;

typedef union _rcdes1_t {
	uint64_t value;
	struct {
#ifdef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t hdr_index:14;
			uint32_t hdr_offset:6;
			uint32_t hdr_size:9;
			uint32_t nxt_index:3;
#else
			uint32_t nxt_index:3;
			uint32_t hdr_size:9;
			uint32_t hdr_offset:6;
			uint32_t hdr_index:14;
#endif
		} hw;
#endif
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t nxt_index:11;
			uint32_t res0:21;
#else
			uint32_t res0:21;
			uint32_t nxt_index:11;
#endif
		} lw;
#ifndef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t hdr_index:14;
			uint32_t hdr_offset:6;
			uint32_t hdr_size:9;
			uint32_t nxt_index:3;
#else
			uint32_t nxt_index:3;
			uint32_t hdr_size:9;
			uint32_t hdr_offset:6;
			uint32_t hdr_index:14;
#endif
		} hw;
#endif
	} bits;
} rcdes1_t, *p_rcdes1_t;

typedef union _rcdes2_t {
	uint64_t value;
	struct {
#ifdef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t sap:16;
			uint32_t l3_head_off:6;
			uint32_t ecn_pkt:1;
			uint32_t load_bal:6;
			uint32_t res0:3;
#else
			uint32_t res0:3;
			uint32_t load_bal:6;
			uint32_t ecn_pkt:1;
			uint32_t l3_head_off:6;
			uint32_t sap:16;
#endif
		} hw;
#endif
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t res0:2;
			uint32_t no_assist:1;
			uint32_t force_fla:1;
			uint32_t opcode:3;
			uint32_t flowid:6;
			uint32_t cs_start_off:7;
			uint32_t res1:9;
			uint32_t jhs_enable:1;
			uint32_t jumbo_pkt:1;
			uint32_t small_pkt:1;
#else
			uint32_t small_pkt:1;
			uint32_t jumbo_pkt:1;
			uint32_t jhs_enable:1;
			uint32_t res1:9;
			uint32_t cs_start_off:7;
			uint32_t flowid:6;
			uint32_t opcode:3;
			uint32_t force_fla:1;
			uint32_t no_assist:1;
			uint32_t res0:2;
#endif
		} lw;
#ifndef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t sap:16;
			uint32_t l3_head_off:6;
			uint32_t ecn_pkt:1;
			uint32_t load_bal:6;
			uint32_t res0:3;
#else
			uint32_t res0:3;
			uint32_t load_bal:6;
			uint32_t ecn_pkt:1;
			uint32_t l3_head_off:6;
			uint32_t sap:16;
#endif
		} hw;
#endif
	} bits;
} rcdes2_t, *p_rcdes2_t;

typedef union _rcdes3_t {
	uint64_t value;
	struct {
#ifdef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t len_mismatch:1;
			uint32_t bad:1;
			uint32_t res0:1;
			uint32_t hash_pass:1;
			uint32_t hash_value:16;
			uint32_t zero:1;
			uint32_t res1:9;
			uint32_t pa_match:2;
#else
			uint32_t pa_match:2;
			uint32_t res1:9;
			uint32_t zero:1;
			uint32_t hash_value:16;
			uint32_t hash_pass:1;
			uint32_t res0:1;
			uint32_t bad:1;
			uint32_t len_mismatch:1;
#endif
		} hw;
#endif
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t pa_match:2;
			uint32_t pkt_len:14;
			uint32_t tcp_cs:16;
#else
			uint32_t tcp_cs:16;
			uint32_t pkt_len:14;
			uint32_t pa_match:2;
#endif
		} lw;
#ifndef _BIG_ENDIAN
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t len_mismatch:1;
			uint32_t bad:1;
			uint32_t res0:1;
			uint32_t hash_pass:1;
			uint32_t hash_value:16;
			uint32_t zero:1;
			uint32_t res1:9;
			uint32_t pa_match:2;
#else
			uint32_t pa_match:2;
			uint32_t res1:9;
			uint32_t zero:1;
			uint32_t hash_value:16;
			uint32_t hash_pass:1;
			uint32_t res0:1;
			uint32_t bad:1;
			uint32_t len_mismatch:1;
#endif
		} hw;
#endif
	} bits;
} rcdes3_t, *p_rcdes3_t;

typedef struct _rx_c_desc_t {
	rcdes0_t rdes0;
	rcdes1_t rdes1;
	rcdes2_t rdes2;
	rcdes3_t rdes3;
} rx_c_desc_t, *p_rx_c_desc_t;

typedef struct _hp_inst_t {
	union {
		uint32_t value;
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t mask:16;
			uint32_t val:16;
#else
			uint32_t val:16;
			uint32_t mask:16;
#endif
		} bits;
	} hw;
	union {
		uint32_t value;
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t op:2;
			uint32_t soff:7;
			uint32_t snext:5;
			uint32_t foff:7;
			uint32_t fnext:5;
			uint32_t outop:4;
			uint32_t outarg:2;
#else
			uint32_t outarg:2;
			uint32_t outop:4;
			uint32_t fnext:5;
			uint32_t foff:7;
			uint32_t snext:5;
			uint32_t soff:7;
			uint32_t op:2;
#endif
		} bits;
	} mw;
	union {
		uint32_t value;
		struct {
#ifdef _BIT_FIELDS_HTOL
			uint32_t outarg:10;
			uint32_t outenab:2;
			uint32_t outshift:4;
			uint32_t outmask:16;
#else
			uint32_t outmask:16;
			uint32_t outshift:4;
			uint32_t outenab:2;
			uint32_t outarg:10;
#endif
		} bits;
	} lw;
} hp_inst_t, *p_hp_inst_t;

/*
 * Restore to default packing.
 */
#pragma pack()

#ifdef _KERNEL
typedef struct _int_regs_t {
	struct _ce_t *cep;
	int int_line;
	p_glob_rstat_t status;	
	p_glob_rstat_t mask;	
	p_glob_rstat_t sel_clr_mask;
	p_glob_rstat_t status_alias;
	uint64_t *comp_pp;
	uint32_t *comp_head;
	uint32_t *comp_tail;
} int_regs_t, *p_int_regs_t;

typedef struct _dev_regs_t {
	ddi_acc_handle_t ce_regh;
	p_ce_regs_t ce_regp;
#ifdef TX_WB_WORKAROUND
	etx_cfg_t etx_cfg;
#endif
	unsigned char *ce_romp;		/* fcode rom pointer */
	ddi_acc_handle_t ce_romh;	/* rom handle */
	ddi_acc_handle_t ce_pciregh;
	p_pci_cfg_t ce_pciregp;
	uint32_t int_cnt;
	int_regs_t int_regs[4];
} dev_regs_t, *p_dev_regs_t;

/*
 * Soft copy of key device registers, this will help avoid
 * pio's to access the device to get it's configuration
 * state.
 */
typedef struct _soft_regs_t {
	uint32_t intr_mask;     /* Soft copy of interrupt mask */
	uint32_t etx_cfg;
	uint32_t erx_cfg;
	uint32_t tx_mac_cfg;
	uint32_t rx_mac_cfg;
	uint32_t mif_cfg;
	uint32_t mif_int_mask;
	mblk_t *filter_msg;
} soft_regs_t, *p_soft_regs_t;

#define FILTER_M_CTL 0xDCEF1
#define HASH_BITS 8
#define NMCFILTER_BITS (1 << HASH_BITS)
#define HASH_REG_WIDTH 16
#define BROADCAST_HASH_WORD 0x0f
#define BROADCAST_HASH_BIT 0x8000

typedef struct _filter_msg_t {
        int     filter_cmd;              /* M_CTL message magic */
} filter_msg_t, *p_filter_msg_t;
#endif

#ifdef	__cplusplus
}
#endif

#endif
