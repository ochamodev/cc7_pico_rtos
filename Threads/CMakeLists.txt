set(thread_utils_files
    thread.c
    thread.h
)

add_library(Threads_utils ${thread_utils_files})
target_link_libraries(Threads_utils pico_stdlib)
#target_link_libraries(Threads_utils Utils)
#target_include_directories(Threads_utils PUBLIC "../Utils/")