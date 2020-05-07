#include <gtest/gtest.h>
#include <auth/session/current_session.h>
#include <exception/invalid_login_exception.h>

using testing::Eq;

class CurrentSessionTest : public ::testing::Test {
public:
    virtual void SetUp() {
        authUserManager = new AuthUserManager();
        currentSession = new CurrentSession(*authUserManager);
    }

    virtual void TearDown() {
        delete authUserManager;
        delete currentSession;
        authUserManager = NULL;
        currentSession = NULL;
    }

    static AuthUserManager *authUserManager;

    static CurrentSession *currentSession;
};

AuthUserManager *CurrentSessionTest::authUserManager = NULL;

CurrentSession *CurrentSessionTest::currentSession = NULL;

TEST_F(CurrentSessionTest, login) {
    AuthUserManager &authUserManager = *CurrentSessionTest::authUserManager;
    CurrentSession &currentSession = *CurrentSessionTest::currentSession;

    EXPECT_FALSE(currentSession.isLogged());

    AuthUser user("robert@de.niro", "deniro", AuthUser::ADMINISTRATOR);
    EXPECT_TRUE(authUserManager.add(user));

    EXPECT_TRUE(authUserManager.has(user.getEmail()));

    EXPECT_TRUE(currentSession.login(user.getEmail(), user.getPassword()));

    EXPECT_TRUE(currentSession.isLogged());
}

TEST_F(CurrentSessionTest, login_excep){
    AuthUserManager &authUserManager = *CurrentSessionTest::authUserManager;
    CurrentSession &currentSession = *CurrentSessionTest::currentSession;

    EXPECT_FALSE(currentSession.isLogged());

    AuthUser user("robert@de.niro", "deniro", AuthUser::ADMINISTRATOR);
    EXPECT_TRUE(authUserManager.add(user));

    EXPECT_TRUE(authUserManager.has(user.getEmail()));

    EXPECT_THROW(currentSession.login("robert@de.nir", user.getPassword()), InvalidLoginException);

    EXPECT_FALSE(currentSession.isLogged());

    EXPECT_THROW(currentSession.login(user.getEmail(), "abc"), InvalidLoginException);

    EXPECT_FALSE(currentSession.isLogged());

    EXPECT_TRUE(currentSession.login(user.getEmail(), user.getPassword()));

    EXPECT_TRUE(currentSession.isLogged());
}