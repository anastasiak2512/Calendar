#include "calendar_defs.h"

ostream& operator<<(ostream& c, Calendar d) {
    c << d.getMonth() << " / " << d.getDay() << " / " << d.getYear();
    return c;
}
