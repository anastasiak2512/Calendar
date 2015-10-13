#include <iostream>
#include "calendar_defs.h"

class GregorianCalendar : public Calendar {
public:
    GregorianCalendar(int date);

    GregorianCalendar(int m, int d, int y) : Calendar(m, d, y) {
    };

    operator int();

    //    LastMonthDay computes the last date of the month for the Gregorian calendar.
    static int LastMonthDay(int month, int year);

    GregorianCalendar NthXday(int n, int x,
            int month, int year, int day = 0);

    int getDefYearLen() {
        return 356;
    }


    int get_general_day(int x, GregorianCalendar &calendar);
};

