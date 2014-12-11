#include "calendar_defs.h"
#include "HebrewCalendar.h"

static const int HebrewEpoch = -1373429;

HebrewCalendar::HebrewCalendar(int d) { // Computes the HebrewCalendar date from the absolute date.
    year = (d + HebrewEpoch) / 366; // Approximation from below.
    // Search forward for year from the approximation.
    while (d >= HebrewCalendar(7, 1, year + 1))
        year++;
    // Search forward for month from either Tishri or Nisan.
    if (d < HebrewCalendar(1, 1, year))
        month = 7;  //  Start at Tishri
    else
        month = 1;  //  Start at Nisan
    while (d > HebrewCalendar(month, (LastMonthDay(month, year)), year))
        month++;
    // Calculate the day by subtraction.
    day = d - HebrewCalendar(month, 1, year) + 1;
}

int HebrewCalendar::HebrewLeapYear(int year)
{
    if ((((7 * year) + 1) % 19) < 7)
        return 1;
    else
        return 0;
}

int HebrewCalendar::LastMonthOfHebrewYear(int year)
{
    return (HebrewLeapYear(year)) ? 13 : 12;
}

int HebrewCalendar::HebrewCalendarElapsedDays(int year)
{
// Number of days elapsed from the Sunday prior to the start of the
// HebrewCalendar calendar to the mean conjunction of Tishri of HebrewCalendar year.

    int MonthsElapsed= monthElapsed(year);
    int PartsElapsed = 204 + 793 * (MonthsElapsed % 1080);
    int HoursElapsed =
            5 + 12 * MonthsElapsed + 793 * (MonthsElapsed  / 1080)
                    + PartsElapsed / 1080;
    int ConjunctionDay = 1 + 29 * MonthsElapsed + HoursElapsed / 24;
    int AlternativeDay;
    if (((1080 * (HoursElapsed % 24) + PartsElapsed % 1080) >= 19440)        // If new moon is at or after midday,
            || (((ConjunctionDay % 7) == 2)    // ...or is on a Tuesday...
                    && ((1080 * (HoursElapsed % 24) + PartsElapsed % 1080) >= 9924)  // at 9 hours, 204 parts or later...
                    && !(HebrewLeapYear(year)))   // ...of a common year,
            || (((ConjunctionDay % 7) == 1)    // ...or is on a Monday at...
                    && ((1080 * (HoursElapsed % 24) + PartsElapsed % 1080) >= 16789) // 15 hours, 589 parts or later...
                    && (HebrewLeapYear(year - 1))))// at the end of a leap year
        // Then postpone Rosh HaShanah one day
        AlternativeDay = ConjunctionDay + 1;
    else
        AlternativeDay = ConjunctionDay;
    if (((AlternativeDay % 7) == 0)// If Rosh HaShanah would occur on Sunday,
            || ((AlternativeDay % 7) == 3)     // or Wednesday,
            || ((AlternativeDay % 7) == 5))    // or Friday
        // Then postpone it one (more) day
        return (1+ AlternativeDay);
    else
        return AlternativeDay;
}

int HebrewCalendar::monthElapsed(int year) {
    int MonthsElapsed =
            (235 * ((year - 1) / 19))           // Months in complete cycles so far.
                    + (12 * ((year - 1) % 19))          // Regular months in this cycle.
                    + (7 * ((year - 1) % 19) + 1) / 19; // Leap months this cycle
    return MonthsElapsed;
}

int HebrewCalendar::DaysInHebrewYear(int year)
{
    return ((HebrewCalendarElapsedDays(year + 1)) -
            (HebrewCalendarElapsedDays(year)));
}

int HebrewCalendar::LongHeshvan(int year)
{
    if ((DaysInHebrewYear(year) % 10) == 5)
        return 1;
    else
        return 0;
}

int HebrewCalendar::ShortKislev(int year)
{
// True if Kislev is short in HebrewCalendar year.

    if ((DaysInHebrewYear(year) % 10) == 3)
        return 1;
    else
        return 0;
}

int HebrewCalendar::LastMonthDay(int month, int year)
{
    if ((month == 2)
            || (month == 4)
            || (month == 6)
            || ((month == 8) && !(LongHeshvan(year)))
            || ((month == 9) && ShortKislev(year))
            || (month == 10)
            || ((month == 12) && !(HebrewLeapYear(year)))
            || (month == 13))
        return 29;
    else
        return 30;
}

HebrewCalendar::operator int() { // Computes the absolute date of HebrewCalendar date.
    int DayInYear = day; // Days so far this month.
    if (month < 7) { // Before Tishri, so add days in prior months
        // this year before and after Nisan.
        int m = 7;
        while (m <= (LastMonthOfHebrewYear(year))) {
            DayInYear = DayInYear + LastMonthDay(m, year);
            m++;
        };
        m = 1;
        while (m < month) {
            DayInYear = DayInYear + LastMonthDay(m, year);
            m++;
        }
    }
    else { // Add days in prior months this year
        int m = 7;
        while (m < month) {
            DayInYear = DayInYear + LastMonthDay(m, year);
            m++;
        }
    }
    int d = DayInYear +
            (HebrewCalendarElapsedDays(year)// Days in prior years.
                    + HebrewEpoch);
    return d;         // Days elapsed before absolute date 1.
}
