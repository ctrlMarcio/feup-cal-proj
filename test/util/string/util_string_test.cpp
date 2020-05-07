#include <gtest/gtest.h>
#include <util/string/util_string.h>

using testing::Eq;

TEST(util_string, split) {
    std::string string = "What to do?";
    std::string backup(string);
    char delimiter = ' ';

    std::vector<std::string> res = util_string::split(string, delimiter);
    std::vector<std::string> expected = {"What", "to", "do?"};

    ASSERT_EQ(res.size(), 3);
    ASSERT_EQ(res, expected);
    ASSERT_EQ(string, backup);
}