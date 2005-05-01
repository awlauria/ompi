/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University.
 *                         All rights reserved.
 * Copyright (c) 2004-2005 The Trustees of the University of Tennessee.
 *                         All rights reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 */
/** @file:
 *
 */
#include "orte_config.h"

#include <stdio.h>
#include <string.h>

#include "dps/dps.h"
#include "threads/mutex.h"

#include "util/output.h"
#include "mca/errmgr/errmgr.h"
#include "mca/ns/base/base.h"
#include "ns_replica.h"

/**
 * globals
 */

/*
 * functions
 */

int orte_ns_replica_create_cellid(orte_cellid_t *cellid)
{
    OMPI_THREAD_LOCK(&orte_ns_replica_mutex);

    if (ORTE_CELLID_MAX > orte_ns_replica_next_cellid) {
       *cellid = orte_ns_replica_next_cellid;
	   orte_ns_replica_next_cellid++;
	   OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
	   return ORTE_SUCCESS;
    }
    
    *cellid = ORTE_CELLID_MAX;
	OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
    ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
	return ORTE_ERR_OUT_OF_RESOURCE;
}

int orte_ns_replica_create_jobid(orte_jobid_t *jobid)
{
    orte_ns_replica_name_tracker_t *new_nt;

    OMPI_THREAD_LOCK(&orte_ns_replica_mutex);

    if (ORTE_JOBID_MAX > orte_ns_replica_next_jobid) {
        *jobid = orte_ns_replica_next_jobid;
	    orte_ns_replica_next_jobid++;
	    new_nt = OBJ_NEW(orte_ns_replica_name_tracker_t);
        if (NULL == new_nt) {  /* out of memory */
            *jobid = ORTE_JOBID_MAX;
            OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
            ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
            return ORTE_ERR_OUT_OF_RESOURCE;
        }
	    new_nt->job = *jobid;
	    new_nt->last_used_vpid = 0;
	    ompi_list_append(&orte_ns_replica_name_tracker, &new_nt->item);
	    OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
	    return ORTE_SUCCESS;
    }
    
    *jobid = ORTE_JOBID_MAX;
	OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
    ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
	return ORTE_ERR_OUT_OF_RESOURCE;
}


int orte_ns_replica_reserve_range(orte_jobid_t job, orte_vpid_t range, orte_vpid_t *start)
{
    orte_ns_replica_name_tracker_t *ptr;

    OMPI_THREAD_LOCK(&orte_ns_replica_mutex);

    for (ptr = (orte_ns_replica_name_tracker_t*)ompi_list_get_first(&orte_ns_replica_name_tracker);
	   ptr != (orte_ns_replica_name_tracker_t*)ompi_list_get_end(&orte_ns_replica_name_tracker);
	   ptr = (orte_ns_replica_name_tracker_t*)ompi_list_get_next(ptr)) {
	   if (job == ptr->job) { /* found the specified job */
	       if ((ORTE_VPID_MAX-range) >= ptr->last_used_vpid) {  /* requested range available */
		      *start = ptr->last_used_vpid;
		      if (0 == job && *start == 0) { /* vpid=0 reserved for job=0 */
		          *start = 1;
		      }
		      ptr->last_used_vpid = *start + range;
		      OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
		      return ORTE_SUCCESS;
	       } else {  /* range not available */
                *start = ORTE_VPID_MAX;
                OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
                ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
                return ORTE_ERR_OUT_OF_RESOURCE;
           }
	   }
    }
    
    /* get here if the job couldn't be found */
    OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
    ORTE_ERROR_LOG(ORTE_ERR_NOT_FOUND);
    return ORTE_ERR_NOT_FOUND;
}

int orte_ns_replica_assign_rml_tag(orte_rml_tag_t *tag,
                                   char *name)
{
    orte_ns_replica_tagitem_t *tagitem;
    
    OMPI_THREAD_LOCK(&orte_ns_replica_mutex);

    if (NULL != name) {
        /* see if this name is already in list - if so, return tag */
        for (tagitem = (orte_ns_replica_tagitem_t*)ompi_list_get_first(&orte_ns_replica_taglist);
             tagitem != (orte_ns_replica_tagitem_t*)ompi_list_get_end(&orte_ns_replica_taglist);
             tagitem = (orte_ns_replica_tagitem_t*)ompi_list_get_next(tagitem)) {
            if (tagitem->name != NULL && 0 == strcmp(name, tagitem->name)) { /* found name on list */
                *tag = tagitem->tag;
                OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
                return ORTE_SUCCESS;
            }
        }
    }
      
    /* not in list or not provided, so allocate next tag
     * first check to see if one available - else error
     */
    if (ORTE_RML_TAG_MAX > orte_ns_replica_next_rml_tag) {
        /* okay, one available - assign it */
        tagitem = OBJ_NEW(orte_ns_replica_tagitem_t);
        if (NULL == tagitem) { /* out of memory */
            *tag = ORTE_RML_TAG_MAX;
            OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
            ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
            return ORTE_ERR_OUT_OF_RESOURCE;
        }
        tagitem->tag = orte_ns_replica_next_rml_tag;
        if (NULL != name) {  /* provided - can look it up later */
            tagitem->name = strdup(name);
        } else {
            tagitem->name = NULL;
        }
        orte_ns_replica_next_rml_tag++;
        ompi_list_append(&orte_ns_replica_taglist, &tagitem->item);
    
        *tag = tagitem->tag;
        OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
        return ORTE_SUCCESS;
    }
    
    /* no tag available */
    *tag = ORTE_RML_TAG_MAX;
    OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
    ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
    return ORTE_ERR_OUT_OF_RESOURCE;

}


