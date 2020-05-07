#include <gtest/gtest.h>
#include <model/location/location.h>

using testing::Eq;

TEST(location, contructor_default_test) {
    Location location(1, "a", 1, 1);

    EXPECT_EQ(location.getLatitude(), DBL_MAX);
    EXPECT_EQ(location.getLongitude(), DBL_MAX);
}

TEST(location, equality_test) {
    Location l1(1, "a", 1, 1);
    Location l2(1, "b", 2, 2, 2, 2);
    Location l3(2, "a", 1, 1);

    EXPECT_EQ(l1, l2);
    EXPECT_NE(l1, l3);
}