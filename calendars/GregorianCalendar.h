#include <iostream>
#include "calendar_defs.h"

class GregorianCalendar : public Calendar {
public:
    GregorianCalendar(int date);

    GregorianCalendar(int m, int d, int y) : Calendar(m, d, y) {
    };

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




    /// @brief The Gregorian date of nth x-day
    ///        in month, year before/after optional day.
    /// @return Gregorian date.
    GregorianCalendar NthXday(int n, ///< [in] The number of the x-day.
                              int x, ///< [in] x = 0 means Sunday, x = 1 means Monday, and so on.
                              int month, ///< [in] Month given.
                              int year, ///< [in] Year given.
                              int day = 0 ///< [in] Day given. If day is omitted or 0, it defaults
                                          ///       to 1 if n>0, and month's last day otherwise.
                             );
};

