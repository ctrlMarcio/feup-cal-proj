#include <gtest/gtest.h>
#include <util/string/string_util.h>

using testing::Eq;

TEST(util_string, split) {
    std::string string = "What to do?";
    std::string backup(string);
    char delimiter = ' ';

    std::vector<std::string> res = string_util::split(string, delimiter);
    std::vector<std::string> expected = {"What", "to", "do?"};

    ASSERT_EQ(res.size(), 3);
    ASSERT_EQ(res, expected);
    ASSERT_EQ(string, backup);
}