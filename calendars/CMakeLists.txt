project(calendars)

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
