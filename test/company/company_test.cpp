#include <gtest/gtest.h>
#include <model/company/company.h>

using testing::Eq;

TEST(company_name, example) {
    Company company("teste1");

    ASSERT_EQ(company.getName(), "teste1");
    ASSERT_NE(company.getName(), "teste2");
}