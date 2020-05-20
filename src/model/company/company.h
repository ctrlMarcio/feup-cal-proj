#ifndef FEUP_CAL_PROJ_COMPANY_H
#define FEUP_CAL_PROJ_COMPANY_H

#include <string>
#include "../../model/location/location.h"
#include "../../util/graph/graph.h"
#include "../company_client/company_client_manager/company_client_manager.h"
#include "../location/location_manager.h"
#include "administrator/administrator_manager.h"

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
     * @param graph             the world graph
     */
    Company(std::string name, const Location& garageLocation, Graph<Location> graph, long vehicleNumber);

    /**
     * @brief Gets the company client manager.
     *
     * @return 	the company client manager
     */
    CompanyClientManager &getCompanyClientManager();

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
     * @brief Gets the number of vehicles already in use of the company.
     *
     * @return	the number of vehicles already in use of the company
     */
    long getUsedVehiclesNumber() const;

    /**
     * @brief Gets the number of vehicles left of the company.
     *
     * @return	the number of vehicles left of the company
     */
    long getVehiclesLeft() const;

    /**
     * @brief Gets the garage location of the company.
     *
     * @return  the garage location
     */
    const Location &getGarageLocation() const;

    /**
     * @brief Verifies and updates the vehicle number.
     *
     * @param vehicleNumber     the new vehicle number
     * @return true, if the vehicle number was successful updated. false, otherwise
     */
    bool setVehicleNumber(long vehicleNumber);

    /**
     * @brief Verifies and updates the vehicle number for a specific company.
     *
     * @param companyClient             the company
     * @param companyVehicleNumber      the new vehicle number
     * @return true, if the vehicle number was successful updated. false, otherwise
     */
    bool setVehicleNumber(CompanyClient &companyClient, long companyVehicleNumber);

    /**
     * @brief Gets the world graph.
     *
     * @return  the world graph
     */
    Graph<Location> &getGraph();

    /**
     * @brief Gets the location manager.
     *
     * @return  the location manager
     */
    LocationManager &getLocationManager();

    /**
     * @brief Gets the administrator manager.
     *
     * @return  the administrator manager
     */
    AdministratorManager &getAdministratorManager();

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

    /**
     * @brief The world graph.
     */
    Graph<Location> graph{};

    /**
     * @brief The company client manager.
     */
    CompanyClientManager companyClientManager;

    /**
     * @brief The company location manager.
     */
    LocationManager locationManager;

    /**
     * @brief The company administrator manager.
     */
    AdministratorManager administratorManager;
};

#endif //FEUP_CAL_PROJ_COMPANY_H
