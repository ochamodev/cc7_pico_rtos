cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(project_name)

pico_sdk_init()

add_executable(cc7_rtos_pintos
    main.c
)

# Add pico_stdlib library, add more if used
target_link_libraries(cc7_rtos_pintos pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(cc7_rtos_pintos 1)
pico_enable_stdio_uart(cc7_rtos_pintos 0)

# Need to generate UF2 file for upload to RP2040
pico_add_extra_outputs(cc7_rtos_pintos)