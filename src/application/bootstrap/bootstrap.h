#ifndef FEUP_CAL_PROJ_BOOTSTRAP_H
#define FEUP_CAL_PROJ_BOOTSTRAP_H


#include <string>
#include "../../model/company/company.h"

/**
 * @brief Boots up the required parameters to run the application.
 */
class Bootstrap {
public:
    /**
     * @brief Empty construct, initializes an empty graph
     */
    Bootstrap() = default;

    /**
     * @brief Creates the bootstrap reading the graph right after
     *
     * @param directory the directory to read the information from
     */
    explicit Bootstrap(const std::string &directory);

    /**
     * @brief Appends the information on a directory to the graph
     *
     * The directory must contain subdirectories for each of the cities, and each subdirectory must contain a \e nodes.txt and a \e edges.txt .
     *
     * @param directory the directory that contains the information
     */
    void appendToGraph(const std::string &directory);

    /**
     * @brief Builds the company given the actual graph
     *
     * @param name          the name of the company
     * @param locationId    the id of the location of the company
     * @param vehicleNumber the number of vehicles
     * @return              the built company
     */
    Company buildCompany(const std::string &name, long locationId, long vehicleNumber);

private:
    /**
     * @brief The graph
     */
    Graph<Location> graph;
};


#endif //FEUP_CAL_PROJ_BOOTSTRAP_H
