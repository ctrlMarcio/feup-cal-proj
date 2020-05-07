#ifndef FEUP_CAL_PROJ_ADMINISTRATOR_MANAGER_H
#define FEUP_CAL_PROJ_ADMINISTRATOR_MANAGER_H

#include <vector>
#include "administrator.h"

/**
 * @brief   Represents the Administrator Manager.
 */
class AdministratorManager {
public:
    /**
     * @brief Constructs the Administrator Manager.
     */
    AdministratorManager();

    /**
     * @brief Verifies if the company is valid.
     *
     * @return          true upon success, false otherwise
     */
    bool isValid(Administrator administrator);

    /**
     * @brief Adds company to administratorSet vector.
     *
     * @return          true upon success, false otherwise
     */
    bool add(Administrator administrator);

    /**
     * @brief Removes company from administratorSet vector.
     *
     * @return          true upon success, false otherwise
     */
    bool remove(Administrator administrator);

private:
    /**
     * @brief Administrator Manager set.
     */
    std::vector<Administrator> administratorSet;
};


#endif //FEUP_CAL_PROJ_ADMINISTRATOR_MANAGER_H
