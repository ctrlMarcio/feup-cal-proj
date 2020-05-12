#include <gtest/gtest.h>
#include <model/company_client/company_client_manager/company_client_manager.h>

using testing::Eq;

CompanyClient createCompanyClientToAdd()
{
    CompanyRepresentative companyRepresentative("nome", "email@email.com");
    Location location(1, "a", 1, 1);
    CompanyClient companyClient("company",companyRepresentative,location);
    return companyClient;
}

TEST(company_client_manager, has_test) {
    CompanyClientManager companyClientManager;
    CompanyClient companyClient = createCompanyClientToAdd();
    companyClientManager.add(companyClient);

    EXPECT_EQ(companyClientManager.getCompaniesClient().size(), 1);
    EXPECT_TRUE(companyClientManager.has(companyClient));
}

TEST(company_client_manager, remove_test) {
    CompanyClientManager companyClientManager;
    CompanyClient companyClient = createCompanyClientToAdd();
    companyClientManager.add(companyClient);
    companyClientManager.remove(companyClient);

    EXPECT_EQ(companyClientManager.getCompaniesClient().size(), 0);
}