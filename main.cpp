#include <iostream>
#include "GregorianCalendar.h"
#include "IslamicCalendar.h"
#include "JulianCalendar.h"
#include "HebrewCalendar.h"

using namespace std;

const char *DayName[7] =
        {
                "Sunday",
                "Monday",
                "Tuesday",
                "Wednesday",
                "Thursday",
                "Friday",
                "Saturday"
        };

int main() {
    int day;
    int month;
    int year;

    cout << "Enter year (>0): ";
    cin >> year;
    cout << "Enter month (1..12): ";
    cin >> month;
    cout << "Enter day (1.."
            << GregorianCalendar::LastMonthDay(month, year) << "): ";
    cin >> day;

    GregorianCalendar gregorian_calendar(month, day, year);
    int a = gregorian_calendar;
    cout << gregorian_calendar << " = " << a << " = "
            << DayName[gregorian_calendar % 7] << "\n";

    cout << "    = GregorianCalendar date " << gregorian_calendar
            << " = absolute date " << a
            << "last day" << gregorian_calendar.LastMonthDay(12, 2015) << "\n";

    JulianCalendar julian_calendar(a);
    a = julian_calendar;
    cout << "    = JulianCalendar date " << julian_calendar << " = absolute date " << a
            << "last day" << julian_calendar.LastMonthDay(12, 2015) << "\n";

    HebrewCalendar hebrew_calendar(a);
    a = hebrew_calendar;
    cout << "    = HebrewCalendar date " << hebrew_calendar << " = absolute date " << a << "\n";

    IslamicCalendar islamic_calendar(a);
    a = islamic_calendar;
    cout << "    = IslamicCalendar date " << islamic_calendar << " = absolute date " << a << "\n";

    cout << "    = julian_calendar date " << julian_calendar << "\n";
    cout << "    = hebrew_calendar date " << hebrew_calendar << "\n";
    cout << "    = islamic_calendar date " << islamic_calendar << "\n";


    return 0;
}
