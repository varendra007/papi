/**
 * @file    common.h
 * @author  Giuseppe Congiu
 *          gcongiu@icl.utk.edu
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "papi.h"
#include "papi_memory.h"
#include "papi_internal.h"

#define PAPI_ROCM_MAX_COUNTERS (512)

#define ROCM_EVENTS_OPENED  (0x1)
#define ROCM_EVENTS_RUNNING (0x2)

typedef struct {
    char *name;
    char *descr;
    unsigned ntv_dev;
    unsigned ntv_id;
    int instance;
} ntv_event_t;

typedef struct ntv_event_table {
    ntv_event_t *events;
    unsigned count;
} ntv_event_table_t;

extern unsigned _rocm_lock;

#endif /* End of __COMMON_H__ */
