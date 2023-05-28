#include "thread.h"

#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>

/* Random value for struct thread's `magic' member.
   Used to detect stack overflow.  See the big comment at the top
   of thread.h for details. */
#define THREAD_MAGIC 0xcd6abf4b

#define TIME_SLICE 243 /* Num. of timer ticks to give each thread. */
static unsigned thread_ticks; /* Num. of timer ticks since last yield.*/

void initialize_scheduler() {
   queue_init(&wait_list, sizeof(pico_thread), THREAD_LIST_SIZE);
   queue_init(&ready_list, sizeof(pico_thread), THREAD_LIST_SIZE);
}

pico_thread* thread_init(void* func, tid_t id, void* thread_args) {
   pico_thread* t = (pico_thread*)malloc(sizeof(pico_thread));
   t->func = func;
   t->status = THREAD_BLOCKED;
   t->tid = id;
   t->args = thread_args;
   printf("Se inserto un thread con id: %d", id);
   return t;
}

void add_to_wait_list(pico_thread* t) {
   queue_add_blocking(&wait_list, &t);
}

void add_to_ready_list(pico_thread* t) {
   queue_add_blocking(&ready_list, &t);
}

void remove_from_waiting_list(pico_thread* t) {
   queue_remove_blocking(&wait_list, t);
}

void remove_from_ready_list(pico_thread* t) {
   queue_remove_blocking(&ready_list, t);
}

void thread_unblock() {
   pico_thread* t;
   remove_from_waiting_list(t);
   t->status = THREAD_READY;
   add_to_ready_list(t);
}

void schedule() {
   pico_thread* t;
   remove_from_ready_list(t);
   // se ejecuta la función del thread
   t->status = THREAD_RUNNING;
   t->func(t->args);
   t->status = THREAD_DYING;
   //free(t);

}