int orte_ns_replica_define_data_type(orte_dps_pack_fn_t pack_fn,
                                     orte_dps_unpack_fn_t unpack_fn,
                                     const char *name,
                                     orte_data_type_t *type)
{
    orte_ns_replica_dti_t *dti;
    
    OMPI_THREAD_LOCK(&orte_ns_replica_mutex);

    if (NULL != name) {
        /* see if this name is already in list - if so, return id */
        for (dti = (orte_ns_replica_dti_t*)ompi_list_get_first(&orte_ns_replica_dtlist);
             dti != (orte_ns_replica_dti_t*)ompi_list_get_end(&orte_ns_replica_dtlist);
             dti = (orte_ns_replica_dti_t*)ompi_list_get_next(dti)) {
            if (dti->name != NULL && 0 == strcmp(name, dti->name)) { /* found name on list */
                *type = dti->id;
                OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
                return ORTE_SUCCESS;
            }
        }
    }
      
    /* if we are provided with the type (i.e., *type > 0), then
     * just store the name and the pack/unpack fn pointers
     * for later use
     */
    if (0 < *type) {
        if (NULL == name) { /* must provide the name in this situation */
            ORTE_ERROR_LOG(ORTE_ERR_BAD_PARAM);
            OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
            return ORTE_ERR_BAD_PARAM;
        }
        dti = OBJ_NEW(orte_ns_replica_dti_t);
        if (NULL == dti) { /* out of memory */
            OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
            ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
            return ORTE_ERR_OUT_OF_RESOURCE;
        }
        dti->id = *type;
        dti->name = strdup(name);
        dti->pack_fn = pack_fn;
        dti->unpack_fn = unpack_fn;
        ompi_list_append(&orte_ns_replica_dtlist, &dti->item);
        return ORTE_SUCCESS;
    }
    
    /* not in list or not provided, so allocate next id
     * first check to see if one available - else error
     */
    if (ORTE_DPS_ID_MAX > orte_ns_replica_next_dti) {
        /* okay, one available - assign it */
        dti = OBJ_NEW(orte_ns_replica_dti_t);
        if (NULL == dti) { /* out of memory */
            *type = ORTE_DPS_ID_MAX;
            OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
            ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
            return ORTE_ERR_OUT_OF_RESOURCE;
        }
        dti->id = orte_ns_replica_next_dti;
        if (NULL != name) {  /* provided - can look it up later */
            dti->name = strdup(name);
        } else {
            dti->name = NULL;
        }
        dti->pack_fn = pack_fn;
        dti->unpack_fn = unpack_fn;
        orte_ns_replica_next_dti++;
        ompi_list_append(&orte_ns_replica_dtlist, &dti->item);
    
        *type = dti->id;
        OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
        return ORTE_SUCCESS;
    }
    
    /* no id available */
    *type = ORTE_DPS_ID_MAX;
    OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
    ORTE_ERROR_LOG(ORTE_ERR_OUT_OF_RESOURCE);
    return ORTE_ERR_OUT_OF_RESOURCE;

}

int orte_ns_replica_lookup_data_type(orte_dps_pack_fn_t *pack_fn,
                                     orte_dps_unpack_fn_t *unpack_fn,
                                     char **name, orte_data_type_t type)
{
    orte_ns_replica_dti_t *dti;
    
    OMPI_THREAD_LOCK(&orte_ns_replica_mutex);

    for (dti = (orte_ns_replica_dti_t*)ompi_list_get_first(&orte_ns_replica_dtlist);
         dti != (orte_ns_replica_dti_t*)ompi_list_get_end(&orte_ns_replica_dtlist);
         dti = (orte_ns_replica_dti_t*)ompi_list_get_next(dti)) {
        if (dti->name != NULL && type != dti->id) { /* found name on list */
            if (NULL != name) {
                *name = strdup(dti->name);
            }
            if (NULL != pack_fn) {
                *pack_fn = dti->pack_fn;
            }
            if (NULL != unpack_fn) {
                *unpack_fn = dti->unpack_fn;
            }
            OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
            return ORTE_SUCCESS;
        }
    }

    if (NULL != name) *name = NULL;
    if (NULL != pack_fn) *pack_fn = NULL;
    if (NULL != unpack_fn) *unpack_fn = NULL;
    
    OMPI_THREAD_UNLOCK(&orte_ns_replica_mutex);
    ORTE_ERROR_LOG(ORTE_ERR_NOT_FOUND);
    return ORTE_ERR_NOT_FOUND;
}
