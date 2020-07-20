//
// Created by AK on 12/09/16.
//

#include "gtest/gtest.h"
#include "GregorianCalendar.h"

TEST(date_check, def_year) {
    EXPECT_EQ(def_year_len, 365);
}

TEST(date_check, longest_month) {
    EXPECT_EQ(longest_month, 31);
}

TEST(date_check, shortest_month) {
    EXPECT_EQ(shortest_month, 28);
}