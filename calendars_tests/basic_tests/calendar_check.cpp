//
// Created by AK on 13/10/15.
//

#include "gtest/gtest.h"

#include "GregorianCalendar.h"
#include "JulianCalendar.h"

#define TEST_DAY_GR 14
#define TEST_MONTH_GR 4
#define TEST_YEAR_GR 2015
#define TEST_ABSOLUTE 735702

class CalendarFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
    CalendarFixture() : Test() {
        gregorian_calendar = new GregorianCalendar(TEST_MONTH_GR, TEST_DAY_GR, TEST_YEAR_GR);
    }

    virtual ~CalendarFixture() {
        delete gregorian_calendar;
    }

    GregorianCalendar * gregorian_calendar;
};
TEST_F(CalendarFixture, absolute_date_check) {
    int absolute = *gregorian_calendar;
    EXPECT_EQ(absolute, TEST_ABSOLUTE);
}

TEST_F(CalendarFixture, plus_one_date_check) {
    int absolute = (*gregorian_calendar) + 1;
    EXPECT_EQ(absolute, TEST_ABSOLUTE + 1);
}

TEST_F(CalendarFixture, julian_date_check) {
    int absolute = *gregorian_calendar;
    JulianCalendar julian_calendar(absolute);

    int julian_absolute = julian_calendar;
    EXPECT_EQ(julian_absolute, TEST_ABSOLUTE);
}

TEST_F(CalendarFixture, julian_plus_one_date_check) {
    int absolute = *gregorian_calendar;
    JulianCalendar julian_calendar(absolute);

    int julian_absolute = julian_calendar + 1;
    EXPECT_EQ(julian_absolute, TEST_ABSOLUTE + 1);
}
