#include "JulianCalendar.h"

static const int JulianEpoch = -2;

JulianCalendar::JulianCalendar(int date) {
    year = (date + JulianEpoch) / year_max_len;
    while (date >= JulianCalendar(1, 1, year + 1))
        year++;
    month = 1;
    while (date > JulianCalendar(month, LastMonthDay(month, year), year))
        month++;
    int JulDay = JulianCalendar(month, 1, year);
    day = date - JulDay + 1;
}

//TODO: introduce constants
int JulianCalendar::LastMonthDay(int month, int year)
{
    switch (month) {
        case 2:
            if ((year % 4) == 0)
                return 29;
            else
                return 28;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        default:
            return MAX_MONTH_LEN;
    }
}

JulianCalendar::operator int() {
    int N = day;                         // days this month
    for (int m = month - 1;  m > 0; m--) // days in prior months this year
        N = N + LastMonthDay(m, year);
    return
            (N                     // days this year
                    + 365 * (year - 1)    // days in previous years ignoring leap days
                    + (year - 1)/4        // leap days before this year...
                    + JulianEpoch);       // days elapsed before absolute date 1
}
