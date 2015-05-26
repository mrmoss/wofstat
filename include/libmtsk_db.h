/*
 */

/*	
 * Copyright (c) 2008, 2011, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_LIBMTSK_DB_H
#define	_LIBMTSK_DB_H

#pragma ident	"@(#)libmtsk_db.h	1.10	11/04/19 SMI"

#include <proc_service.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mtsk_db_spawn_func_t {
    char *symbol_name;
    int   o_register_num;
} mtsk_db_spawn_func_t;

/*
 * Error codes returned by libmtsk routines.
 */
 
typedef enum {
    MTSK_DB_NO_CAP=-1,       /* This function is not supported in libmtsk_db */
    MTSK_DB_OK=0,            /* Everything is fine */
    MTSK_DB_VERSION_ERROR,   /* This libmtsk_db cannot support the a.out */
    MTSK_DB_NOT_OMP_THREAD,  /* This thread is not an openmp thread */
    MTSK_DB_NOT_IN_PARALLEL, /* Not in parallel region */
    MTSK_DB_ADDRESS_INVALID, /* If address provided by dbx is invalid */
    MTSK_DB_ERROR,           /* Unknown error, like ps_read failed etc. */
    MTSK_DB_LIBMTSK_HANDLE_INVALID,   /*libmtsk handle is invalid*/    
    MTSK_DB_THREAD_HANDLE_INVALID,    /*thread handle is invalid*/
    MTSK_DB_PARALLEL_HANDLE_INVALID,  /*parallel region handle is invalid*/
    MTSK_DB_TASK_HANDLE_INVALID,      /*task handle is invalid*/
    MTSK_DB_ATTRID_INVALID,            /*attr_id is invalid*/
    MTSK_DB_PAR_ID_INVALID,           /*task_id is invalid*/    
    MTSK_DB_TASK_ID_INVALID,           /*task_id is invalid*/    
    MTSK_DB_EVENT_ID_INVALID,          /*event_id is invalid*/
    MTSK_DB_NO_CURRENT_LOOP            /*the thread is not working on openmp loop*/
} mtsk_db_errno_t;


/*
 * Called by the debugger once to initialize the debug support library.
 * Return handle, that should be used with subsequent queries.
 */

void *mtsk_db_init (struct ps_prochandle *);

/*
 * Called to destroy the handle, and clean up.
 */

void mtsk_db_fini (void *handle);

/*
 * This is called when dbx is about to resume the process, *or* 
 * immediately after dbx has stopped the process.  Either way it
 * indicates that the library needs to flush anyvcached values 
 * from the process that might change.
 */  

void mtsk_db_proc_flush(void *handle);
    
/*
 * Returns a list of items where each item includes the name of a 
 * function which can spawn a new parallel region, and which parameter 
 * holds the pointer to the mfunction.  This is used to support
 * stepping into a region in dbx.
 *
 * This function allocates an array of return type structure
 * using malloc. The count is set to the number of elements in the
 * array. It is the responsibility of the caller to free the returned
 * structure.
 */

struct mtsk_db_spawn_func_t *mtsk_db_spawn_funcs(int *count);
    
/*
 * This is to support the ability to print OMP thread
 * private variables in dbx.  A thread private variable
 * "x" will have a global variable "__tls_x" (or similar)
 * defined by the front end.  This will hold some kind
 * of pointer.  Dbx will need to used stabs info to
 * correlate "x" and "__tls_x", and then read the value
 * in "__tls_x" and use this value as 'base' when calling
 * libmtsk_db_thread_private_addr().  The address
 * in tp_var is the address of the instance of "x" for
 * the given thread.  Note: dbx will have no knowledge
 * of any mangling scheme used to go from the name "x"
 * to the name "__tls_x" (or whatever name it turns out
 * to be) The relationship between these two symbol names
 * will be recorded in the debug information.
 * 
 * For Fortran common blocks dbx will pass in the base
 * address of the common block, and the API will 
 * attempt to return the base address of the 
 * thread private chunk for the given tid. Individual
 * field offsets can be obtained by dbx from the stabs.
 * 
 * Return one of the error codes in libmtsk_db_errno_t
 * On success (MTSK_DB_OK), tp_var will contain the
 * address of the thread private data for this thread.
 */

