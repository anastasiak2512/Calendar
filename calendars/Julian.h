#include <iostream>
#include "calendar_defs.h"

class Julian : public Calendar {
public:
    Julian(int d);
    Julian(int m, int d, int y): Calendar(m,d,y) {};

    int LastMonthDay(int month, int year);

    // Computes the absolute date from the Julian date.
    operator int();
};
