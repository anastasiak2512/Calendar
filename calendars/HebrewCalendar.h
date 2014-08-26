#include <ostream>
#include "calendar_defs.h"

class HebrewCalendar : public Calendar {
public:
    HebrewCalendar(int m, int d, int y) : Calendar(m, d, y) {
    };

    HebrewCalendar(int d);

    operator int();

    int HebrewLeapYear(int year);
    int LastMonthOfHebrewYear(int year);
    int HebrewCalendarElapsedDays(int year);
    int DaysInHebrewYear(int year);
    int LongHeshvan(int year);
    int ShortKislev(int year);
    int LastMonthDay(int month, int year);

    int monthElapsed(int year);

};