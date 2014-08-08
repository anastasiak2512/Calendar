cmake_minimum_required(VERSION 2.8)
project(Calendar)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(calendar_run ${SOURCE_FILES})

include_directories(calendars)

add_subdirectory(calendars)

target_link_libraries(calendar_run calendars)
