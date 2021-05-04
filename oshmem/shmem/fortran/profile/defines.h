/*
 * Copyright (c) 2014-2016 Mellanox Technologies, Inc.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef OSHMEM_FORTRAN_PROFILE_DEFINES_H
#define OSHMEM_FORTRAN_PROFILE_DEFINES_H
/*
 * This file is included in the top directory only if
 * profiling is required. Once profiling is required,
 * this file will replace all shmem_* symbols with
 * pshmem_* symbols
 */

#define SHMEM_INIT   PSHMEM_INIT
#define shmem_init_  pshmem_init_
#define shmem_init__ pshmem_init__

#define START_PES   PSTART_PES
#define start_pes_  pstart_pes_
#define start_pes__ pstart_pes__

#define SHMEM_GLOBAL_EXIT   PSHMEM_GLOBAL_EXIT
#define shmem_global_exit_  pshmem_global_exit_
#define shmem_global_exit__ pshmem_global_exit__

#define SHMEM_MY_PE   PSHMEM_MY_PE
#define shmem_my_pe_  pshmem_my_pe_
#define shmem_my_pe__ pshmem_my_pe__

#define MY_PE   PMY_PE
#define my_pe_  pmy_pe_
#define my_pe__ pmy_pe__
#define _my_pe_ p_my_pe_

#define SHMEM_N_PES   PSHMEM_N_PES
#define shmem_n_pes_  pshmem_n_pes_
#define shmem_n_pes__ pshmem_n_pes__

#define NUM_PES   PNUM_PES
#define num_pes_  pnum_pes_
#define num_pes__ pnum_pes__

#define SHMEM_ADDR_ACCESSIBLE   PSHMEM_ADDR_ACCESSIBLE
#define shmem_addr_accessible_  pshmem_addr_accessible_
#define shmem_addr_accessible__ pshmem_addr_accessible__

#define SHMEM_INT2_AND_TO_ALL   PSHMEM_INT2_AND_TO_ALL
#define shmem_int2_and_to_all_  pshmem_int2_and_to_all_
#define shmem_int2_and_to_all__ pshmem_int2_and_to_all__

#define SHMEM_INT4_AND_TO_ALL   PSHMEM_INT4_AND_TO_ALL
#define shmem_int4_and_to_all_  pshmem_int4_and_to_all_
#define shmem_int4_and_to_all__ pshmem_int4_and_to_all__

#define SHMEM_INT8_AND_TO_ALL   PSHMEM_INT8_AND_TO_ALL
#define shmem_int8_and_to_all_  pshmem_int8_and_to_all_
#define shmem_int8_and_to_all__ pshmem_int8_and_to_all__

#define SHMEM_BARRIER_ALL   PSHMEM_BARRIER_ALL
#define shmem_barrier_all_  pshmem_barrier_all_
#define shmem_barrier_all__ pshmem_barrier_all__

#define SHMEM_BARRIER   PSHMEM_BARRIER
#define shmem_barrier_  pshmem_barrier_
#define shmem_barrier__ pshmem_barrier__

#define SHMEM_BROADCAST4   PSHMEM_BROADCAST4
#define shmem_broadcast4_  pshmem_broadcast4_
#define shmem_broadcast4__ pshmem_broadcast4__

#define SHMEM_BROADCAST8   PSHMEM_BROADCAST8
#define shmem_broadcast8_  pshmem_broadcast8_
#define shmem_broadcast8__ pshmem_broadcast8__

#define SHMEM_BROADCAST32   PSHMEM_BROADCAST32
#define shmem_broadcast32_  pshmem_broadcast32_
#define shmem_broadcast32__ pshmem_broadcast32__

#define SHMEM_BROADCAST64   PSHMEM_BROADCAST64
#define shmem_broadcast64_  pshmem_broadcast64_
#define shmem_broadcast64__ pshmem_broadcast64__

#define SHMEM_ALLTOALL32   PSHMEM_ALLTOALL32
#define shmem_alltoall32_  pshmem_alltoall32_
#define shmem_alltoall32__ pshmem_alltoall32__

#define SHMEM_ALLTOALL64   PSHMEM_ALLTOALL64
#define shmem_alltoall64_  pshmem_alltoall64_
#define shmem_alltoall64__ pshmem_alltoall64__

#define SHMEM_ALLTOALLS32   PSHMEM_ALLTOALLS32
#define shmem_alltoalls32_  pshmem_alltoalls32_
#define shmem_alltoalls32__ pshmem_alltoalls32__

#define SHMEM_ALLTOALLS64   PSHMEM_ALLTOALLS64
#define shmem_alltoalls64_  pshmem_alltoalls64_
#define shmem_alltoalls64__ pshmem_alltoalls64__

#define SHMEM_SET_CACHE_INV   PSHMEM_SET_CACHE_INV
#define shmem_set_cache_inv_  pshmem_set_cache_inv_
#define shmem_set_cache_inv__ pshmem_set_cache_inv__

