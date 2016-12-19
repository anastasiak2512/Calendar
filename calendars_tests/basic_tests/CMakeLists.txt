include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicCalendarTests
        basic_check.cpp
        calendar_check.cpp date_checks.cpp)

target_link_libraries(runBasicCalendarTests gtest gtest_main)
target_link_libraries(runBasicCalendarTests calendars)
