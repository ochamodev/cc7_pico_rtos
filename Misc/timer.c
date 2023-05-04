#include "Misc/timer.h"
#include "hardware/timer.h"

static int32_t ticks;

void init_timer() {
    timer_config_t config = timer_get_default_config();
    timer_init(TIMER_INDEX, &config);

    uint32_t alarm_time

}