#define SHMEM_SET_CACHE_LINE_INV   PSHMEM_SET_CACHE_LINE_INV
#define shmem_set_cache_line_inv_  pshmem_set_cache_line_inv_
#define shmem_set_cache_line_inv__ pshmem_set_cache_line_inv__

#define SHMEM_CLEAR_CACHE_INV   PSHMEM_CLEAR_CACHE_INV
#define shmem_clear_cache_inv_  pshmem_clear_cache_inv_
#define shmem_clear_cache_inv__ pshmem_clear_cache_inv__

#define SHMEM_CLEAR_CACHE_LINE_INV   PSHMEM_CLEAR_CACHE_LINE_INV
#define shmem_clear_cache_line_inv_  pshmem_clear_cache_line_inv_
#define shmem_clear_cache_line_inv__ pshmem_clear_cache_line_inv__

#define SHMEM_UDCFLUSH   PSHMEM_UDCFLUSH
#define shmem_udcflush_  pshmem_udcflush_
#define shmem_udcflush__ pshmem_udcflush__

#define SHMEM_UDCFLUSH_LINE   PSHMEM_UDCFLUSH_LINE
#define shmem_udcflush_line_  pshmem_udcflush_line_
#define shmem_udcflush_line__ pshmem_udcflush_line__

#define SHMEM_CHARACTER_GET   PSHMEM_CHARACTER_GET
#define shmem_character_get_  pshmem_character_get_
#define shmem_character_get__ pshmem_character_get__

#define SHMEM_CHARACTER_PUT   PSHMEM_CHARACTER_PUT
#define shmem_character_put_  pshmem_character_put_
#define shmem_character_put__ pshmem_character_put__

#define SHMEM_CHARACTER_PUT_NBI   PSHMEM_CHARACTER_PUT_NBI
#define shmem_character_put_nbi_  pshmem_character_put_nbi_
#define shmem_character_put_nbi__ pshmem_character_put_nbi__

#define SHMEM_COLLECT4   PSHMEM_COLLECT4
#define shmem_collect4_  pshmem_collect4_
#define shmem_collect4__ pshmem_collect4__

#define SHMEM_COLLECT8   PSHMEM_COLLECT8
#define shmem_collect8_  pshmem_collect8_
#define shmem_collect8__ pshmem_collect8__

#define SHMEM_COLLECT32   PSHMEM_COLLECT32
#define shmem_collect32_  pshmem_collect32_
#define shmem_collect32__ pshmem_collect32__

#define SHMEM_COLLECT64   PSHMEM_COLLECT64
#define shmem_collect64_  pshmem_collect64_
#define shmem_collect64__ pshmem_collect64__

#define SHMEM_FCOLLECT4   PSHMEM_FCOLLECT4
#define shmem_fcollect4_  pshmem_fcollect4_
#define shmem_fcollect4__ pshmem_fcollect4__

#define SHMEM_FCOLLECT8   PSHMEM_FCOLLECT8
#define shmem_fcollect8_  pshmem_fcollect8_
#define shmem_fcollect8__ pshmem_fcollect8__

#define SHMEM_FCOLLECT32   PSHMEM_FCOLLECT32
#define shmem_fcollect32_  pshmem_fcollect32_
#define shmem_fcollect32__ pshmem_fcollect32__

#define SHMEM_FCOLLECT64   PSHMEM_FCOLLECT64
#define shmem_fcollect64_  pshmem_fcollect64_
#define shmem_fcollect64__ pshmem_fcollect64__

#define SHMEM_COMPLEX_GET   PSHMEM_COMPLEX_GET
#define shmem_complex_get_  pshmem_complex_get_
#define shmem_complex_get__ pshmem_complex_get__

#define SHMEM_COMPLEX_IGET   PSHMEM_COMPLEX_IGET
#define shmem_complex_iget_  pshmem_complex_iget_
#define shmem_complex_iget__ pshmem_complex_iget__

#define SHMEM_COMPLEX_IPUT   PSHMEM_COMPLEX_IPUT
#define shmem_complex_iput_  pshmem_complex_iput_
#define shmem_complex_iput__ pshmem_complex_iput__

#define SHMEM_COMPLEX_PUT   PSHMEM_COMPLEX_PUT
#define shmem_complex_put_  pshmem_complex_put_
#define shmem_complex_put__ pshmem_complex_put__

#define SHMEM_COMPLEX_PUT_NBI   PSHMEM_COMPLEX_PUT_NBI
#define shmem_complex_put_nbi_  pshmem_complex_put_nbi_
#define shmem_complex_put_nbi__ pshmem_complex_put_nbi__

#define SHMEM_DOUBLE_GET   PSHMEM_DOUBLE_GET
#define shmem_double_get_  pshmem_double_get_
#define shmem_double_get__ pshmem_double_get__

#define SHMEM_DOUBLE_IGET   PSHMEM_DOUBLE_IGET
#define shmem_double_iget_  pshmem_double_iget_
#define shmem_double_iget__ pshmem_double_iget__

#define SHMEM_DOUBLE_IPUT   PSHMEM_DOUBLE_IPUT
#define shmem_double_iput_  pshmem_double_iput_
#define shmem_double_iput__ pshmem_double_iput__

