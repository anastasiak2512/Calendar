#include "calendars/Gregorian.h"
#include "calendars/Islamic.h"
#include "calendars/Julian.h"
#include "calendars/Hebrew.h"

using namespace std;

const char * DayName[7] =
{
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

int main()
{
    int day;
    int month;
    int year;
  
  while (1)
  {
    cout << "Enter year (>0): ";
      cin >> year;
      if (year <= 0)
    {
      break;
    }

    cout << "Enter month (1..12): ";
      cin >> month;
    cout << "Enter day (1.."
            << Gregorian::LastMonthDay(month, year) << "): ";
      cin >> day;

      Gregorian gregorian_calendar(month, day, year);
      int a = gregorian_calendar;
      cout << gregorian_calendar << " = " << a << " = " << DayName[gregorian_calendar % 7] << "\n";

      gregorian_calendar = a;
      a = gregorian_calendar;
      cout << "    = Gregorian date " << gregorian_calendar << " = absolute date " << a << "\n";

      Julian julian_calendar(a);
      a = julian_calendar;
      cout << "    = Julian date " << julian_calendar << " = absolute date " << a << "\n";

      Hebrew hebrew_calendar(a);
      a = hebrew_calendar;
      cout << "    = Hebrew date " << hebrew_calendar << " = absolute date " << a << "\n";

      Islamic islamic_calendar(a);
      a = islamic_calendar;
      cout << "    = Islamic date " << islamic_calendar << " = absolute date " << a << "\n";
  }

  return 0;
}

