cmake_minimum_required(VERSION 2.8)

project(calendars)

add_definitions(-std=c++11)

set(HEADER_FILES
    calendar_defs.h
    General.h
    GregorianCalendar.h
    JulianCalendar.h
    IslamicCalendar.h
    HebrewCalendar.h
    )

set(SOURCE_FILES
    calendar_defs.cpp
    Calendar.cpp
    General.cpp
    GregorianCalendar.cpp
    JulianCalendar.cpp
    IslamicCalendar.cpp
    HebrewCalendar.cpp
    )

add_library(calendars STATIC ${SOURCE_FILES} ${HEADER_FILES})
