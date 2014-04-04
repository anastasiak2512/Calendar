#include "General.h"

int General::XdayOnOrBefore(int d,int x )
{
    return (d - ((d - x) % 7));
}