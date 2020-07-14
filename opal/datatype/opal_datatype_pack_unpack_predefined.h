/*
 * Copyright (c) 2020      IBM Corporation.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef OPAL_DATATYPE_PACK_UNPACK_PREDEFINED_H_HAS_BEEN_INCLUDED
#define OPAL_DATATYPE_PACK_UNPACK_PREDEFINED_H_HAS_BEEN_INCLUDED

#include "opal_config.h"
#include <stdint.h>

/*
 *  Improved predefined pack/unpack method using mvapich methods.
 *   
 *  For reference implementation, see:
 *  https://github.com/pmodels/mpich/blob/9ab5fd06af2a648bf24214f0d9cff0ee77ee3e7d/src/mpi/datatype/veccpy.h
 * 
 *  The overhead of memcpy() was causing noticable slowdown in the
 *  predefined pack/unpack routines. To fix that, this PR implements a
 *  manual copy for blocklengths of <= 8, an idea borrowed from
 *  mpich above.
 * 
 *  It may also be beneficial to perform a manual copy for larger blocklengths.
 *  However, more data will have to be gathered to see if a similar
 *  implementation would be better over the current memcpy() approach.
*/

#define OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_ONE(stride, blocklen) { \
  for (; i; i--) {            \
    *_dest   = *_src;         \
     _src    += stride;       \
     _dest   += blocklen;     \
  }                           \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_TWO(stride, blocklen) { \
  for (; i > 1; i -= 2) {     \
    _dest[0]  = _src[0];      \
    _dest[1]  = _src[1];      \
    _src     += stride;       \
    _dest    += blocklen;     \
  }                           \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_THREE(stride, blocklen) { \
  for (; i > 2; i -= 3) {     \
    _dest[0]  = _src[0];      \
    _dest[1]  = _src[1];      \
    _dest[2]  = _src[2];      \
    _src     += stride;       \
    _dest    += blocklen;     \
  }                           \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_FOUR(stride, blocklen) { \
  for (; i > 3; i -= 4) {     \
    _dest[0]  = _src[0];      \
    _dest[1]  = _src[1];      \
    _dest[2]  = _src[2];      \
    _dest[3]  = _src[3];      \
    _src     += stride;       \
    _dest    += blocklen;     \
  }                           \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_FIVE(stride, blocklen) { \
  for (; i > 4; i -= 5) {     \
    _dest[0]  = _src[0];      \
    _dest[1]  = _src[1];      \
    _dest[2]  = _src[2];      \
    _dest[3]  = _src[3];      \
    _dest[4]  = _src[4];      \
    _src     += stride;       \
    _dest    += blocklen;     \
  }                           \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_SIX(stride, blocklen) { \
  for (; i > 5; i -= 6) {     \
    _dest[0]  = _src[0];      \
    _dest[1]  = _src[1];      \
    _dest[2]  = _src[2];      \
    _dest[3]  = _src[3];      \
    _dest[4]  = _src[4];      \
    _dest[5]  = _src[5];      \
    _src     += stride;       \
    _dest    += blocklen;     \
  }                           \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_SEVEN(stride, blocklen) { \
  for (; i > 6; i -= 7) {     \
    _dest[0]  = _src[0];      \
    _dest[1]  = _src[1];      \
    _dest[2]  = _src[2];      \
    _dest[3]  = _src[3];      \
    _dest[4]  = _src[4];      \
    _dest[5]  = _src[5];      \
    _dest[6]  = _src[6];      \
    _src     += stride;       \
    _dest    += blocklen;     \
  }                           \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_EIGHT(stride, blocklen) { \
  for (; i > 7; i -= 8) {     \
    _dest[0]  = _src[0];      \
    _dest[1]  = _src[1];      \
    _dest[2]  = _src[2];      \
    _dest[3]  = _src[3];      \
    _dest[4]  = _src[4];      \
    _dest[5]  = _src[5];      \
    _dest[6]  = _src[6];      \
    _dest[7]  = _src[7];      \
    _src     += stride;       \
    _dest    += blocklen;     \
  }                           \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_RESIDUAL_DATA() { \
  if(i != 0) {                          \
   for (; i > 0; i--) {                 \
     *_dest++ = *_src++;                \
   }                                    \
  }                                     \
}

#define OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src_base, dest_base, count, stride, blocklen, type) {     \
  type* _src  = (type *) src_base;                                        \
  type* _dest = (type *) dest_base;                                       \
  register unsigned long i = count;                                       \
  if(blocklen == 1) {                                                     \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_ONE(stride, blocklen);         \
  }                                                                       \
  else if (blocklen == 2) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_TWO(stride, blocklen);         \
  }                                                                       \
  else if (blocklen == 3) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_THREE(stride, blocklen);       \
  }                                                                       \
  else if (blocklen == 4) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_FOUR(stride, blocklen);        \
  }                                                                       \
  else if (blocklen == 5) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_FIVE(stride, blocklen);        \
  }                                                                       \
  else if (blocklen == 6) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_SIX(stride, blocklen);         \
  }                                                                       \
  else if (blocklen == 7) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_SEVEN(stride, blocklen);       \
  }                                                                       \
  else if (blocklen == 8) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_EIGHT(stride, blocklen);       \
  }                                                                       \
  OPAL_DATATYPE_PACK_PREDEFINED_RESIDUAL_DATA()                           \
  src_base  = (unsigned char *) _src;                                     \
  dest_base = (unsigned char *) _dest;                                    \
}                                                                         \

