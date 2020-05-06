#ifndef FEUP_CAL_PROJ_COMPANY_REPRESENTATIVE_H
#define FEUP_CAL_PROJ_COMPANY_REPRESENTATIVE_H


#include <string>

/**
 * @brief   Represents the company's representative.
 */
class CompanyRepresentative {
public:
    /**
     * @brief Constructs the company's representative.
     *
     * @param name                  the company's representative name
     * @param email                 the company's representative email
     */
    CompanyRepresentative(std::string name, std::string email);

    /**
     * @brief Gets the company's representative name.
     *
     * @return          the name
     */
    std::string getName() const;

    /**
     * @brief Gets the company's representative email.
     *
     * @return          the email
     */
    std::string getEmail() const;

private:
    /**
	 * @brief The company's representative name.
	 */
    std::string name;
    /**
	 * @brief The company's representative email.
	 */
    std::string email;
};


#endif //FEUP_CAL_PROJ_COMPANY_REPRESENTATIVE_H
