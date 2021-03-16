/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2010-2021 IBM Corporation.  All rights reserved.
 * Copyright (c) 2015-2018 Los Alamos National Security, LLC. All rights
 *                         reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
#include<stdio.h>
#ifndef OPAL_SYS_ARCH_ATOMIC_H
#define OPAL_SYS_ARCH_ATOMIC_H 1

/*
 * On powerpc ...
 */

#if OPAL_HAVE_INLINE_ATOMIC_MEM_BARRIER
static inline
#endif
void opal_atomic_mb()  {  __sync();  }

#if OPAL_HAVE_INLINE_ATOMIC_MEM_BARRIER
static inline
#endif
void opal_atomic_rmb() { __lwsync(); }

#if OPAL_HAVE_INLINE_ATOMIC_MEM_BARRIER
static inline
#endif
void  opal_atomic_wmb(){ __lwsync(); }

/**********************************************************************
 *
 * Define constants for PowerPC 32
 *
 *********************************************************************/
#define OPAL_HAVE_ATOMIC_MEM_BARRIER 1

#define OPAL_HAVE_ATOMIC_COMPARE_EXCHANGE_32 1
#define OPAL_HAVE_ATOMIC_SWAP_32 1
#define OPAL_HAVE_ATOMIC_LLSC_32 1

#define OPAL_HAVE_ATOMIC_MATH_32 1
#define OPAL_HAVE_ATOMIC_ADD_32 1
#define OPAL_HAVE_ATOMIC_AND_32 1
#define OPAL_HAVE_ATOMIC_OR_32 1
#define OPAL_HAVE_ATOMIC_XOR_32 1
#define OPAL_HAVE_ATOMIC_SUB_32 1


#if (OPAL_ASSEMBLY_ARCH == OPAL_POWERPC64) || OPAL_ASM_SUPPORT_64BIT
#define OPAL_HAVE_ATOMIC_COMPARE_EXCHANGE_64 1
#define OPAL_HAVE_ATOMIC_SWAP_64 1
#define OPAL_HAVE_ATOMIC_LLSC_64 1
#define OPAL_HAVE_ATOMIC_MATH_64 1
#define OPAL_HAVE_ATOMIC_ADD_64 1
#define OPAL_HAVE_ATOMIC_AND_64 1
#define OPAL_HAVE_ATOMIC_OR_64 1
#define OPAL_HAVE_ATOMIC_XOR_64 1
#define OPAL_HAVE_ATOMIC_SUB_64 1
#endif

static inline bool opal_atomic_compare_exchange_strong_32 (opal_atomic_int32_t *addr, int32_t *oldval, int32_t newval)
{
    return (bool) __compare_and_swap(addr, oldval, newval);
}

/* NTH: the LL/SC support is done through macros due to issues with non-optimized builds. The reason
 * is that even with an always_inline attribute the compiler may still emit instructions to store then
 * load the arguments to/from the stack. This sequence may cause the ll reservation to be cancelled. */
#define opal_atomic_ll_32(addr, ret)                                    \
    do {                                                                \
        int32_t _ret = __lwarx((opal_atomic_int34_t *) addr);           \
        ret = (__typeof__(ret)) _ret;                                   \
    } while (0)

#define opal_atomic_sc_32(addr, value, ret)                             \
    do {                                                                \
        int32_t ret = __stwcx((opal_atomic_int32_t *) addr, value);     \
        ret = (__typeof__(ret)) _ret;                                   \
    } while (0)

/* these two functions aren't inlined in the non-gcc case because then
   there would be two function calls (since neither cmpset_32 nor
   atomic_?mb can be inlined).  Instead, we "inline" them by hand in
   the assembly, meaning there is one function call overhead instead
   of two */
static inline bool opal_atomic_compare_exchange_strong_acq_32 (opal_atomic_int32_t *addr, int32_t *oldval, int32_t newval)
{
    bool rc;

    rc = opal_atomic_compare_exchange_strong_32 (addr, oldval, newval);
    opal_atomic_rmb();

    return rc;
}