#define OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src_base, dest_base, count, stride, blocklen, type) {     \
  type* _src  = (type *) src_base;                                        \
  type* _dest = (type *) dest_base;                                       \
  register unsigned long i = count;                                       \
  if(blocklen == 1) {                                                     \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_ONE(blocklen, stride);         \
  }                                                                       \
  else if (blocklen == 2) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_TWO(blocklen, stride);         \
  }                                                                       \
  else if (blocklen == 3) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_THREE(blocklen, stride);       \
  }                                                                       \
  else if (blocklen == 4) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_FOUR(blocklen, stride);        \
  }                                                                       \
  else if (blocklen == 5) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_FIVE(blocklen, stride);        \
  }                                                                       \
  else if (blocklen == 6) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_SIX(blocklen, stride);         \
  }                                                                       \
  else if (blocklen == 7) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_SEVEN(blocklen, stride);       \
  }                                                                       \
  else if (blocklen == 8) {                                               \
    OPAL_DATATYPE_PACK_PREDEFINED_BLOCKLEN_EIGHT(blocklen, stride);       \
  }                                                                       \
  OPAL_DATATYPE_PACK_PREDEFINED_RESIDUAL_DATA()                           \
  src_base  = (unsigned char *) _src;                                     \
  dest_base = (unsigned char *) _dest;                                    \
}                                                                         \

static inline int
opal_datatype_unpack_predefined_element( unsigned char** rtn_src,
                                unsigned char** rtn_dest,
                                size_t cando_count,
                                size_t stride,
                                int    blocklen,
                                int    id) {

    unsigned char *src = *rtn_src;
    unsigned char *dest = *rtn_dest;

    switch(id) {
        case OPAL_DATATYPE_INT1:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, int8_t);
            break;
        case OPAL_DATATYPE_INT2:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, int16_t);
            break;
        case OPAL_DATATYPE_INT4:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, int32_t);
            break;
        case OPAL_DATATYPE_INT8:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, int64_t);
            break;
        case OPAL_DATATYPE_INT16:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, __int128_t);
            break;
        case OPAL_DATATYPE_UINT1:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, uint8_t);
            break;
        case OPAL_DATATYPE_UINT2:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, uint16_t);
            break;
        case OPAL_DATATYPE_UINT4:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, uint32_t);
            break;
        case OPAL_DATATYPE_UINT8:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, uint64_t);
            break;
        case OPAL_DATATYPE_UINT16:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, __uint128_t);
            break;
        case OPAL_DATATYPE_FLOAT4:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, float);
            break;
        case OPAL_DATATYPE_FLOAT8:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, double);
            break;
        case OPAL_DATATYPE_FLOAT16:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, long double);
            break;
        case OPAL_DATATYPE_SHORT_FLOAT_COMPLEX:
