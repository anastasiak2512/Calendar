cmake_minimum_required(VERSION 2.8)

project(calendars)

add_definitions(-std=c++11)

set(HEADER_FILES
    calendar_defs.h
    Calendar.h
    General.h
    Gregorian.h
    Julian.h
    Islamic.h
    Hebrew.h
    )

set(SOURCE_FILES
    calendar_defs.cpp
    Calendar.cpp
    General.cpp
    Gregorian.cpp
    Julian.cpp
    Islamic.cpp
    Hebrew.cpp
    )

add_library(calendars STATIC ${SOURCE_FILES})

