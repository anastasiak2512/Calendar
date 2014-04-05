#ifndef CALENDAR_DEFS_H
#define CALENDAR_DEFS_H

#include <ostream>
using namespace std;

#include "Calendar.h"

extern const char *DayName[7];
ostream& operator<<(ostream& c, Calendar d);

#endif /*CALENDAR_DEFS_H*/