#define SHMEM_DOUBLE_PUT   PSHMEM_DOUBLE_PUT
#define shmem_double_put_  pshmem_double_put_
#define shmem_double_put__ pshmem_double_put__

#define SHMEM_DOUBLE_PUT_NBI   PSHMEM_DOUBLE_PUT_NBI
#define shmem_double_put_nbi_  pshmem_double_put_nbi_
#define shmem_double_put_nbi__ pshmem_double_put_nbi__

#define SHMEM_FENCE   PSHMEM_FENCE
#define shmem_fence_  pshmem_fence_
#define shmem_fence__ pshmem_fence__

#define SHMEM_GET128   PSHMEM_GET128
#define shmem_get128_  pshmem_get128_
#define shmem_get128__ pshmem_get128__

#define SHMEM_GET32   PSHMEM_GET32
#define shmem_get32_  pshmem_get32_
#define shmem_get32__ pshmem_get32__

#define SHMEM_GET4   PSHMEM_GET4
#define shmem_get4_  pshmem_get4_
#define shmem_get4__ pshmem_get4__

#define SHMEM_GET64   PSHMEM_GET64
#define shmem_get64_  pshmem_get64_
#define shmem_get64__ pshmem_get64__

#define SHMEM_GET8   PSHMEM_GET8
#define shmem_get8_  pshmem_get8_
#define shmem_get8__ pshmem_get8__

#define SHMEM_GETMEM   PSHMEM_GETMEM
#define shmem_getmem_  pshmem_getmem_
#define shmem_getmem__ pshmem_getmem__

#define SHMEM_IGET128   PSHMEM_IGET128
#define shmem_iget128_  pshmem_iget128_
#define shmem_iget128__ pshmem_iget128__

#define SHMEM_IGET32   PSHMEM_IGET32
#define shmem_iget32_  pshmem_iget32_
#define shmem_iget32__ pshmem_iget32__

#define SHMEM_IGET4   PSHMEM_IGET4
#define shmem_iget4_  pshmem_iget4_
#define shmem_iget4__ pshmem_iget4__

#define SHMEM_IGET64   PSHMEM_IGET64
#define shmem_iget64_  pshmem_iget64_
#define shmem_iget64__ pshmem_iget64__

#define SHMEM_IGET8   PSHMEM_IGET8
#define shmem_iget8_  pshmem_iget8_
#define shmem_iget8__ pshmem_iget8__

#define SHMEM_GETMEM_NBI   PSHMEM_GETMEM_NBI
#define shmem_getmem_nbi_  pshmem_getmem_nbi_
#define shmem_getmem_nbi__ pshmem_getmem_nbi__

#define SHMEM_CHARACTER_GET_NBI   PSHMEM_CHARACTER_GET_NBI
#define shmem_character_get_nbi_  pshmem_character_get_nbi_
#define shmem_character_get_nbi__ pshmem_character_get_nbi__

#define SHMEM_COMPLEX_GET_NBI   PSHMEM_COMPLEX_GET_NBI
#define shmem_complex_get_nbi_  pshmem_complex_get_nbi_
#define shmem_complex_get_nbi__ pshmem_complex_get_nbi__

#define SHMEM_DOUBLE_GET_NBI   PSHMEM_DOUBLE_GET_NBI
#define shmem_double_get_nbi_  pshmem_double_get_nbi_
#define shmem_double_get_nbi__ pshmem_double_get_nbi__

#define SHMEM_INTEGER_GET_NBI   PSHMEM_INTEGER_GET_NBI
#define shmem_integer_get_nbi_  pshmem_integer_get_nbi_
#define shmem_integer_get_nbi__ pshmem_integer_get_nbi__

#define SHMEM_LOGICAL_GET_NBI   PSHMEM_LOGICAL_GET_NBI
#define shmem_logical_get_nbi_  pshmem_logical_get_nbi_
#define shmem_logical_get_nbi__ pshmem_logical_get_nbi__

#define SHMEM_REAL_GET_NBI   PSHMEM_REAL_GET_NBI
#define shmem_real_get_nbi_  pshmem_real_get_nbi_
#define shmem_real_get_nbi__ pshmem_real_get_nbi__

#define SHMEM_GET4_NBI   PSHMEM_GET4_NBI
#define shmem_get4_nbi_  pshmem_get4_nbi_
#define shmem_get4_nbi__ pshmem_get4_nbi__

#define SHMEM_GET8_NBI   PSHMEM_GET8_NBI
#define shmem_get8_nbi_  pshmem_get8_nbi_
#define shmem_get8_nbi__ pshmem_get8_nbi__

#define SHMEM_GET32_NBI   PSHMEM_GET32_NBI
#define shmem_get32_nbi_  pshmem_get32_nbi_
#define shmem_get32_nbi__ pshmem_get32_nbi__

#define SHMEM_GET64_NBI   PSHMEM_GET64_NBI
#define shmem_get64_nbi_  pshmem_get64_nbi_
#define shmem_get64_nbi__ pshmem_get64_nbi__

