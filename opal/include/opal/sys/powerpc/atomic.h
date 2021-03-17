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
//#include<stdio.h>
#if !defined(OPAL_SYS_ARCH_ATOMIC_LLSC_H)
#define OPAL_SYS_ARCH_ATOMIC_LLSC_H

#define OPAL_HAVE_ATOMIC_LLSC_64 1
#define OPAL_HAVE_ATOMIC_LLSC_32 1

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

/* NTH: the LL/SC support is done through macros due to issues with non-optimized builds. The reason
 * is that even with an always_inline attribute the compiler may still emit instructions to store then
 * load the arguments to/from the stack. This sequence may cause the ll reservation to be cancelled. */
#define opal_atomic_ll_32(addr, ret)                                    \
    do {                                                                \
        int32_t _ret = __lwarx((opal_atomic_int34_t *) addr);           \
        ret = (__typeof__(ret)) _ret;                                   \
       /* __fence();*/ \
    } while (0)

#define opal_atomic_sc_32(addr, value, ret)                             \
    do {                                                                \
        int32_t ret = __stwcx((opal_atomic_int32_t *) addr, value);     \
        ret = (__typeof__(ret)) _ret;                                   \
        /*__fence(); */\
    } while (0)

#endif /* ! OPAL_SYS_ARCH_ATOMIC_LLSC_H */