mtsk_db_errno_t mtsk_db_thread_private_var_addr(void *handle,
                                                pthread_t tid,
                                                unsigned long base,
                                                unsigned long *tp_var);
    
/*
 * This function will be called only for the bottom
 * "slave" frame on a stack.  If the master and slave
 * frames are on the same thread, dbx will find the
 * master frame without help.
 *  
 * Dbx provides the thread id of a slave thread which
 * was assigned by the libmtask scheduler.
 * If the tid is not currently assigned to a parallel
 * region, then this function returns -1 as a return value.
 * Otherwise, it returns 0 and assigns a thread id, and
 * a frame pointer value to the reference parameters.
 * 
 * These point to the master frame/thread (or to slightly
 * newer frames).  Dbx will search backwards on the stack
 * from this point looking for the first frame of the function
 * that dbx knows is the "parent" for the mfunction where it
 * started.
 * 
 * Return one of the error codes in in libmtsk_db_errno_t
 * On success (MTSK_DB_OK), solaris_tid and the FP will
 * contain valid information
 */

mtsk_db_errno_t mtsk_db_slave_to_master(void *handle,
                                        pthread_t slave_tid,
                                        pthread_t *solaris_tid,
                                        unsigned long *FP);

/*
 * The new interfaces added in libmtsk_db is to help dbx show openmp items. Currently the items
 * include thread, parallel region, worksharing constructs and task.
 * 
 * For each item, dbx uses attribute id to query attributes. That is to make the interface easy 
 * to keep backward compatibility. 
 * 
 * The attribute is saved in the memory pointed by attr_data. This memory should be allocated by 
 * dbx. Different attribute has different data type. The types are listed in the comments for 
 * attribute id.
 *
 * Each API will return 0 if success. Otherwise, the return value indicates the fail reason.
 *
 */


/****************************
 
 API for versioning
  
 ***************************/ 

typedef enum {
    UNKNOWN = 0,
    ARCHIVE_LIB_7_1,
    SHARED_LIB_8_1,
    SHARED_LIB_8_2
} library_version;

mtsk_db_errno_t mtsk_db_get_version(void * p_libmtsk_handle, library_version * p_version);

/*************************
  
  APIs for omp thread.
 
 ************************/

/*
 * This function get /thread_handle/ of given omp thread whose pthread id is /tid/. It returns 0 for success.
 * It may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID  
 * MTSK_DB_NOT_OMP_THREAD
 */
  
mtsk_db_errno_t mtsk_db_get_thread_handle(void * p_libmtsk_handle, pthread_t tid, psaddr_t * thread_handle);


typedef enum{
   /* 
    * data: current parallel region handle
    * type: psaddr_t
    */
   MTSK_THREAD_PAR_REG,   
   /*
    * data: current task handle
    * type: psaddr_t
    */ 
   MTSK_THREAD_TASK_REG,
   /*
    * data: thread state
    * type: MT_THR_STATE 
    */ 
   MTSK_THREAD_STATE,     
   /*
    * data: omp thread tid in current team.
    *       it's always from 0 to teamsize-1
    *       team_tid equals 0 means this is a master thread. 
    * type: int32_t
    */ 
   MTSK_THREAD_TEAM_TID,
   /*
    * data: pthread id for given team
    * type: pthread_t
    */
   MTSK_THREAD_TID

} MTSK_THREAD_ATTR_ID;


/* [THR_STAT] */
/*
 * This enum lists the states recorded internally by libmtsk.  
 */

typedef enum {
    MT_THR_NO_STATE = 0,      /* Not initialized */

    MT_THR_OVHD_STATE = 1,    /* Overhead */
    MT_THR_WORK_STATE = 2,    /* Useful work, excluding reduction, master, 
                                 single, critical */
    MT_THR_IBAR_STATE = 3,    /* In an implicit barrier */
    MT_THR_EBAR_STATE = 4,    /* In an explicit barrier */
    MT_THR_IDLE_STATE = 5,    /* Slave waiting for work */
    MT_THR_SERIAL_STATE = 6,  /* thread not in any OMP parallel region 
                                 (initial thread only) */
    MT_THR_REDUC_STATE = 7,   /* Reduction */
    MT_THR_LKWT_STATE = 8,    /* Waiting for lock */
    MT_THR_CTWT_STATE = 9,    /* Waiting to enter critical region */
    MT_THR_ODWT_STATE = 10,   /* Waiting to execute an ordered region */
    MT_THR_ATWT_STATE = 11,   /* Waiting to enter an atomic region */
    MT_THR_TSKWT_STATE = 12,  /* Waiting for child tasks finishing */

    MT_THR_LAST_STATE
} MT_THR_STATE;

