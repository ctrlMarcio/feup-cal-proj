#ifndef FEUP_CAL_PROJ_COMPANY_CLIENT_MANAGER_H
#define FEUP_CAL_PROJ_COMPANY_CLIENT_MANAGER_H

#include <unordered_set>
#include "../company_client.h"

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

    /**
     * @brief Verifies if the company is valid.
     *
     * @return          true upon success, false otherwise
     */
    bool isValid(const CompanyClient &companyClient) const;

    /*!
    * Verifies if a company client is in the set or not.
    *
    * @param companyClient  reference to a company client
    * @return true, if the company client is in the set. false, otherwise
    */
    bool has(CompanyClient &companyClient) const;

    /*!
     * Verifies if a company client is in the set or not.
     *
     * @param email the uuid of the company client to verify
     * @return true, if the company client is in the set. false, otherwise
     */
    bool has(long uuid) const;

    /**
     * @brief Gets company client's set.
     *
     * @return          company client's set
     */
    std::vector<CompanyClient> getCompanies() const;

    /**
     * @brief Gets the number of vehicles already in use.
     *
     * @return	the number of vehicles already in use
     */
    long getUsedVehiclesNumber() const;

    CompanyClient *getCompany(long uuid);

    /**
     * @brief Gets the company of a representative given its email.
     *
     * @param email the email of the representative
     * @return  a pointer to the company of the representative, null if the company does not exist
     */
    CompanyClient *getCompany(const std::string &email);

private:
    /**
     * @brief Company Client's set.
     */
    std::vector<CompanyClient> companies;
};


#endif //FEUP_CAL_PROJ_COMPANY_CLIENT_MANAGER_H
