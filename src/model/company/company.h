#ifndef FEUP_CAL_PROJ_COMPANY_H
#define FEUP_CAL_PROJ_COMPANY_H

#include <string>
#include "../../model/location/location.h"

/**
 * @brief Represents a company.
 *
 * The company is responsible for managing its locations, administrators and company clients. Also holds
 * the company's vehicles and garage location.
 */
class Company {
public:
    /**
     * @brief Establishes an instance of a Company given a name and a number of vehicles.
     *
     * @param name              the name
     * @param garageLocation    the garage location
     * @param vehicleNumber     the number of vehicles
     */
    Company(std::string name, Location garageLocation, long vehicleNumber);

    /**
     * @brief Gets the name of the company.
     *
     * @return  the name of the company
     */
    const std::string &getName() const;

    /**
     * @brief Gets the number of vehicles of the company
     *
     * @return  the number of vehicles of the company
     */
    long getVehicleNumber() const;

    /**
     * @brief Gets the garage location of the company.
     *
     * @return  the garage location
     */
    const Location &getGarageLocation() const;

private:
    /**
     * @brief The name of the company.
     */
    std::string name;

    /**
     * @brief The number of vehicles owned by the company.
     */
    long vehicleNumber;

    /**
     * @brief The garage location of the company.
     */
    Location garageLocation;
};

#endif //FEUP_CAL_PROJ_COMPANY_H
