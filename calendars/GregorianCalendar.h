#include <iostream>
#include "calendar_defs.h"
#include "General.h"

static const int def_year_len = 365;

static const int longest_month = 31;

static const int shortest_month = 28;

class GregorianCalendar : public Calendar {
public:
    GregorianCalendar(int date);

    GregorianCalendar(int m, int d, int y) : Calendar(m, d, y) {
    }

    operator int();

    /// @brief
    /// @param month
    /// @param year
    /// @return
    static int LastMonthDay(int month, int year);



    /// @brief Check if the given year is a leap one.
    /// @param year Year given.
    /// @return True for the leap year, false - otherwise.
    static bool ifLeapYear(int year);




    /// @brief The GregorianCalendar date of nth x-day in month, year before/after
    /// optional day.
    /// x = 0 means Sunday, x = 1 means Monday, and so on.  If n<0, return the nth
    /// x-day before month day, year (inclusive).  If n>0, return the nth x-day
    /// after month day, year (inclusive).  If day is omitted or 0, it defaults
    /// to 1 if n>0, and month's last day otherwise.
    /// @return Gregorian date.
    GregorianCalendar NthXday(int n, ///< [in] The number of the x-day.
                              int x, ///< [in] x = 0 means Sunday, x = 1 means Monday, and so on.
                              int month, ///< [in] Month given.
                              int year, ///< [in] Year given.
                              int day = 0 ///< [in] Day given. If day is omitted or 0, it defaults
                                          ///       to 1 if n>0, and month's last day otherwise.
                             ) {
        if (n > 0) {
            if (day == 0) {
                day = 1;
            }
            GregorianCalendar calendar =
                    GregorianCalendar(month, day, year);

            return
                    GregorianCalendar
                            ((7 * (n - 1)) + General::XdayOnOrBefore(6 + calendar, x));
        }
        else {
            if (day == 0) {
                day = LastMonthDay(month, year);
            }
            GregorianCalendar calendar =
                    GregorianCalendar(month, day, year);
            int date = (7 * (n + 1)) +
                       General::XdayOnOrBefore(calendar, x);
            return GregorianCalendar(date);
        }
    }

};

