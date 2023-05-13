#include "timer.h"
#include <stdio.h>
#include "pico/stdlib.h"

// ticks = freq x time
static int32_t ticks;

static repeating_timer_t timer;

int32_t timer_ticks(void) {
    return ticks;
}

bool timer_interrupt_handler_func(repeating_timer_t *rt) {
    ticks++; // increase ticks
    if (ticks > 20) {
        return false;
    }

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