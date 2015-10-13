//
// Created by AK on 13/10/15.
//

#include "gtest/gtest.h"

#include "GregorianCalendar.h"
#include "JulianCalendar.h"

#define CLION_DAY_GR 14
#define CLION_MONTH_GR 4
#define CLION_YEAR_GR 2015
#define CLION_ABSOLUTE 735702

class CalendarFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    CalendarFixture() : Test() {
        gregorian_calendar = new GregorianCalendar(CLION_MONTH_GR, CLION_DAY_GR, CLION_YEAR_GR);
    }

    virtual ~CalendarFixture() {
        delete gregorian_calendar;
    }

    GregorianCalendar * gregorian_calendar;
};

TEST_F(CalendarFixture, absolute_check) {
    int absolute = *gregorian_calendar;
    EXPECT_EQ(absolute, CLION_ABSOLUTE);
}

TEST_F(CalendarFixture, julian_check) {
    int absolute = *gregorian_calendar;
    JulianCalendar julian_calendar(absolute);

    int julian_absolute = julian_calendar;
    EXPECT_EQ(julian_absolute, absolute);
}
