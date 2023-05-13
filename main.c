#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/irq.h"
#include "Misc/timer.h"

int main() {

    // Initialize standard library
    stdio_init_all();
    
    initialize_timer();
    
    while (1) {
        printf("timer finished");
        break;
    }
    return 0;
}