#include "General.h"
#include "Gregorian.h"

Gregorian::Gregorian(int d) {
    // Search forward year by year from approximate year
    year = d/366;
    while (d >= Gregorian(1,1, year +1))
        year++;
    // Search forward month by month from January
    month = 1;
    while (d > Gregorian(month, LastDayOfGregorianMonth(month, year), year))
        month++;
    day = d - Gregorian(month,1, year) + 1;
}

int Gregorian::LastDayOfGregorianMonth(int month,int year)
{
    switch (month) {
        case 2:
            if ((((year % 4) == 0) && ((year % 100) != 0))
                    || ((year % 400) == 0)) {
                return 29;
            }
            else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        default: return 31;
    }
}

/*
     The Gregorian date of nth x-day in month, year before/after optional day.
     x = 0 means Sunday, x = 1 means Monday, and so on.  If n<0, return the nth
     x-day before month day, year (inclusive).  If n>0, return the nth x-day
     after month day, year (inclusive).  If day is omitted or 0, it defaults
     to 1 if n>0, and month's last day otherwise.
*/
Gregorian Gregorian::NthXday(int n, int x, int month, int year, int day) {
    if (n > 0) {
        if (day == 0) {
            day = 1;
        }  // default for positive n
        return Gregorian
                ((7 * (n - 1)) + General::XdayOnOrBefore(6 + Gregorian(month, day, year), x));
    }
    else {
        if (day == 0) {
            day = LastDayOfGregorianMonth(month, year);
        };  // default for negative n
        return Gregorian
                ((7 * (n + 1)) + General::XdayOnOrBefore(Gregorian(month, day, year), x));
    }
}

Gregorian::operator int() { // Computes the absolute date from the Gregorian date.
    int N = day;           // days this month
    for (int m = month - 1;  m > 0; m--) // days in prior months this year
        N = N + LastDayOfGregorianMonth(m, year);
    return
            (N                    // days this year
                + 365 * (year - 1)   // days in previous years ignoring leap days
                + (year - 1)/4       // Julian leap days before this year...
                - (year - 1)/100     // ...minus prior century years...
                + (year - 1)/400);   // ...plus prior years divisible by 400
}