/*
 * This function gets thread /attr_data/ according to /attr_id/. Dbx needs to provide /thread_handle/ for target thread.
 *
 * It may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_THREAD_HANDLE_INVALID
 * MTSK_DB_ATTRID_INVALID
 */

mtsk_db_errno_t mtsk_db_get_thread_attribute(void * p_libmtsk_handle, psaddr_t thread_handle, MTSK_THREAD_ATTR_ID attr_id, void * attr_data);

/*
 * The only attribute ID allowed now is MTSK_THREAD_TEAM_TID.
 */

mtsk_db_errno_t mtsk_db_get_thread_attribute_in_parallel_region(void * p_libmtsk_handle, psaddr_t thread_handle, psaddr_t parallel_handle, MTSK_THREAD_ATTR_ID attr_id, void * attr_data);

/************************************
 
  APIs for omp parallel region.
 
 *************************************/


/*
 * This function gets /parallel_handle/ of a parallel region according to its /par_id/. 
 * It may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_PAR_ID_INVALID
 */ 

mtsk_db_errno_t mtsk_db_get_parallel_handle(void * p_libmtsk_handle, uint64_t par_id, psaddr_t * parallel_handle);

/*
 * This is the type for dbx callback function. Dbx can define such functions to deal with each handle passed by libmtsk_db.
 */

typedef int mtsk_db_iterator_func(psaddr_t handle, void *paramters);

/*
 * This function goes through active parallel regions and call /callback_func/ with the parallel handle and /callback_data/
 * for each region. 
 * With these active parallel regions and their parent attribute, dbx can explore all parallel regions 
 * and build the parallel region tree.
 * It may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 *
 * NOTE:If the callback function returns negative value, the iterate function will return MTSK_DB_OK immediately.
 */

mtsk_db_errno_t mtsk_db_active_parallel_iterate(void * p_libmtsk_handle, mtsk_db_iterator_func * callback_func, void * callback_data);

typedef enum{
    /*
     * data: parallel region id
     * type: uint64_t
     */
    MTSK_PARALLEL_ID,            
    /*
     * data: number of threads in current team 
     * type: uint16_t
     */
    MTSK_PARALLEL_TEAM_SIZE,
    /*
     * data: pc for instruction of MasterFunction call
     *       It can be resolved to file name and line number of omp pragma
     *       by dbx using debugging information
     * type: psaddr_t
     *
     */
    MTSK_PARALLEL_LOCATION,
    /*
     * data: handle for parent parallel region
     * type: psaddr_t
     */
    MTSK_PARALLEL_PARENT
}MTSK_PARALLEL_ATTR_ID;

/*
 * This function gets parallel /attr_data/ according to /attr_id/.  The target 
 * parallel region is specified by /parallel_handle/.
 *
 * This function may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_PARALLEL_HANDLE_INVALID
 * MTSK_DB_ATTRID_INVALID
 */

mtsk_db_errno_t mtsk_db_get_parallel_attribute(void * p_libmtsk_handle, psaddr_t parallel_handle,  MTSK_PARALLEL_ATTR_ID attr_id, void * attr_data);

/*
 * This function goes through all threads in the team and call /callback_func/ with thread handle and /callback_data/ for each thread.
 *
 * It may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_PARALLEL_HANDLE_INVALID
 *
 * NOTE:If the callback function returns negative value, the iterate function will return MTSK_DB_OK immediately.
 */

mtsk_db_errno_t mtsk_db_team_thread_iterate(void * p_libmtsk_handle, psaddr_t parallel_handle, mtsk_db_iterator_func * callback_func, void * callback_data);

/************************************
 
  APIs for omp loop.
 
 *************************************/
 
 /*
  * This function gets /loop_handle/ for the openmp loop that /current_thread/ is working on.
  * It may fail if:
  * MTSK_DB_LIBMTSK_HANDLE_INVALID
  * MTSK_DB_NOT_OMP_THREAD
  * MTSK_DB_NO_CURRENT_LOOP
  */  

