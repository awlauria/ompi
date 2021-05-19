/*
 * Copyright (c) 2015      Mellanox Technologies, Inc.
 *                         All rights reserved.
 * Copyright (c) 2016      Intel, Inc. All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
/*
 * To compile test:
 * mpicc -I$src_dir -I$src_dir/opal/include -I$src_dir/ompi/include
 * -DOMPI_BUILDING=1 pmix.c -o pmix To run test: mpirun -np 2 <any mca params> ./pmix Test should
 * print "Passed" in case of success and print pmix time intervals at process with rank 0.
 * */
#include <mpi.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include "ompi/proc/proc.h"
#include "opal/util/output.h"
#include "opal/class/opal_list.h"
#include "opal/mca/pmix/pmix-3rdparty.h"

#define DO_FINALIZE(rc, flag, format, args...) \
    do {                                       \
        if (flag) {                            \
            fprintf(stderr, format, args);     \
        }                                      \
        MPI_Finalize();                        \
        return rc;                             \
    } while (0);

static int my_rank;
static volatile bool waiting = true;

static double get_timestamp(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec) + (tv.tv_usec) * 1.0e-6);
}

static void evhandler(size_t id, const pmix_status_t status, const pmix_proc_t *source, pmix_info_t info[],
                      size_t ninfo, pmix_info_t *results, size_t nresults, pmix_event_notification_cbfunc_fn_t cbfunc,
                      void *cbdata)
{
    fprintf(stderr, "%d: received notification status %d\n", my_rank, status);
    //if (NULL != cbfunc) {
    //    cbfunc(OPAL_ERR_HANDLERS_COMPLETE, NULL, 0, NULL, cbdata, NULL);
   // }
    waiting = false;
}

int main(int argc, char *argv[])
{
    int rc, code;;
    int recv_data;
    size_t i, numprocs;
    ompi_proc_t **procs, *thisproc;
    double t0, t1, t2, t3, t4, t5, t6;
    int *ptr;
    struct timespec tp;
    pmix_info_t iptr;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    PMIX_INFO_LOAD(&iptr, PMIX_EVENT_HDLR_PREPEND, "DEFAULT", PMIX_STRING);
    PMIx_Register_event_handler(&code, 1, &iptr, 1, evhandler, NULL, NULL);

    int data = my_rank;
    t0 = get_timestamp();
    OPAL_MODEX_SEND_VALUE(rc, PMIX_GLOBAL, "MY_RANK", &data, PMIX_INT);
    t1 = get_timestamp();
    if (OPAL_SUCCESS != rc) {
        DO_FINALIZE(rc, 1, "[%d] OPAL_MODEX_SEND_STRING failed.\n", my_rank);
    }
    t2 = get_timestamp();
    PMIx_Commit();
    PMIx_Fence_nb(NULL, 0, NULL, 0, NULL, NULL);
    t3 = get_timestamp();
    procs = ompi_proc_world(&numprocs);
    ptr = &recv_data;
    t4 = get_timestamp();
    for (i = 0; i < numprocs; i++) {
        thisproc = procs[i];
        OPAL_MODEX_RECV_VALUE(rc, "MY_RANK", &thisproc->super.proc_name, (void **) &ptr, PMIX_INT);
        /* check return status and received data */
        if (OPAL_SUCCESS != rc || i != recv_data) {
            rc = OPAL_ERROR;
            DO_FINALIZE(rc, 1, "[%d] OPAL_MODEX_RECV_VALUE failed from rank %d.\n", my_rank, i);
        }
    }
    t5 = get_timestamp();

    /* using fence as a barrier */
    PMIx_Fence_nb(NULL, 0, NULL, 0, NULL, NULL);
    t6 = get_timestamp();

    fprintf(stderr, "[%d] Test passed.\n", my_rank);
    fprintf(stderr, "[%d] \"MODEX_SEND\" %f\n", my_rank, t1 - t0);
    fprintf(stderr, "[%d] \"FENCE\" %f\n", my_rank, t3 - t2);
    fprintf(stderr, "[%d] \"MODEX_RECV\" %f\n", my_rank, t5 - t4);
    fprintf(stderr, "[%d] \"BARRIER\" %f\n", my_rank, t6 - t5);
    fprintf(stderr, "[%d] \"TOTAL\" %f\n", my_rank, t6 - t0);

    fprintf(stderr, "[%d] Pid %d waiting for notification\n", my_rank, (int) getpid());

    /* now wait for notification of someone failing */
    tp.tv_sec = 0;
    tp.tv_nsec = 100000;
    waiting = true;
    pmix_info_t info[2];
    /* notify the host that we are waiting */
    PMIX_INFO_LOAD(&info[0], PMIX_EVENT_NON_DEFAULT, NULL, PMIX_BOOL);
    PMIX_INFO_LOAD(&info[1], "", "DONE", PMIX_STRING);
    pmix_proc_t proc;
    PMIx_Notify_event(0, NULL, PMIX_RANGE_RM, info, 2, NULL, NULL);
    while (waiting) {
        nanosleep(&tp, NULL);
    }
    free(procs);

    DO_FINALIZE(0, 0, 0, 0);
}
