find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIR})

add_executable(calendar_cal_test calendar_calc_test.cpp)

#target_link_libraries(calendar_cal_test ${Boost_LIBRARIES})
target_link_libraries(calendar_cal_test calendars)


