#include "timer.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/util/queue.h"
#include "../Threads/thread.h"

// ticks = freq x time
static int32_t ticks;

static repeating_timer_t timer;

int32_t timer_ticks(void) {
    return ticks;
}

/*
    Función que se llama por cada disparo del timer
*/
bool timer_interrupt_handler_func(repeating_timer_t *rt) {
    ticks++; // increase ticks
    //printf("current ticks: %d\n", ticks);

    thread_unblock();
    schedule();

    return true; // keep repeating
}



void initialize_timer(void) {
    // Configure the timer

    if (!add_repeating_timer_us(-1000000 / OUR_FREQ, timer_interrupt_handler_func, NULL, &timer)) {
        printf("Failed to add timer\n");
    }
}

void stop_timer(void) {
    cancel_repeating_timer(&timer);
}