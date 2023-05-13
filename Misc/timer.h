#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include "pico/stdlib.h"
// aka 133Mhz 
#define OUR_FREQ 133000000

#define TIMER_INTERVAL_US 1000000 // Timer interval in microseconds


int32_t timer_ticks(void);
int32_t timer_elapsed(int32_t);

/*
* function that configures the system timer
*/
void initialize_timer(void);

void add_timer_task();

void stop_timer();

bool timer_interrupt_handler_func(repeating_timer_t *rt);

#endif
