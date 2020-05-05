#ifndef FEUP_CAL_PROJ_COMPANY_CLIENT_H
#define FEUP_CAL_PROJ_COMPANY_CLIENT_H

#include <string>
#include <vector>
#include <model/location/location.h>
#include <model/company client/company representative/representative.h>

/**
 * @brief   Represents a company that might benefit from BosHbus services.
 */
class CompanyClient {

public:
    /**
     * @brief Constructs the company with all its attributes.
     *
     * @param name                  the company name
     * @param representative        the company representative
     * @param headquarters          the company headquarters location
     */
    CompanyClient(std::string name, Representative representative, Location headquarters);

    /**
     * @brief Gets the UUID.
     *
     * @return          the UUID
     */
    //UUID getUuid()

    /**
     * @brief Gets the company's name.
     *
     * @return          the company name
     */
    std::string getName() const;

    /**
     * @brief Gets the company representative.
     *
     * @return          the company representative
     */
    Representative getRepresentative() const;

    /**
     * @brief Gets the headquarters location.
     *
     * @return          the headquarters location
     */
    Location getHeadquarters() const;

    /**
     * @brief Gets the pickup points location vector.
     *
     * @return          the pickup points location vector
     */
    std::vector<Location> getPickupPoints() const;

    /**
     * @brief Adds a location to the pickup points vector.
     *
     * @param location              the location wanted to be added to the pickup points vector
     */
    bool addPickupPoint(Location location);

    /**
     * @brief Removes a location from the pickup points vector.
     *
     * @param location              the location wanted to be removed from the pickup points vector
     */
    bool removePickupPoint(Location location);

    /**
     * @brief Gets the number of used vehicles by the company.
     *
     * @return          the number of used vehicles by the company
     */
    int getVehicleNumber() const;

    /**
     * @brief Sets the number of used vehicles by the company.
     *
     * @param          the number of used vehicles by the company
     */
    void setVehicleNumber(int vehicleNumber);

private:
    /**
	 * @brief The company name.
	 */
    std::string name;

    /**
     * @brief The Company Representative.
     */
    Representative representative;

    /**
     * @brief The Company's headquarters location.
     */
    Location headquarters;

    /**
     * @brief The Company's pickup points vector.
     */
    std::vector<Location> pickupPoints;

    /**
     * @brief The number of vehicles used by the Company.
     */
    int vehicleNumber;

    /**
     * @brief The Company's identifier.
     */
    //UUID uuid;

};


#endif //FEUP_CAL_PROJ_COMPANY_CLIENT_H