#include "opal/util/output.h"
#include "opal/runtime/opal.h"
#include "atomic.h"

#include "opal/mca/threads/pthreads/threads_pthreads_mutex.h"

pthread_mutex_t atomic_fallback_mutex;

static void opal_util_atomic_finalize (void)
{
    pthread_mutex_destroy(&atomic_fallback_mutex);
}

int opal_util_atomic_init(void)
{
    pthread_mutex_init(&atomic_fallback_mutex, NULL);

    opal_finalize_register_cleanup (opal_util_atomic_finalize);

    return OPAL_SUCCESS;
}
