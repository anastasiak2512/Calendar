#include <iostream>
#include "calendar_defs.h"


#define julianYearLen 366

class JulianCalendar : public Calendar {
public:
    JulianCalendar(int d);

    JulianCalendar(int m, int d, int y) : Calendar(m, d, y) {
    };

    int LastMonthDay(int month, int year);

    // Computes the absolute date from the Julian date.
    operator int();
};
