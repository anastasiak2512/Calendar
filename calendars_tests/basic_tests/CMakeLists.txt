cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runBasicCalendarTests basic_check.cpp)

target_link_libraries(runBasicCalendarTests gtest gtest_main)
target_link_libraries(runBasicCalendarTests calendars)
