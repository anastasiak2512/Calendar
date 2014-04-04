#include <iostream>
#include "calendar_defs.h"

class Gregorian : public Calendar {
public:
    Gregorian(int d);
    Gregorian(int m, int d, int y): Calendar(m,d,y) {};

    operator int();

    //    LastDayOfGregorianMonth computes the last date of the month for the Gregorian calendar.
    static int LastDayOfGregorianMonth(int month, int year);
    Gregorian NthXday(int n, int x, int month, int year, int day = 0);
};
