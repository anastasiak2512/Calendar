#include <iostream>

#include "calendar_defs.h"

#define MONTH_LEN 31
#define MAX_MONTH_LEN MONTH_LEN

static const int year_max_len = 366;

class JulianCalendar : public Calendar {
public:
    JulianCalendar(int date);

    JulianCalendar(int m, int d, int y) : Calendar(m, d, y) {
    };

    int LastMonthDay(int month, int year);

    // Computes the absolute date from the Julian date.
    operator int();

//    int getDefYearLen();
//
//    void setMark(int mark);
};