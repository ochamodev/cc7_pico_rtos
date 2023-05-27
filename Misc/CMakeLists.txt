set(timer_utils_files
    timer.c
    timer.h
)

add_library(Misc_timer ${timer_utils_files})
target_link_libraries(Misc_timer pico_stdlib)
target_include_directories(Misc_timer PUBLIC "../Threads/")