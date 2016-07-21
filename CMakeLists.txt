cmake_minimum_required(VERSION 3.1)
project(Calendar)

#add_definitions(-std=c++11 --target=x86_64-linux-gnu)
#set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(calendar_run ${SOURCE_FILES})

include_directories(calendars)

add_subdirectory(calendars)
add_subdirectory(calendars_tests)

target_link_libraries(calendar_run calendars)


#if ($ENV{CLION_IDE})
#    message("Call cmake command from the CLion IDE")
#    set(CALENDAR_PATH_VAR "test")
#    set(CALENDAR_DIR_VAR "test")
#endif ()