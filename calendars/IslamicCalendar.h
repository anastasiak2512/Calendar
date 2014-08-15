#include <iostream>
#include "calendar_defs.h"

class IslamicCalendar : public Calendar {
public:
    IslamicCalendar(int m, int d, int y) : Calendar(m, d, y) {
    };

    IslamicCalendar(int d);

    int IslamicLeapYear(int year);
    int LastMonthDay(int month, int year);

    operator int();
};