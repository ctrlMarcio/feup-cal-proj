#ifndef FEUP_CAL_PROJ_ADMINISTRATOR_H
#define FEUP_CAL_PROJ_ADMINISTRATOR_H


#include <string>

/**
 * @brief   Represents the BosHbus administrator.
 */
class Administrator {
public:
    /**
     * @brief Constructs the BosHbus administrator.
     *
     * @param name                  the administrator name
     * @param email                 the administrator email
     */
    Administrator(std::string name, std::string email);

    /**
     * @brief Gets the administrator name.
     *
     * @return          the name
     */
    std::string getName() const;

    /**
     * @brief Gets the administrator email.
     *
     * @return          the email
     */
    std::string getEmail() const;

private:
    /**
	 * @brief The administrator name.
	 */
    std::string name;
    /**
	 * @brief The administrator email.
	 */
    std::string email;
};


#endif //FEUP_CAL_PROJ_ADMINISTRATOR_H
