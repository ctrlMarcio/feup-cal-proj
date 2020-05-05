#ifndef FEUP_CAL_PROJ_LOCATION_H
#define FEUP_CAL_PROJ_LOCATION_H

#include <string>
#include <float.h>

/**
 * @brief   Represents a real world location.
 *
 * @warning A coordinate isn't defined if it is equal to \e DBL_MAX (from \e float.h).
 */
class Location {
public:
    /**
     * @brief Constructs the location with all its attributes.
     *
     * @param id        the unique ID
     * @param city      the city of the location
     * @param x         the \e x coordinate
     * @param y         the \e y coordinate
     * @param latitude  the latitude
     * @param longitude the longitude
     */
    Location(long id, const std::string &city, double x, double y, double latitude=DBL_MAX, double longitude=DBL_MAX);

    /**
     * @brief Gets the ID.
     *
     * @return          the ID
     */
    long getId() const;

    /**
     * @brief Gets the city's name.
     *
     * @return the city name
     */
    const std::string &getCity() const;

    /**
     * @brief Gets the \e x coordinate.
     *
     * @return the \e x coordinate
     */
    double getX() const;

    /**
     * @brief Gets the \e y coordinate.
     *
     * @return the \e y coordinate
     */
    double getY() const;

    /**
     * @brief Gets the latitude.
     *
     * @return the latitude
     */
    double getLatitude() const;

    /**
     * @brief Gets the longitude
     *
     * @return the longitude
     */
    double getLongitude() const;

private:
	/**
	 * @brief The location unique identifier.
	 */
	long id;

	/**
	 * @brief The string
	 */
	std::string city;

	/**
	 * @brief The \e x coordinate.
	 */
	double x;

	/**
	 * @brief The \e y coordinate.
	 */
	double y;

	/**
	 * @brief The latitude.
	 */
	double latitude;

	/**
	 * @brief The longitude.
	 */
	double longitude;

};


#endif //FEUP_CAL_PROJ_LOCATION_H