#define SHMEM_GET128_NBI   PSHMEM_GET128_NBI
#define shmem_get128_nbi_  pshmem_get128_nbi_
#define shmem_get128_nbi__ pshmem_get128_nbi__

#define SHMEM_PUTMEM_NBI   PSHMEM_PUTMEM_NBI
#define shmem_putmem_nbi_  pshmem_putmem_nbi_
#define shmem_putmem_nbi__ pshmem_putmem_nbi__

#define SHMEM_CHARACTER_PUT_NBI   PSHMEM_CHARACTER_PUT_NBI
#define shmem_character_put_nbi_  pshmem_character_put_nbi_
#define shmem_character_put_nbi__ pshmem_character_put_nbi__

#define SHMEM_COMPLEX_PUT_NBI   PSHMEM_COMPLEX_PUT_NBI
#define shmem_complex_put_nbi_  pshmem_complex_put_nbi_
#define shmem_complex_put_nbi__ pshmem_complex_put_nbi__

#define SHMEM_DOUBLE_PUT_NBI   PSHMEM_DOUBLE_PUT_NBI
#define shmem_double_put_nbi_  pshmem_double_put_nbi_
#define shmem_double_put_nbi__ pshmem_double_put_nbi__

#define SHMEM_INTEGER_PUT_NBI   PSHMEM_INTEGER_PUT_NBI
#define shmem_integer_put_nbi_  pshmem_integer_put_nbi_
#define shmem_integer_put_nbi__ pshmem_integer_put_nbi__

#define SHMEM_LOGICAL_PUT_NBI   PSHMEM_LOGICAL_PUT_NBI
#define shmem_logical_put_nbi_  pshmem_logical_put_nbi_
#define shmem_logical_put_nbi__ pshmem_logical_put_nbi__

#define SHMEM_REAL_PUT_NBI   PSHMEM_REAL_PUT_NBI
#define shmem_real_put_nbi_  pshmem_real_put_nbi_
#define shmem_real_put_nbi__ pshmem_real_put_nbi__

#define SHMEM_PUT4_NBI   PSHMEM_PUT4_NBI
#define shmem_put4_nbi_  pshmem_put4_nbi_
#define shmem_put4_nbi__ pshmem_put4_nbi__

#define SHMEM_PUT8_NBI   PSHMEM_PUT8_NBI
#define shmem_put8_nbi_  pshmem_put8_nbi_
#define shmem_put8_nbi__ pshmem_put8_nbi__

#define SHMEM_PUT32_NBI   PSHMEM_PUT32_NBI
#define shmem_put32_nbi_  pshmem_put32_nbi_
#define shmem_put32_nbi__ pshmem_put32_nbi__

#define SHMEM_PUT64_NBI   PSHMEM_PUT64_NBI
#define shmem_put64_nbi_  pshmem_put64_nbi_
#define shmem_put64_nbi__ pshmem_put64_nbi__

#define SHMEM_PUT128_NBI   PSHMEM_PUT128_NBI
#define shmem_put128_nbi_  pshmem_put128_nbi_
#define shmem_put128_nbi__ pshmem_put128_nbi__

#define SHMEM_INT4_ADD   PSHMEM_INT4_ADD
#define shmem_int4_add_  pshmem_int4_add_
#define shmem_int4_add__ pshmem_int4_add__

#define SHMEM_INT4_CSWAP   PSHMEM_INT4_CSWAP
#define shmem_int4_cswap_  pshmem_int4_cswap_
#define shmem_int4_cswap__ pshmem_int4_cswap__

#define SHMEM_INT4_FADD   PSHMEM_INT4_FADD
#define shmem_int4_fadd_  pshmem_int4_fadd_
#define shmem_int4_fadd__ pshmem_int4_fadd__

#define SHMEM_INT4_FETCH   PSHMEM_INT4_FETCH
#define shmem_int4_fetch_  pshmem_int4_fetch_
#define shmem_int4_fetch__ pshmem_int4_fetch__

#define SHMEM_INT4_FINC   PSHMEM_INT4_FINC
#define shmem_int4_finc_  pshmem_int4_finc_
#define shmem_int4_finc__ pshmem_int4_finc__

#define SHMEM_INT4_INC   PSHMEM_INT4_INC
#define shmem_int4_inc_  pshmem_int4_inc_
#define shmem_int4_inc__ pshmem_int4_inc__

#define SHMEM_INT4_SWAP   PSHMEM_INT4_SWAP
#define shmem_int4_swap_  pshmem_int4_swap_
#define shmem_int4_swap__ pshmem_int4_swap__

#define SHMEM_INT4_SET   PSHMEM_INT4_SET
#define shmem_int4_set_  pshmem_int4_set_
#define shmem_int4_set__ pshmem_int4_set__

#define SHMEM_INT4_WAIT   PSHMEM_INT4_WAIT
#define shmem_int4_wait_  pshmem_int4_wait_
#define shmem_int4_wait__ pshmem_int4_wait__

