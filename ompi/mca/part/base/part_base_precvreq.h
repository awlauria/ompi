/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2016 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2006      Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2016      Los Alamos National Security, LLC. All rights
 *                         reserved.
 * Copyright (c) 2020      Sandia National Laboratories. All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
/**
 * @file
 */
#ifndef MCA_PART_BASE_PRECV_REQUEST_H
#define MCA_PART_BASE_PRECV_REQUEST_H

#include "ompi_config.h"
#include "ompi/mca/part/base/part_base_prequest.h"
#include "ompi/peruse/peruse-internal.h"
#include "opal/datatype/opal_convertor.h"

BEGIN_C_DECLS

/**
 * Base type for receive requests.
 */
struct mca_part_base_precv_request_t {
    mca_part_base_prequest_t req_base; /**< base request */
    size_t parts;                      /**< number of partitions */
};
typedef struct mca_part_base_precv_request_t mca_part_base_precv_request_t;

OMPI_DECLSPEC OBJ_CLASS_DECLARATION(mca_part_base_precv_request_t);

END_C_DECLS

#endif
