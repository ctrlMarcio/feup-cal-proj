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
     * @brief The regular delimiter of the files.
     */
    static const char DELIMITER = ',';

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
    void readDir(const string &city, const string &path);

    /**
     * @brief Appends nodes and edges from files to the graph
     *
     * @param edgesFile         the name of the edges' file
     * @param city              the name of the city to append
     * @param mutex     the mutex to ensure thread safety
     */
    void
    append(const std::string &nodesFile, const std::string &edgesFile, const std::string &city);

    /**
     * @brief Appends locations to the graph from a file.
     *
     * @warning         Only available for \e Location graphs.
     * @throws          InvalidFileException
     * @param fileName  the name of the file containing the locations
     * @param city      the name of the city described in the files
     * @param mutex     the mutex to assure safety
     */
    void readNodes(const std::string &fileName, const std::string &city);

    /**
     * @brief Reads the edges between locations to the graph from a file.
     *
     * If an edge has an ID non existent, returns false but adds the other edges anyway.
     *
     * @warning         only available for \e Location graphs
     * @throws          InvalidFileException
     * @param fileName  the name of the file containing the edges
     * @param mutex     the mutex to assure safety
     * @return          true if the edges were successfully read, false otherwise
     */
    bool readEdges(const string &fileName);
};


#endif //FEUP_CAL_PROJ_BOOTSTRAP_H