#define SHMEM_INT4_WAIT_UNTIL   PSHMEM_INT4_WAIT_UNTIL
#define shmem_int4_wait_until_  pshmem_int4_wait_until_
#define shmem_int4_wait_until__ pshmem_int4_wait_until__

#define SHMEM_INT8_ADD   PSHMEM_INT8_ADD
#define shmem_int8_add_  pshmem_int8_add_
#define shmem_int8_add__ pshmem_int8_add__

#define SHMEM_INT8_CSWAP   PSHMEM_INT8_CSWAP
#define shmem_int8_cswap_  pshmem_int8_cswap_
#define shmem_int8_cswap__ pshmem_int8_cswap__

#define SHMEM_INT8_FADD   PSHMEM_INT8_FADD
#define shmem_int8_fadd_  pshmem_int8_fadd_
#define shmem_int8_fadd__ pshmem_int8_fadd__

#define SHMEM_INT8_FETCH   PSHMEM_INT8_FETCH
#define shmem_int8_fetch_  pshmem_int8_fetch_
#define shmem_int8_fetch__ pshmem_int8_fetch__

#define SHMEM_INT8_FINC   PSHMEM_INT8_FINC
#define shmem_int8_finc_  pshmem_int8_finc_
#define shmem_int8_finc__ pshmem_int8_finc__

#define SHMEM_INT8_INC   PSHMEM_INT8_INC
#define shmem_int8_inc_  pshmem_int8_inc_
#define shmem_int8_inc__ pshmem_int8_inc__

#define SHMEM_INT8_SWAP   PSHMEM_INT8_SWAP
#define shmem_int8_swap_  pshmem_int8_swap_
#define shmem_int8_swap__ pshmem_int8_swap__

#define SHMEM_INT8_SET   PSHMEM_INT8_SET
#define shmem_int8_set_  pshmem_int8_set_
#define shmem_int8_set__ pshmem_int8_set__

#define SHMEM_INT8_WAIT   PSHMEM_INT8_WAIT
#define shmem_int8_wait_  pshmem_int8_wait_
#define shmem_int8_wait__ pshmem_int8_wait__

#define SHMEM_INT8_WAIT_UNTIL   PSHMEM_INT8_WAIT_UNTIL
#define shmem_int8_wait_until_  pshmem_int8_wait_until_
#define shmem_int8_wait_until__ pshmem_int8_wait_until__

#define SHMEM_INTEGER_GET   PSHMEM_INTEGER_GET
#define shmem_integer_get_  pshmem_integer_get_
#define shmem_integer_get__ pshmem_integer_get__

#define SHMEM_INTEGER_IGET   PSHMEM_INTEGER_IGET
#define shmem_integer_iget_  pshmem_integer_iget_
#define shmem_integer_iget__ pshmem_integer_iget__

#define SHMEM_INTEGER_IPUT   PSHMEM_INTEGER_IPUT
#define shmem_integer_iput_  pshmem_integer_iput_
#define shmem_integer_iput__ pshmem_integer_iput__

#define SHMEM_INTEGER_PUT   PSHMEM_INTEGER_PUT
#define shmem_integer_put_  pshmem_integer_put_
#define shmem_integer_put__ pshmem_integer_put__

#define SHMEM_IPUT128   PSHMEM_IPUT128
#define shmem_iput128_  pshmem_iput128_
#define shmem_iput128__ pshmem_iput128__

#define SHMEM_IPUT32   PSHMEM_IPUT32
#define shmem_iput32_  pshmem_iput32_
#define shmem_iput32__ pshmem_iput32__

#define SHMEM_IPUT4   PSHMEM_IPUT4
#define shmem_iput4_  pshmem_iput4_
#define shmem_iput4__ pshmem_iput4__

#define SHMEM_IPUT64   PSHMEM_IPUT64
#define shmem_iput64_  pshmem_iput64_
#define shmem_iput64__ pshmem_iput64__

#define SHMEM_IPUT8   PSHMEM_IPUT8
#define shmem_iput8_  pshmem_iput8_
#define shmem_iput8__ pshmem_iput8__

#define SHMEM_SET_LOCK   PSHMEM_SET_LOCK
#define shmem_set_lock_  pshmem_set_lock_
#define shmem_set_lock__ pshmem_set_lock__

#define SHMEM_TEST_LOCK   PSHMEM_TEST_LOCK
#define shmem_test_lock_  pshmem_test_lock_
#define shmem_test_lock__ pshmem_test_lock__

#define SHMEM_CLEAR_LOCK   PSHMEM_CLEAR_LOCK
#define shmem_clear_lock_  pshmem_clear_lock_
#define shmem_clear_lock__ pshmem_clear_lock__

#define SHMEM_LOGICAL_GET   PSHMEM_LOGICAL_GET
#define shmem_logical_get_  pshmem_logical_get_
#define shmem_logical_get__ pshmem_logical_get__

#define SHMEM_LOGICAL_IGET   PSHMEM_LOGICAL_IGET
#define shmem_logical_iget_  pshmem_logical_iget_
#define shmem_logical_iget__ pshmem_logical_iget__

