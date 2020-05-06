#include <gtest/gtest.h>
#include <model/location/location.h>

using testing::Eq;

TEST(location, contructor_default_test) {
    Location location(1, "a", 1, 1);

    EXPECT_EQ(location.getLatitude(), DBL_MAX);
    EXPECT_EQ(location.getLongitude(), DBL_MAX);
}