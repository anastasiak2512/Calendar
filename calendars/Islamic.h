#include <iostream>
#include "calendar_defs.h"

class Islamic : public Calendar {
public:
    Islamic(int m, int d, int y) : Calendar(m,d,y) {};
    Islamic(int d);

    int IslamicLeapYear(int year);
    int LastDayOfIslamicMonth(int month, int year);

    operator int();
};