mtsk_db_errno_t mtsk_db_get_current_loop(void * p_libmtsk_handle, pthread_t current_thread, psaddr_t * loop_handle);

typedef enum
{
    INDEX_INT = 0,
    INDEX_UINT,
    INDEX_LL,
    INDEX_ULL,
    INDEX_SH,
    INDEX_USH,
    INDEX_CH,
    INDEX_UCH
} indexType_t;

typedef union loop_index_type
{
    int i;
    unsigned int ui;
    long long ll;
    unsigned long long ull;
    short int sh;
    unsigned short int ush;
    char ch;
    unsigned char uch;
} loopIndex_t;

typedef enum
{
    SCHEDTYPE_NONE = 0,
    SCHEDTYPE_STATIC,
    SCHEDTYPE_SELF,
    SCHEDTYPE_GSS,
    SCHEDTYPE_FACTORING,
    SCHEDTYPE_AFFINITY,
    SCHEDTYPE_NUMCHUNKS,

    /* For IROPT internal use */
    SCHEDTYPE_INC_TRIANGULAR,
    SCHEDTYPE_INC_LOWER_TRIANGULAR, 
    SCHEDTYPE_DEC_TRIANGULAR,

    /* OpenMP */
    SCHEDTYPE_OMP_STATIC,
    SCHEDTYPE_OMP_GUIDED,
    SCHEDTYPE_OMP_DYNAMIC,
    SCHEDTYPE_OMP_RUNTIME,

    /* NUMA */
    SCHEDTYPE_NUMA,

    /* Other */
    SCHEDTYPE_OMP_AUTO

} sun_sched_t;

typedef enum{
    /*
     * data: flag for ordered loop
     *       It is set to 1 if the loop is ordered. Otherwise it is set to 0.
     * type: int 
     */
    MTSK_LOOP_HAS_ORDER,
    /*
     * data: type of loop index
     *       This is used by dbx to get correct lower bound and upper bound value
     *       from data passed by libmtsk_db
     * type: indexType_t
     */
    MTSK_LOOP_INDEX_TYPE, 
    /*
     * data: loop lower bound
     * type: loopIndex_t
     */
    MTSK_LOOP_LOWER_BOUND,
    /*
     * data: loop upper bound     
     * type: loopIndex_t
     */
    MTSK_LOOP_UPPER_BOUND,
    /*
     * data: loop step
     *       Note: Loop step should be a corresponding signed type to loop index.
     *             This work well in most cases. But it will still display wrong
     *             result if the step is a big unsigned value. 
     *             Libmtsk does not care whether the step is signed or unsigned.
     * type: loopIndex_t
     */
    MTSK_LOOP_STEP,
    
    /*
     * data: loop chunk
     * type: loopIndex_t
     */
    MTSK_LOOP_CHUNK,
    
    /*
     * data: loop scheduling type
     *       Note: only openmp scheduling type should be displayed
     * type: sun_sched_t
     */
    
    MTSK_LOOP_SCHEDULE_TYPE,
    
    /*
     * data: omp loop location
     *       That is the pc for call instruction of libmtsk entry function for openmp loop
     *       It may be the same as parallel location if it is a combined "parallel for" pragma.     
     */
    MTSK_LOOP_LOCATION
    
}MTSK_LOOP_ATTR_ID;

/*
 * This function gets loop /attr_data/ according to /attr_id/.  The target 
 * loop is specified by /parallel_handle/.
 *
 * This function may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_LOOP_HANDLE_INVALID
 * MTSK_DB_ATTRID_INVALID
 */

mtsk_db_errno_t mtsk_db_get_loop_attribute(void * p_libmtsk_handle, psaddr_t loop_handle, MTSK_LOOP_ATTR_ID attr_id, void * attr_data);

/***********************
 
  APIs for omp task.
 
 **********************/

/*
 * This function gets /task_handle/ for omp task entity according to its /task_id/.
 * It will fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_TASK_ID_INVALID
 */
 
mtsk_db_errno_t mtsk_db_get_task_handle(void * p_libmtsk_handle, uint64_t task_id, psaddr_t * task_handle);

