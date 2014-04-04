#include "Julian.h"
#include "calendar_defs.h"

Julian::Julian(int d) {
    // Search forward year by year from approximate year
    year = (d + JulianEpoch)/366;
    while (d >= Julian(1,1,year+1))
        year++;
    // Search forward month by month from January
    month = 1;
    while (d > Julian(month, LastDayOfJulianMonth(month,year), year))
        month++;
    day = d - Julian(month,1,year) + 1;
}

int Julian::LastDayOfJulianMonth(int month, int year)
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
        default: return 31;
    }
}

Julian::operator int() {
    int N = day;                         // days this month
    for (int m = month - 1;  m > 0; m--) // days in prior months this year
        N = N + LastDayOfJulianMonth(m, year);
    return
            (N                     // days this year
                    + 365 * (year - 1)    // days in previous years ignoring leap days
                    + (year - 1)/4        // leap days before this year...
                    + JulianEpoch);       // days elapsed before absolute date 1
}
