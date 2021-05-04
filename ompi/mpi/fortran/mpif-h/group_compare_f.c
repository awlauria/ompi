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
 * Copyright (c) 2011-2012 Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2015      Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "ompi_config.h"

#include "ompi/group/group.h"
#include "ompi/mpi/fortran/mpif-h/bindings.h"

#if OMPI_BUILD_MPI_PROFILING
#    if OPAL_HAVE_WEAK_SYMBOLS
#        pragma weak PMPI_GROUP_COMPARE = ompi_group_compare_f
#        pragma weak pmpi_group_compare = ompi_group_compare_f
#        pragma weak pmpi_group_compare_ = ompi_group_compare_f
#        pragma weak pmpi_group_compare__ = ompi_group_compare_f

#        pragma weak PMPI_Group_compare_f = ompi_group_compare_f
#        pragma weak PMPI_Group_compare_f08 = ompi_group_compare_f
#    else
OMPI_GENERATE_F77_BINDINGS(PMPI_GROUP_COMPARE, pmpi_group_compare, pmpi_group_compare_,
                           pmpi_group_compare__, pompi_group_compare_f,
                           (MPI_Fint * group1, MPI_Fint *group2, MPI_Fint *result,
                            MPI_Fint *ierror),
                           (group1, group2, result, ierror))
#    endif
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#    pragma weak MPI_GROUP_COMPARE = ompi_group_compare_f
#    pragma weak mpi_group_compare = ompi_group_compare_f
#    pragma weak mpi_group_compare_ = ompi_group_compare_f
#    pragma weak mpi_group_compare__ = ompi_group_compare_f

#    pragma weak MPI_Group_compare_f = ompi_group_compare_f
#    pragma weak MPI_Group_compare_f08 = ompi_group_compare_f
#endif

#if !OMPI_BUILD_MPI_PROFILING && !OPAL_HAVE_WEAK_SYMBOLS
OMPI_GENERATE_F77_BINDINGS(MPI_GROUP_COMPARE, mpi_group_compare, mpi_group_compare_,
                           mpi_group_compare__, ompi_group_compare_f,
                           (MPI_Fint * group1, MPI_Fint *group2, MPI_Fint *result,
                            MPI_Fint *ierror),
                           (group1, group2, result, ierror))
#endif

#if OMPI_BUILD_MPI_PROFILING && !OPAL_HAVE_WEAK_SYMBOLS
#    define ompi_group_compare_f pompi_group_compare_f
#endif

void ompi_group_compare_f(MPI_Fint *group1, MPI_Fint *group2, MPI_Fint *result, MPI_Fint *ierr)
{
    int c_ierr;
    ompi_group_t *c_group1, *c_group2;
    OMPI_SINGLE_NAME_DECL(result);

    /* make the fortran to c representation conversion */
    c_group1 = PMPI_Group_f2c(*group1);
    c_group2 = PMPI_Group_f2c(*group2);

    c_ierr = PMPI_Group_compare(c_group1, c_group2, OMPI_SINGLE_NAME_CONVERT(result));
    if (NULL != ierr)
        *ierr = OMPI_INT_2_FINT(c_ierr);

    if (MPI_SUCCESS == c_ierr) {
        OMPI_SINGLE_INT_2_FINT(result);
    }
}