/*
 * This function goes through all tasks currently being executed in given parallel region and calls /callback_func/ with
 * task handle and /callback_data/ for each task.
 *
 * It may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_PARALLEL_HANDLE_INVALID
 *
 * NOTE:If the callback function returns negative value, the iterate function will return MTSK_DB_OK immediately.
 */

mtsk_db_errno_t mtsk_db_active_task_iterate(void * p_libmtsk_handle, psaddr_t parallel_handle, mtsk_db_iterator_func * callback_func,void * callback_data);

/*
 * This function goes through all tasks created but not executed in given parallel region and calls /callback_func/ with
 * task handle and /callback_data/ for each task.
 *
 * The enqueued tasks and active tasks cover all leaves on the task tree. So dbx can explore all tasks from these 2 lists.
 * 
 * It may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_PARALLEL_HANDLE_INVALID
 *
 * NOTE:If the callback function returns negative value, the iterate function will return MTSK_DB_OK immediately.
 */
mtsk_db_errno_t mtsk_db_enqueued_task_iterate(void * p_libmtsk_handle, psaddr_t parallel_handle, mtsk_db_iterator_func * callback_func, void * callback_data);

typedef enum{
    /*
     * data: task id
     * type: uint64_t
     */
    MTSK_TASK_ID,
    /*
     * data: task type
     * type: MT_TASK_TYPE 
     */
    MTSK_TASK_TYPE,
    /*
     * data: task state
     * type: MT_TASK_STATE
     */
    MTSK_TASK_STATE,
    /*
     * data: handle of thread executing the task
     * type: psaddr_t 
     */
    MTSK_TASK_EXEC_THREAD,
    /*
     * data: pc for instruction of OmptaskFunction call
     * type: psaddr_t
     */
    MTSK_TASK_LOCATION,
    /*
     * data: number of unfinished children
     * type: int
     */
    MTSK_NUM_UNFINISHED_CHILDREN,
    /*
     * data: handle of parent task
     * type: psaddr_t
     */
    MTSK_TASK_PARENT 
}MTSK_TASK_ATTR_ID;

typedef enum{
    MT_TASK_EXPLICIT,
    MT_TASK_IMPLICIT 
}MT_TASK_TYPE;

typedef enum{
    MT_TASK_CREATED,
    MT_TASK_EXECUTING,
    MT_TASK_WAITING,
    MT_TASK_FINISHED,
}MT_TASK_STATE;

/*
 * This function gets task /attr_data/ according to /attr_id/. 
 * The target task is specified by /task_handle/.
 * 
 * This function may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_TASK_HANDLE_INVALID
 * MTSK_DB_ATTRID_INVALID
 */
mtsk_db_errno_t mtsk_db_get_task_attribute(void * p_libmtsk_handle, psaddr_t task_handle, MTSK_TASK_ATTR_ID attr_id, void * attr_data);

/***********************
 
  APIs for omp events.

 ***********************/ 
typedef uint64_t MTSK_DB_EVENT_ID;
#define OMP_EXPLICIT_BARRIER_ENTER 0x000001
#define OMP_EXPLICIT_BARRIER_EXIT  0x000002
#define OMP_IMPLICIT_BARRIER_ENTER 0x000004
#define OMP_IMPLICIT_BARRIER_EXIT  0x000008
#define OMP_TASKWAIT_ENTER         0x000010
#define OMP_TASKWAIT_EXIT          0x000020
#define OMP_ORDERED_BEGIN          0x000040
#define OMP_ORDERED_ENTER          0x000080
#define OMP_ORDERED_EXIT           0x000100
#define OMP_CRITICAL_BEGIN         0x000200
#define OMP_CRITICAL_ENTER         0x000400
#define OMP_CRITICAL_EXIT          0x000800
#define OMP_ATOMIC_BEGIN           0x001000
#define OMP_ATOMIC_EXIT            0x002000
#define OMP_FLUSH_IMPLICIT         0x004000
#define OMP_FLUSH_EXPLICIT         0x008000
#define OMP_MASTER_BEGIN           0x010000
#define OMP_MASTER_END             0x020000
#define OMP_SINGLE_BEGIN           0x040000
#define OMP_SINGLE_END             0x080000
#define OMP_TASK_CREATE            0x100000
#define OMP_TASK_START             0x200000
#define OMP_TASK_FINISH            0x400000
#define OMP_EXPLICIT_BARRIER_ALLENTERED 0x0800000
#define OMP_IMPLICIT_BARRIER_ALLENTERED 0x1000000
#define OMP_THREAD_BEGIN 0x2000000
#define OMP_MAX_EVENT 0x2000000