#if defined(HAVE_SHORT_FLOAT__COMPLEX)
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, short float _Complex);
#elif defined(HAVE_OPAL_SHORT_FLOAT_COMPLEX_T)
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, opal_short_float_complex_t);
#else
            return 1;
#endif
            break;
        case OPAL_DATATYPE_FLOAT_COMPLEX:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, float _Complex);
            break;
        case OPAL_DATATYPE_DOUBLE_COMPLEX:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, double _Complex);
            break;
        case OPAL_DATATYPE_LONG_DOUBLE_COMPLEX:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, long double _Complex);
            break;
        case OPAL_DATATYPE_BOOL:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, _Bool);
            break;
        case OPAL_DATATYPE_WCHAR:
            OPAL_DATATYPE_UNPACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, wchar_t);
            break;
        default:
            return 1;
     }
     *rtn_src  = src;
     *rtn_dest = dest;
     return 0;
}

static inline int
opal_datatype_pack_predefined_element( unsigned char** rtn_src,
                                unsigned char** rtn_dest,
                                size_t cando_count,
                                size_t stride,
                                int    blocklen,
                                int    id) {

    unsigned char *src = *rtn_src;
    unsigned char *dest = *rtn_dest;

    switch(id) {
        case OPAL_DATATYPE_INT1:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, int8_t);
            break;
        case OPAL_DATATYPE_INT2:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, int16_t);
            break;
        case OPAL_DATATYPE_INT4:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, int32_t);
            break;
        case OPAL_DATATYPE_INT8:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, int64_t);
            break;
        case OPAL_DATATYPE_INT16:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, __int128_t);
            break;
        case OPAL_DATATYPE_UINT1:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, uint8_t);
            break;
        case OPAL_DATATYPE_UINT2:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, uint16_t);
            break;
        case OPAL_DATATYPE_UINT4:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, uint32_t);
            break;
        case OPAL_DATATYPE_UINT8:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, uint64_t);
            break;
        case OPAL_DATATYPE_UINT16:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, __uint128_t);
            break;
        case OPAL_DATATYPE_FLOAT4:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, float);
            break;
        case OPAL_DATATYPE_FLOAT8:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, double);
            break;
        case OPAL_DATATYPE_FLOAT16:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, long double);
            break;
        case OPAL_DATATYPE_SHORT_FLOAT_COMPLEX:
#if defined(HAVE_SHORT_FLOAT__COMPLEX)
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, short float _Complex);
#elif defined(HAVE_OPAL_SHORT_FLOAT_COMPLEX_T)
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, opal_short_float_complex_t);
#else
            return 1;
#endif
            break;
        case OPAL_DATATYPE_FLOAT_COMPLEX:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, float _Complex);
            break;
        case OPAL_DATATYPE_DOUBLE_COMPLEX:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, double _Complex);
            break;
        case OPAL_DATATYPE_LONG_DOUBLE_COMPLEX:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, long double _Complex);
            break;
        case OPAL_DATATYPE_BOOL:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, _Bool);
            break;
        case OPAL_DATATYPE_WCHAR:
            OPAL_DATATYPE_PACK_PREDEFINED_ELEMENT(src, dest, cando_count, stride, blocklen, wchar_t);
            break;
        default:
            return 1;
     }

     *rtn_src  = src;
     *rtn_dest = dest;
     return 0;
}
#endif
