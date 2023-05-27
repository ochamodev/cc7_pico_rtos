#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/irq.h"
#include "Misc/timer.h"
#include "Threads/thread.h"

void setup_sample_threads(void);

int main() {

    // Initialize standard library
    stdio_init_all();
    
    initialize_timer();
    initialize_scheduler();
    setup_sample_threads();

    while (1) {
        printf("timer finished");
    }
    return 0;
}

typedef struct thread_args {
    int n;
} thread_args;

void factorial(void* arg) {
    thread_args* s = (thread_args*) arg;
    int32_t f = 1;
    for (int i = 2; i <= s->n; i++) {
        f *= i;
    }
    printf("Calculo factorial: %d", f);
}

void fibonacci(void* arg) {
    thread_args* s = (thread_args*) arg;
    int32_t n = s->n;
    if (n == 0) return;
    if (n == 1) return;

    int n1 = 0, n2 = 1, n3 = 0;

    for (int i = 2; i <= n; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    printf("Calculo fibonacci: %d", n3);
}

void setup_sample_threads() {
    thread_args* thread_args1;
    thread_args1->n = 3;
    thread_args* thread_args2;
    thread_args2->n = 4;
    thread_args* thread_args3;
    thread_args3->n = 5;
    pico_thread* t1 = thread_init(factorial, 1, thread_args1);
    pico_thread* t2 = thread_init(factorial, 2, thread_args2);
    pico_thread* t3 = thread_init(fibonacci, 3, thread_args3);

    add_to_wait_list(t1);
    add_to_wait_list(t2);
    add_to_wait_list(t3);
}