/*
 * These functions enable/disable omp events on given thread.
 * Some events listed up may not be implemented. If so, the API will return an error.
 * The event_id can be a combination of events.
 * 
 * These functions may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_NOT_OMP_THREAD
 * MTSK_DB_EVENT_ID_INVALID
 */
mtsk_db_errno_t mtsk_db_monitor_omp_event(void * p_libmtsk_handle, pthread_t thread_id, int on_off, MTSK_DB_EVENT_ID event_id);

/*
 * These functions check if omp events specified /event_id/ is /enabled/ on given thread.
 * If the event_id is a combination of events, the result will be true only if all these events are enabled.
 *
 * This function may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 * MTSK_DB_NOT_OMP_THREAD
 * MTSK_DB_EVENT_ID_INVALID
 */

mtsk_db_errno_t mtsk_db_is_enabled_omp_thread_event(void * p_libmtsk_handle, pthread_t thread_id, MTSK_DB_EVENT_ID event_id, int32_t * enabled);

/*
 * stub fuctions for event monitoring.
 * These functions will be called by libmtsk at the event definition point when that event is monitored.
 *
 * The events for critical, ordered and atomic means:
 * - begin: Thread is going to start the waiting loop for critical/ordered/atomic
 * - enter: Thread finished the waiting and entered the protected area.  
 * - exit:  Thread left the protected area.
 *
 * The atomic does not have enter event. Currently, atomic is implemented the same as critical. But
 * if it is really implemented with atomic operations, there is no such entered status. So we only
 * provide begin and exit for atomic.
 *
 * For master and single, we have 2 events:
 * - begin: Thread entered the single area.
 * - end:   Thread left the single area.  
 *
 */

void mtsk_event_explicit_barrier_enter(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_explicit_barrier_allentered(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_explicit_barrier_exit(pthread_t thread_id, uint64_t pr_id);

void mtsk_event_implicit_barrier_enter(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_implicit_barrier_allentered(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_implicit_barrier_exit(pthread_t thread_id, uint64_t pr_id);

void mtsk_event_taskwait_enter(pthread_t thread_id, uint64_t task_id);
void mtsk_event_taskwait_exit(pthread_t thread_id, uint64_t task_id);

void mtsk_event_ordered_begin(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_ordered_enter(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_ordered_exit(pthread_t thread_id, uint64_t pr_id);

void mtsk_event_critical_begin(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_cirtical_enter(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_critical_exit(pthread_t thread_id, uint64_t pr_id);

void mtsk_event_atomic_begin(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_atomic_exit(pthread_t thread_id, uint64_t pr_id);

void mtsk_event_implicit_flush(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_explicit_flush(pthread_t thread_id, uint64_t pr_id);

void mtsk_event_master_begin(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_master_end(pthread_t thread_id, uint64_t pr_id);

void mtsk_event_single_begin(pthread_t thread_id, uint64_t pr_id);
void mtsk_event_single_end(pthread_t thread_id, uint64_t pr_id);

void mtsk_event_task_create(pthread_t thread_id, uint64_t task_id);
void mtsk_event_task_start(pthread_t thread_id, uint64_t task_id);
void mtsk_event_task_finish(pthread_t thread_id, uint64_t task_id);

void mtsk_event_thread_begin(pthread_t thread_id);

/*******************************
  
  APIs for serialize one region

 ********************************/
/*
 * This function will set the number of threads to 1 for next parallel region. 
 * After entering the paralle region, the number of threads will be restored.
 * So the next encountered parallel region will be parallelized.
 *
 * How to use this API?
 *
 * User needs to stop before the parallel region and issue the serialization command. 
 * After that, dbx call this function to serialize the parallel region. If user choose to
 * serialize next parallel regions meets by all team threads, the tid can be set to -1
 * to represent that.
 *
 * This function may fail if:
 * MTSK_DB_LIBMTSK_HANDLE_INVALID
 */

mtsk_db_errno_t mtsk_db_serialize_next_par_region(void * p_libmtsk_handle, pthread_t tid);


#ifdef __cplusplus
}
#endif

#endif	/* _LIBMTSK_DB_H */
