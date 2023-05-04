#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

int32_t timer_ticks(void);
int32_t timer_elapsed(int32_t);


void init_timer(void);

#endif