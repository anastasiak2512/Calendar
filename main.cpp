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
  int d;
  int m;
  int y;
  
  while (1)
  {
    cout << "Enter year (>0): ";
    cin >> y;
    if ( y <= 0 ) 
    {
      break;
    }

    cout << "Enter month (1..12): ";
    cin >> m;
    cout << "Enter day (1.."
         << Gregorian::LastMonthDay(m, y) << "): "; cin >> d;

      Gregorian gregorian_calendar(m, d, y);
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

