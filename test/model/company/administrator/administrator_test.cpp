#include <gtest/gtest.h>
#include <model/company/administrator/administrator.h>

using testing::Eq;

TEST(administrator, contructor_default_test) {
    Administrator administrator("nome", "email@email.com");

    EXPECT_EQ(administrator.getName(), "nome");
    EXPECT_EQ(administrator.getEmail(), "email@email.com");
}