#define SHMEM_LOGICAL_IPUT   PSHMEM_LOGICAL_IPUT
#define shmem_logical_iput_  pshmem_logical_iput_
#define shmem_logical_iput__ pshmem_logical_iput__

#define SHMEM_LOGICAL_PUT   PSHMEM_LOGICAL_PUT
#define shmem_logical_put_  pshmem_logical_put_
#define shmem_logical_put__ pshmem_logical_put__

#define SHMEM_INT2_MAX_TO_ALL   PSHMEM_INT2_MAX_TO_ALL
#define shmem_int2_max_to_all_  pshmem_int2_max_to_all_
#define shmem_int2_max_to_all__ pshmem_int2_max_to_all__

#define SHMEM_INT4_MAX_TO_ALL   PSHMEM_INT4_MAX_TO_ALL
#define shmem_int4_max_to_all_  pshmem_int4_max_to_all_
#define shmem_int4_max_to_all__ pshmem_int4_max_to_all__

#define SHMEM_INT8_MAX_TO_ALL   PSHMEM_INT8_MAX_TO_ALL
#define shmem_int8_max_to_all_  pshmem_int8_max_to_all_
#define shmem_int8_max_to_all__ pshmem_int8_max_to_all__

#define SHMEM_REAL4_MAX_TO_ALL   PSHMEM_REAL4_MAX_TO_ALL
#define shmem_real4_max_to_all_  pshmem_real4_max_to_all_
#define shmem_real4_max_to_all__ pshmem_real4_max_to_all__

#define SHMEM_REAL8_MAX_TO_ALL   PSHMEM_REAL8_MAX_TO_ALL
#define shmem_real8_max_to_all_  pshmem_real8_max_to_all_
#define shmem_real8_max_to_all__ pshmem_real8_max_to_all__

#define SHMEM_REAL16_MAX_TO_ALL   PSHMEM_REAL16_MAX_TO_ALL
#define shmem_real16_max_to_all_  pshmem_real16_max_to_all_
#define shmem_real16_max_to_all__ pshmem_real16_max_to_all__

#define SHMEM_INT2_MIN_TO_ALL   PSHMEM_INT2_MIN_TO_ALL
#define shmem_int2_min_to_all_  pshmem_int2_min_to_all_
#define shmem_int2_min_to_all__ pshmem_int2_min_to_all__

#define SHMEM_INT4_MIN_TO_ALL   PSHMEM_INT4_MIN_TO_ALL
#define shmem_int4_min_to_all_  pshmem_int4_min_to_all_
#define shmem_int4_min_to_all__ pshmem_int4_min_to_all__

#define SHMEM_INT8_MIN_TO_ALL   PSHMEM_INT8_MIN_TO_ALL
#define shmem_int8_min_to_all_  pshmem_int8_min_to_all_
#define shmem_int8_min_to_all__ pshmem_int8_min_to_all__

#define SHMEM_REAL4_MIN_TO_ALL   PSHMEM_REAL4_MIN_TO_ALL
#define shmem_real4_min_to_all_  pshmem_real4_min_to_all_
#define shmem_real4_min_to_all__ pshmem_real4_min_to_all__

#define SHMEM_REAL8_MIN_TO_ALL   PSHMEM_REAL8_MIN_TO_ALL
#define shmem_real8_min_to_all_  pshmem_real8_min_to_all_
#define shmem_real8_min_to_all__ pshmem_real8_min_to_all__

#define SHMEM_REAL16_MIN_TO_ALL   PSHMEM_REAL16_MIN_TO_ALL
#define shmem_real16_min_to_all_  pshmem_real16_min_to_all_
#define shmem_real16_min_to_all__ pshmem_real16_min_to_all__

#define SHMEM_INT2_OR_TO_ALL   PSHMEM_INT2_OR_TO_ALL
#define shmem_int2_or_to_all_  pshmem_int2_or_to_all_
#define shmem_int2_or_to_all__ pshmem_int2_or_to_all__

#define SHMEM_INT4_OR_TO_ALL   PSHMEM_INT4_OR_TO_ALL
#define shmem_int4_or_to_all_  pshmem_int4_or_to_all_
#define shmem_int4_or_to_all__ pshmem_int4_or_to_all__

#define SHMEM_INT8_OR_TO_ALL   PSHMEM_INT8_OR_TO_ALL
#define shmem_int8_or_to_all_  pshmem_int8_or_to_all_
#define shmem_int8_or_to_all__ pshmem_int8_or_to_all__

#define SHMEM_PE_ACCESSIBLE   PSHMEM_PE_ACCESSIBLE
#define shmem_pe_accessible_  pshmem_pe_accessible_
#define shmem_pe_accessible__ pshmem_pe_accessible__

#define SHMEM_INT2_PROD_TO_ALL   PSHMEM_INT2_PROD_TO_ALL
#define shmem_int2_prod_to_all_  pshmem_int2_prod_to_all_
#define shmem_int2_prod_to_all__ pshmem_int2_prod_to_all__

