#include "calendar_defs.h"

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

ostream& operator<<(ostream& c, Calendar d) {
    c << d.GetMonth() << "/" << d.GetDay() << "/" << d.GetYear();
    return c;
}
