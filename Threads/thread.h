#ifndef THREADS_THREAD_H
#define THREADS_THREAD_H
#include "pico/util/queue.h"
#include <stdint.h>

// QUEUE
static queue_t ready_list;
static queue_t wait_list;
// QUEUE

#define THREAD_LIST_SIZE 32


/* States in a thread's life cycle. */
typedef enum thread_status {
    THREAD_RUNNING,     /* Running thread. */
    THREAD_READY,       /* Not running but ready to run. */
    THREAD_BLOCKED,     /* Waiting for an event to trigger. */
    THREAD_DYING        /* About to be destroyed. */
} thread_status;

/* Thread identifier type.
   You can redefine this to whatever type you like. */
typedef int tid_t;
#define TID_ERROR ((tid_t) -1)          /* Error value for tid_t. */

typedef struct pico_thread {
  tid_t tid; // Thread Id
  thread_status status; // Thread status
  void (*func)(void*); // Thread function to run
  void *args; // Threads functions args
} pico_thread;

void initialize_scheduler(void);

pico_thread* thread_init (void* func, tid_t id, void* thread_args);
void add_to_wait_list(pico_thread* t);
pico_thread* remove_from_waiting_list(void);
pico_thread* remove_from_ready_list(void);
/*
  Función que pasa de la wait list a la ready list
*/
void thread_unblock();
void add_to_ready_list(pico_thread* t);
void thread_start (void);

void schedule(void);

#endif /* threads/thread.h */
