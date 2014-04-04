#ifndef CALENDAR_DEFS_H
#define CALENDAR_DEFS_H

#include <ostream>
using namespace std;

#include "Calendar.h"

//
//  Absolute dates of the starts of the Hebrew, Islamic, and Julian calendars.
//
const int HebrewEpoch = -1373429;
const int IslamicEpoch = 227014;
const int JulianEpoch = -2;

extern const char *DayName[7];

ostream& operator<<(ostream& c, Calendar d);

#endif /*CALENDAR_DEFS_H*/