#define SHMEM_INT4_PROD_TO_ALL   PSHMEM_INT4_PROD_TO_ALL
#define shmem_int4_prod_to_all_  pshmem_int4_prod_to_all_
#define shmem_int4_prod_to_all__ pshmem_int4_prod_to_all__

#define SHMEM_INT8_PROD_TO_ALL   PSHMEM_INT8_PROD_TO_ALL
#define shmem_int8_prod_to_all_  pshmem_int8_prod_to_all_
#define shmem_int8_prod_to_all__ pshmem_int8_prod_to_all__

#define SHMEM_COMP4_PROD_TO_ALL   PSHMEM_COMP4_PROD_TO_ALL
#define shmem_comp4_prod_to_all_  pshmem_comp4_prod_to_all_
#define shmem_comp4_prod_to_all__ pshmem_comp4_prod_to_all__

#define SHMEM_COMP8_PROD_TO_ALL   PSHMEM_COMP8_PROD_TO_ALL
#define shmem_comp8_prod_to_all_  pshmem_comp8_prod_to_all_
#define shmem_comp8_prod_to_all__ pshmem_comp8_prod_to_all__

#define SHMEM_REAL4_PROD_TO_ALL   PSHMEM_REAL4_PROD_TO_ALL
#define shmem_real4_prod_to_all_  pshmem_real4_prod_to_all_
#define shmem_real4_prod_to_all__ pshmem_real4_prod_to_all__

#define SHMEM_REAL8_PROD_TO_ALL   PSHMEM_REAL8_PROD_TO_ALL
#define shmem_real8_prod_to_all_  pshmem_real8_prod_to_all_
#define shmem_real8_prod_to_all__ pshmem_real8_prod_to_all__

#define SHMEM_REAL16_PROD_TO_ALL   PSHMEM_REAL16_PROD_TO_ALL
#define shmem_real16_prod_to_all_  pshmem_real16_prod_to_all_
#define shmem_real16_prod_to_all__ pshmem_real16_prod_to_all__

#define SHMEM_PTR   PSHMEM_PTR
#define shmem_ptr_  pshmem_ptr_
#define shmem_ptr__ pshmem_ptr__

#define SHMEM_PUT32   PSHMEM_PUT32
#define shmem_put32_  pshmem_put32_
#define shmem_put32__ pshmem_put32__

#define SHMEM_PUT4   PSHMEM_PUT4
#define shmem_put4_  pshmem_put4_
#define shmem_put4__ pshmem_put4__

#define SHMEM_PUT64   PSHMEM_PUT64
#define shmem_put64_  pshmem_put64_
#define shmem_put64__ pshmem_put64__

#define SHMEM_PUT128   PSHMEM_PUT128
#define shmem_put128_  pshmem_put128_
#define shmem_put128__ pshmem_put128__

#define SHMEM_PUT8   PSHMEM_PUT8
#define shmem_put8_  pshmem_put8_
#define shmem_put8__ pshmem_put8__

#define SHMEM_PUT   PSHMEM_PUT
#define shmem_put_  pshmem_put_
#define shmem_put__ pshmem_put__

#define SHMEM_PUTMEM   PSHMEM_PUTMEM
#define shmem_putmem_  pshmem_putmem_
#define shmem_putmem__ pshmem_putmem__

#define SHMEM_QUIET   PSHMEM_QUIET
#define shmem_quiet_  pshmem_quiet_
#define shmem_quiet__ pshmem_quiet__

#define SHMEM_REAL4_SWAP   PSHMEM_REAL4_SWAP
#define shmem_real4_swap_  pshmem_real4_swap_
#define shmem_real4_swap__ pshmem_real4_swap__

#define SHMEM_REAL8_SWAP   PSHMEM_REAL8_SWAP
#define shmem_real8_swap_  pshmem_real8_swap_
#define shmem_real8_swap__ pshmem_real8_swap__

#define SHMEM_REAL4_SET   PSHMEM_REAL4_SET
#define shmem_real4_set_  pshmem_real4_set_
#define shmem_real4_set__ pshmem_real4_set__

#define SHMEM_REAL8_SET   PSHMEM_REAL8_SET
#define shmem_real8_set_  pshmem_real8_set_
#define shmem_real8_set__ pshmem_real8_set__

#define SHMEM_REAL4_FETCH   PSHMEM_REAL4_FETCH
#define shmem_real4_fetch_  pshmem_real4_fetch_
#define shmem_real4_fetch__ pshmem_real4_fetch__

#define SHMEM_REAL8_FETCH   PSHMEM_REAL8_FETCH
#define shmem_real8_fetch_  pshmem_real8_fetch_
#define shmem_real8_fetch__ pshmem_real8_fetch__

#define SHMEM_REAL_GET   PSHMEM_REAL_GET
#define shmem_real_get_  pshmem_real_get_
#define shmem_real_get__ pshmem_real_get__

#define SHMEM_REAL_IGET   PSHMEM_REAL_IGET
#define shmem_real_iget_  pshmem_real_iget_
#define shmem_real_iget__ pshmem_real_iget__

