/*
 * Copyright (c) 1993, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef _SYS_ARCHSYSTM_H
#define	_SYS_ARCHSYSTM_H

#pragma ident	"@(#)archsystm.h	1.40	11/02/11 SMI"

/*
 * A selection of ISA-dependent interfaces
 */

#include <vm/seg_enum.h>
#include <vm/page.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _KERNEL

extern greg_t getfp(void);
extern int getpil(void);

extern ulong_t getcr0(void);
extern void setcr0(ulong_t);
extern ulong_t getcr2(void);
extern void setcr8(ulong_t);
extern void iommu_cpu_nop(void);
extern void clflush_insn(caddr_t addr);
extern void mfence_insn(void);

#if defined(__i386)
extern uint16_t getgs(void);
extern void setgs(uint16_t);
#endif

extern void patch_xsave(void);

extern void sti(void);

extern void tenmicrosec(void);

extern void restore_int_flag(ulong_t);
extern void intr_restore(ulong_t);
extern ulong_t clear_int_flag(void);
extern ulong_t intr_clear(void);
extern ulong_t getflags(void);
extern int interrupts_enabled(void);

extern void int3(void);
extern void int18(void);
extern void int20(void);
extern void int_cmci(void);

#if defined(__amd64)
extern void sys_syscall();
extern void sys_syscall32();
extern void sys_lcall32();
extern void sys_syscall_int();
extern void brand_sys_syscall();
extern void brand_sys_syscall32();
extern void brand_sys_syscall_int();
#elif defined(__i386)
extern void sys_call();
extern void brand_sys_call();
#endif
extern void sys_sysenter();
extern void _sys_sysenter_post_swapgs();
extern void brand_sys_sysenter();
extern void _brand_sys_sysenter_post_swapgs();

extern void dosyscall(void);

extern void bind_hwcap(void);

extern uint8_t inb(int port);
extern uint16_t inw(int port);
extern uint32_t inl(int port);
extern void repinsb(int port, uint8_t *addr, int count);
extern void repinsw(int port, uint16_t *addr, int count);
extern void repinsd(int port, uint32_t *addr, int count);
extern void outb(int port, uint8_t value);
extern void outw(int port, uint16_t value);
extern void outl(int port, uint32_t value);
extern void repoutsb(int port, uint8_t *addr, int count);
extern void repoutsw(int port, uint16_t *addr, int count);
extern void repoutsd(int port, uint32_t *addr, int count);

extern void pc_reset(void) __NORETURN;
extern void reset(void) __NORETURN;
extern int goany(void);

extern void setgregs(klwp_t *, gregset_t);
extern void getgregs(klwp_t *, gregset_t);
extern void setfpregs(klwp_t *, fpregset_t *);
extern void getfpregs(klwp_t *, fpregset_t *);

#if defined(_SYSCALL32_IMPL)
extern void getgregs32(klwp_t *, gregset32_t);
extern void setfpregs32(klwp_t *, fpregset32_t *);
extern void getfpregs32(klwp_t *, fpregset32_t *);
#endif

struct ucontext;
extern  void	xregs_clrptr(klwp_t *, struct ucontext *);
extern  int	xregs_hasptr(klwp_t *, struct ucontext *);
extern  caddr_t xregs_getptr(klwp_t *, struct ucontext *);
extern  void	xregs_setptr(klwp_t *, struct ucontext *, caddr_t);

#ifdef _SYSCALL32_IMPL
struct  ucontext32;
extern  void	xregs_clrptr32(klwp_t *, struct ucontext32 *);
extern  int	xregs_hasptr32(klwp_t *, struct ucontext32 *);
extern  caddr32_t xregs_getptr32(klwp_t *, struct ucontext32 *);
extern  void	xregs_setptr32(klwp_t *, struct ucontext32 *, caddr32_t);
#endif /* _SYSCALL32_IMPL */

extern  void	xregs_getfpregs(klwp_t *, caddr_t);
extern  void	xregs_get(klwp_t *, caddr_t);
extern  void	xregs_setfpregs(klwp_t *, caddr_t);
extern  void	xregs_set(klwp_t *, caddr_t);
extern  int	xregs_getsize(struct proc *);
extern  int	xregs_isvalid(caddr_t);

struct fpu_ctx;

extern void fp_free(struct fpu_ctx *, int);
extern void fp_save(struct fpu_ctx *);
extern void fp_restore(struct fpu_ctx *);

extern int fpu_pentium_fdivbug;

extern void sep_save(void *);
extern void sep_restore(void *);

extern void brand_interpositioning_enable(void);
extern void brand_interpositioning_disable(void);

struct regs;

extern int instr_size(struct regs *, caddr_t *, enum seg_rw);

extern void realsigprof(int, int);

extern int enable_cbcp; /* patchable in /etc/system */

extern uint_t cpu_hwcap_flags;
extern uint_t cpu_freq;
extern uint64_t cpu_freq_hz;

#ifdef __ia64
extern caddr_t ia64devmap(pfn_t, pgcnt_t, uint_t);
#else
extern caddr_t i86devmap(pfn_t, pgcnt_t, uint_t);
#endif
extern page_t *page_numtopp_alloc(pfn_t pfnum);

extern void hwblkclr(void *, size_t);
extern void hwblkpagecopy(const void *, void *);

extern void (*kcpc_hw_enable_cpc_intr)(void);

extern void setup_mca(void);
extern void setup_mtrr(void);
extern void patch_tsc(void);
extern void patch_tsc_read(int);
#if defined(__amd64)
extern void patch_memops(uint_t);
#endif	/* defined(__amd64) */
extern void setup_xfem(void);

extern user_desc_t *cpu_get_gdt(void);

extern void switch_sp_and_call(void *, void (*)(uint_t, uint_t), uint_t,
    uint_t);

/*
 * Warning: these routines do -not- use normal calling conventions!
 */
extern void setup_121_andcall(void (*)(ulong_t), ulong_t);
extern void enable_big_page_support(ulong_t);
extern void enable_pae(ulong_t);

extern hrtime_t (*gethrtimef)(void);
extern hrtime_t (*gethrtimeunscaledf)(void);
extern void (*scalehrtimef)(hrtime_t *);
extern void (*gethrestimef)(timestruc_t *);

extern void av_dispatch_softvect(uint_t);
extern void av_dispatch_autovect(uint_t);
extern uint_t bsrw_insn(uint16_t);

#endif /* _KERNEL */

#ifdef __cplusplus
}
#endif

#endif	/* _SYS_ARCHSYSTM_H */