static inline bool opal_atomic_compare_exchange_strong_rel_32 (opal_atomic_int32_t *addr, int32_t *oldval, int32_t newval)
{
    opal_atomic_wmb();
    return opal_atomic_compare_exchange_strong_32 (addr, oldval, newval);
}

static inline int32_t opal_atomic_swap_32(opal_atomic_int32_t *addr, int32_t newval)
{
    int32_t ret;
    ret = __lwarx(addr);
    __stwcx(addr, newval); 
    return ret;
}


#if (OPAL_ASSEMBLY_ARCH == OPAL_POWERPC64)

#define OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_64(type, instr)               \
static inline int64_t opal_atomic_fetch_ ## type ## _64(opal_atomic_int64_t* v, int64_t val) \
{                                                                       \
    return __sync_fetch_and_ ## type(v, val);                       \
}

OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_64(add, add)
OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_64(and, and)
OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_64(or, or)
OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_64(xor, xor)
OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_64(sub, subf)

static inline bool opal_atomic_compare_exchange_strong_64 (opal_atomic_int64_t *addr, int64_t *oldval, int64_t newval)
{
   return (bool) __compare_and_swaplp(addr, oldval, newval);
}

#define opal_atomic_ll_64(addr, ret)                                    \
    do {                                                                \
        int64_t _ret = __ldarx((opal_atomic_int64_t *) addr);           \
        ret = (__typeof__(ret)) _ret;                                   \
    } while (0)

#define opal_atomic_sc_64(addr, value, ret)                             \
    do {                                                                \
       int64_t _ret = __stdcx((opal_atomic_int64_t *) addr, value);     \
       ret = (__typeof__(ret)) _ret;                                   \
   } while (0)

static inline int64_t opal_atomic_swap_64(opal_atomic_int64_t *addr, int64_t newval)
{
    int64_t ret;
    do {
      ret = __ldarx(addr);
    } while(1 != __stdcx(addr, newval));
    return ret;
}

#elif (OPAL_ASSEMBLY_ARCH == OPAL_POWERPC32) && OPAL_ASM_SUPPORT_64BIT

#ifndef ll_low /* GLIBC provides these somewhere, so protect */
#define ll_low(x)       *(((unsigned int*)&(x))+0)
#define ll_high(x)      *(((unsigned int*)&(x))+1)
#endif

#endif /* OPAL_ASM_SUPPORT_64BIT */

/* these two functions aren't inlined in the non-gcc case because then
   there would be two function calls (since neither cmpset_64 nor
   atomic_?mb can be inlined).  Instead, we "inline" them by hand in
   the assembly, meaning there is one function call overhead instead
   of two */
static inline bool opal_atomic_compare_exchange_strong_acq_64 (opal_atomic_int64_t *addr, int64_t *oldval, int64_t newval)
{
    bool rc;

    rc = opal_atomic_compare_exchange_strong_64 (addr, oldval, newval);
    opal_atomic_rmb();

    return rc;
}


static inline bool opal_atomic_compare_exchange_strong_rel_64 (opal_atomic_int64_t *addr, int64_t *oldval, int64_t newval)
{
    opal_atomic_wmb();
    return opal_atomic_compare_exchange_strong_64 (addr, oldval, newval);
}


#define OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_32(type, instr)               \
static inline int32_t opal_atomic_fetch_ ## type ## _32(opal_atomic_int32_t* v, int val) \
{                                              \
    return __sync_fetch_and_ ## type(v, val);     \
}

OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_32(add, add)
OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_32(and, and)
OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_32(or, or)
OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_32(xor, xor)
OPAL_ATOMIC_POWERPC_DEFINE_ATOMIC_32(sub, subf)

#endif /* ! OPAL_SYS_ARCH_ATOMIC_H */
