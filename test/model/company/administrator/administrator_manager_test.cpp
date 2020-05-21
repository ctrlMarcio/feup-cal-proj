#include <gtest/gtest.h>
#include <model/company/administrator/administrator_manager.h>

using testing::Eq;

TEST(administrator_manager, is_valid_test) {
    AdministratorManager administratorManager;
    Administrator administrator("nome", "email@email.com");

    EXPECT_TRUE(administratorManager.isValid(administrator));
}

TEST(administrator_manager, add_test) {
    AdministratorManager administratorManager;
    Administrator administrator("nome", "email@email.com");
    administratorManager.add(administrator);

    EXPECT_EQ(administratorManager.getAdministrators().size(), 1);

    Administrator administrator2("nome2", "email2@email.com");
    administratorManager.add(administrator2);

    EXPECT_EQ(administratorManager.getAdministrators().size(), 2);
}

TEST(administrator_manager, remove_test) {
    AdministratorManager administratorManager;
    Administrator administrator("nome", "email@email.com");
    administratorManager.add(administrator);
    Administrator administrator2("nome2", "email2@email.com");
    administratorManager.add(administrator2);

    administratorManager.remove(administrator);

    EXPECT_EQ(administratorManager.getAdministrators().size(), 1);
}