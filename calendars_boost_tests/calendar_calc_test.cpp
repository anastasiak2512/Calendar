#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE module1
#include <boost/test/included/unit_test.hpp>

#include "GregorianCalendar.h"
#include "JulianCalendar.h"

#define TEST_DAY_GR 14
#define TEST_MONTH_GR 4
#define TEST_YEAR_GR 2015
#define TEST_ABSOLUTE 735702

BOOST_AUTO_TEST_SUITE(calendar_calc_suite)

    BOOST_AUTO_TEST_CASE(test_convert_greg_abs)
    {
        GregorianCalendar gr_cal(TEST_MONTH_GR, TEST_DAY_GR, TEST_YEAR_GR);
        int absolute = gr_cal;

        BOOST_CHECK_EQUAL(absolute, TEST_ABSOLUTE);
    }

    BOOST_AUTO_TEST_CASE(test_plus_one_date)
    {
        GregorianCalendar gr_cal(TEST_MONTH_GR, TEST_DAY_GR, TEST_YEAR_GR);
        int absolute = gr_cal + 1;

        BOOST_CHECK_EQUAL(absolute, TEST_ABSOLUTE + 1);
    }

    BOOST_AUTO_TEST_CASE(test_convert_julian_abs)
    {
        GregorianCalendar gr_cal(TEST_MONTH_GR, TEST_DAY_GR, TEST_YEAR_GR);
        int absolute = gr_cal;
        JulianCalendar jul_cal(absolute);
        int jul_abs = jul_cal;

        BOOST_CHECK_EQUAL(jul_abs, TEST_ABSOLUTE);
    }

    BOOST_AUTO_TEST_CASE(test_julian_plus_one)
    {
        GregorianCalendar gr_cal(TEST_MONTH_GR, TEST_DAY_GR, TEST_YEAR_GR);
        int absolute = gr_cal;
        JulianCalendar jul_cal(absolute);
        int jul_abs = (jul_cal + 2);

        BOOST_CHECK_EQUAL(jul_abs, TEST_ABSOLUTE + 1);
    }

BOOST_AUTO_TEST_SUITE_END()