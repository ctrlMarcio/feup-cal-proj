#include <gtest/gtest.h>
#include <model/company_client/company_client.h>

using testing::Eq;

TEST(company_representative, contructor_default_test) {
    CompanyRepresentative companyRepresentative("nome", "email@email.com");

    EXPECT_EQ(companyRepresentative.getName(), "nome");
    EXPECT_EQ(companyRepresentative.getEmail(), "email@email.com");
}