#include "calendar_defs.h"

ostream& operator<<(ostream& c, Calendar d) {
    c << d.GetMonth() << "/" << d.GetDay() << "/" << d.GetYear();
    return c;
}