#define SHMEM_REAL_IPUT   PSHMEM_REAL_IPUT
#define shmem_real_iput_  pshmem_real_iput_
#define shmem_real_iput__ pshmem_real_iput__

#define SHMEM_REAL_PUT   PSHMEM_REAL_PUT
#define shmem_real_put_  pshmem_real_put_
#define shmem_real_put__ pshmem_real_put__

#define SHMEM_INT2_SUM_TO_ALL   PSHMEM_INT2_SUM_TO_ALL
#define shmem_int2_sum_to_all_  pshmem_int2_sum_to_all_
#define shmem_int2_sum_to_all__ pshmem_int2_sum_to_all__

#define SHMEM_INT4_SUM_TO_ALL   PSHMEM_INT4_SUM_TO_ALL
#define shmem_int4_sum_to_all_  pshmem_int4_sum_to_all_
#define shmem_int4_sum_to_all__ pshmem_int4_sum_to_all__

#define SHMEM_INT8_SUM_TO_ALL   PSHMEM_INT8_SUM_TO_ALL
#define shmem_int8_sum_to_all_  pshmem_int8_sum_to_all_
#define shmem_int8_sum_to_all__ pshmem_int8_sum_to_all__

#define SHMEM_COMP4_SUM_TO_ALL   PSHMEM_COMP4_SUM_TO_ALL
#define shmem_comp4_sum_to_all_  pshmem_comp4_sum_to_all_
#define shmem_comp4_sum_to_all__ pshmem_comp4_sum_to_all__

#define SHMEM_COMP8_SUM_TO_ALL   PSHMEM_COMP8_SUM_TO_ALL
#define shmem_comp8_sum_to_all_  pshmem_comp8_sum_to_all_
#define shmem_comp8_sum_to_all__ pshmem_comp8_sum_to_all__

#define SHMEM_REAL4_SUM_TO_ALL   PSHMEM_REAL4_SUM_TO_ALL
#define shmem_real4_sum_to_all_  pshmem_real4_sum_to_all_
#define shmem_real4_sum_to_all__ pshmem_real4_sum_to_all__

#define SHMEM_REAL8_SUM_TO_ALL   PSHMEM_REAL8_SUM_TO_ALL
#define shmem_real8_sum_to_all_  pshmem_real8_sum_to_all_
#define shmem_real8_sum_to_all__ pshmem_real8_sum_to_all__

#define SHMEM_REAL16_SUM_TO_ALL   PSHMEM_REAL16_SUM_TO_ALL
#define shmem_real16_sum_to_all_  pshmem_real16_sum_to_all_
#define shmem_real16_sum_to_all__ pshmem_real16_sum_to_all__

#define SHMEM_SWAP   PSHMEM_SWAP
#define shmem_swap_  pshmem_swap_
#define shmem_swap__ pshmem_swap__

#define SHMEM_WAIT   PSHMEM_WAIT
#define shmem_wait_  pshmem_wait_
#define shmem_wait__ pshmem_wait__

#define SHMEM_WAIT_UNTIL   PSHMEM_WAIT_UNTIL
#define shmem_wait_until_  pshmem_wait_until_
#define shmem_wait_until__ pshmem_wait_until__

#define SHMEM_INT2_XOR_TO_ALL   PSHMEM_INT2_XOR_TO_ALL
#define shmem_int2_xor_to_all_  pshmem_int2_xor_to_all_
#define shmem_int2_xor_to_all__ pshmem_int2_xor_to_all__

#define SHMEM_INT4_XOR_TO_ALL   PSHMEM_INT4_XOR_TO_ALL
#define shmem_int4_xor_to_all_  pshmem_int4_xor_to_all_
#define shmem_int4_xor_to_all__ pshmem_int4_xor_to_all__

#define SHMEM_INT8_XOR_TO_ALL   PSHMEM_INT8_XOR_TO_ALL
#define shmem_int8_xor_to_all_  pshmem_int8_xor_to_all_
#define shmem_int8_xor_to_all__ pshmem_int8_xor_to_all__

#define SHMEM_COMP4_XOR_TO_ALL   PSHMEM_COMP4_XOR_TO_ALL
#define shmem_comp4_xor_to_all_  pshmem_comp4_xor_to_all_
#define shmem_comp4_xor_to_all__ pshmem_comp4_xor_to_all__

#define SHMEM_COMP8_XOR_TO_ALL   PSHMEM_COMP8_XOR_TO_ALL
#define shmem_comp8_xor_to_all_  pshmem_comp8_xor_to_all_
#define shmem_comp8_xor_to_all__ pshmem_comp8_xor_to_all__

#define SHPALLOC   PSHPALLOC
#define shpalloc_  pshpalloc_
#define shpalloc__ pshpalloc__

#define SHPCLMOVE   PSHPCLMOVE
#define shpclmove_  pshpclmove_
#define shpclmove__ pshpclmove__

#define SHPDEALLC   PSHPDEALLC
#define shpdeallc_  pshpdeallc_
#define shpdeallc__ pshpdeallc__

#endif /* OSHMEM_FORTRAN_PROFILE_DEFINES_H */
