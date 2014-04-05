#include "calendar_defs.h"
#include "Islamic.h"

Islamic::Islamic(int d) {
    if (d <= 227014) { // Date is pre-Islamic
        month = 0;
        day = 0;
        year = 0;
    }
    else {
        // Search forward year by year from approximate year
        year = (d - 227014) / 355;
        while (d >= Islamic(1,1, year +1))
            year++;
        // Search forward month by month from Muharram
        month = 1;
        while (d > Islamic(month, LastDayOfIslamicMonth(month, year), year))
            month++;
        day = d - Islamic(month,1, year) + 1;
    }
}

int Islamic::IslamicLeapYear(int year)
{
    if ((((11 * year) + 14) % 30) < 11)
        return 1;
    else
        return 0;
}

int Islamic::LastDayOfIslamicMonth(int month, int year)
{
    if (((month % 2) == 1) || ((month == 12) && IslamicLeapYear(year)))
        return 30;
    else
        return 29;
}

Islamic::operator int() { // Computes the absolute date from the Islamic date.
    return (day                      // days so far this month
            + 29 * (month - 1)       // days so far...
            + month/2                //            ...this year
            + 354 * (year - 1)       // non-leap days in prior years
            + (3 + (11 * year)) / 30 // leap days in prior years
            + 227014);                // days before start of calendar
}

