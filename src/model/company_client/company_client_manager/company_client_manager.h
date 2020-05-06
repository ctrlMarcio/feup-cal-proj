#ifndef FEUP_CAL_PROJ_COMPANY_CLIENT_MANAGER_H
#define FEUP_CAL_PROJ_COMPANY_CLIENT_MANAGER_H


#include <vector>
#include <model/company_client/company_client.h>

/**
 * @brief   Represents the Company Client's Manager.
 */
class CompanyClientManager {
public:
    /**
     * @brief Constructs the Company Client's Manager.
     */
    CompanyClientManager();

    /**
     * @brief Verifies if the company is valid.
     *
     * @return          true upon success, false otherwise
     */
    bool isValid(CompanyClient companyClient);

    /**
     * @brief Adds company to companyClientSet vector.
     *
     * @return          true upon success, false otherwise
     */
    bool add(CompanyClient companyClient);

    /**
     * @brief Removes company from companyClientSet vector.
     *
     * @return          true upon success, false otherwise
     */
    bool remove(CompanyClient companyClient);

private:
    /**
     * @brief Company Client's set.
     */
    std::vector<CompanyClient> companyClientSet;
};


#endif //FEUP_CAL_PROJ_COMPANY_CLIENT_MANAGER_H
