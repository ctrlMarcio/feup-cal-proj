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
     * @brief   The name of the file that contains nodes
     */
    static const std::string NODES_FILE;

    /**
     * @brief   The name of the file that contains edges
     */
    static const std::string EDGES_FILE;

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
     * @param country   the country
     */
    void appendToGraph(const std::string &directory, const std::string &country);

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

    /**
     * @brief Reads a single directory as a city
     *
     * @param city  the city
     * @param path  the directory
     * @param mutex     the mutex to ensure thread safety
     */
    void readDir(const string &city, const string &path, std::mutex *mutex);
};


#endif //FEUP_CAL_PROJ_BOOTSTRAP_H
