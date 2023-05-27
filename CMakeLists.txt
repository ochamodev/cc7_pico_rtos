cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(cc7_rtos_pico)

pico_sdk_init()


add_subdirectory(Misc)
#add_subdirectory(Utils)
add_subdirectory(Threads)

add_executable(cc7_rtos_pintos
    main.c
)

# Add pico_stdlib library, add more if used
target_link_libraries(cc7_rtos_pintos pico_stdlib Misc_timer Threads_utils)

# enable usb output, disable uart output
pico_enable_stdio_usb(cc7_rtos_pintos 1)
pico_enable_stdio_uart(cc7_rtos_pintos 0)

# Need to generate UF2 file for upload to RP2040
pico_add_extra_outputs(cc7_rtos_pintos)