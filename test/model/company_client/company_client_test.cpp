#include <gtest/gtest.h>
#include <model/company_client/company_client.h>

using testing::Eq;

CompanyClient createCompanyClient()
{
    CompanyRepresentative companyRepresentative("nome", "email@email.com");
    Location location(1, "a", 1, 1);
    CompanyClient companyClient("company",companyRepresentative,location);
    return companyClient;
}

TEST(company_client, contructor_default_test) {
    CompanyRepresentative companyRepresentative("nome", "email@email.com");
    Location location(1, "a", 1, 1);
    CompanyClient companyClient("company",companyRepresentative,location);

    EXPECT_EQ(companyClient.getName(), "company");
    EXPECT_EQ(companyClient.getHeadquarters(), location);
    EXPECT_EQ(companyClient.getRepresentative().getEmail(), companyRepresentative.getEmail());
}

TEST(company_client, add_pickuppoints) {
    CompanyClient companyClient = createCompanyClient();
    Location location1(2, "a", 1, 2);
    Location location2(3, "b", 1, 3);
    companyClient.addPickupPoint(location1);
    companyClient.addPickupPoint(location2);
    companyClient.addPickupPoint(location2);

    EXPECT_EQ(companyClient.getPickupPoints().size(), 2);
}

TEST(company_client, remove_pickuppoints) {
    CompanyClient companyClient = createCompanyClient();
    Location location1(2, "a", 1, 2);
    Location location2(3, "b", 1, 3);
    companyClient.addPickupPoint(location1);
    companyClient.addPickupPoint(location2);
    companyClient.addPickupPoint(location2);
    companyClient.removePickupPoint(location1);

    EXPECT_EQ(companyClient.getPickupPoints().size(), 1);
    EXPECT_EQ(companyClient.getPickupPoints().at(0), location2);
}

TEST(company_client, change_vehicle_number) {
    CompanyClient companyClient = createCompanyClient();
    companyClient.setVehicleNumber(3);

    EXPECT_EQ(companyClient.getVehicleNumber(), 3);
}