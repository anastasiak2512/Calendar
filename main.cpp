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

    Gregorian g(m,d,y);
    int a = g;
    cout << g << " = " << a << " = " << DayName[g % 7] << "\n";
    
    g = a;
    a = g;
    cout << "    = Gregorian date " << g << " = absolute date " << a << "\n";
    
    Julian j(a);
    a = j;
    cout << "    = Julian date " << j << " = absolute date " << a << "\n";
    
    Hebrew h(a);
    a = h;
    cout << "    = Hebrew date " << h << " = absolute date " << a << "\n";
    
    Islamic I(a);
    a = I;
    cout << "    = Islamic date " << I << " = absolute date " << a << "\n";
  }

  return 0;
}

