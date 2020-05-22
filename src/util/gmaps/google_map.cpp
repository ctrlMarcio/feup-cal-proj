#include <iostream>
#include "google_map.h"
#include <sstream>
#include "../string/string_util.h"

GoogleMap::GoogleMap(const std::list<Path<Location>> &paths, const Location &garage, const Location &headquarters,
                     const std::vector<Location> &pickupPoints) {
    this->HTML = R"(<!DOCTYPE html><html><head> <title>CAL 2019/20 G6</title> <script src="https://polyfill.io/v3/polyfill.min.js?features=default"></script> <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDb1l2d5UJ3wJ7DmMb1DhF3iWPE7aMqVQk&callback=initMap&libraries=&v=weekly" defer></script> <link rel="icon" type="image/png" href="https://img.icons8.com/color/48/000000/google-maps.png"> <style> #map { height: 100%; } html, body { height: 100%; margin: 0; padding: 0; } </style> <script> var map; function initMap() { map = new google.maps.Map(document.getElementById("map"), { center: { lat: 41.177331426373925, lng: -8.598700761795044 }, zoom: 16, mapTypeId: 'roadmap' }); var garage = new google.maps.Marker({ position: ##GARAGE##, map: map, animation: google.maps.Animation.DROP, title: 'Garage', icon: 'https://img.icons8.com/color/40/000000/garage-closed.png' }); var headquarters = new google.maps.Marker({ position: ##HEADQUARTERS##, map: map, animation: google.maps.Animation.DROP, title: 'Company headquarters', icon: 'https://img.icons8.com/fluent/40/000000/client-company.png' }); var locations = [##LOCATIONS##]; var pickupPoints = [##PICK_UP_POINTS##]; for (var point in pickupPoints) { new google.maps.Marker({ map: map, animation: google.maps.Animation.DROP, position: pickupPoints[point], icon: 'https://img.icons8.com/color/40/000000/person-pointing.png' }); } var bounds = new google.maps.LatLngBounds(); for (var i = 0; i < locations.length; i++) { for(var j = 0; j < locations[i].length; j++){ bounds.extend(locations[i][j]); } } for (var i = 0; i < pickupPoints.length; i++) { bounds.extend(pickupPoints[i]); } bounds.extend(garage.position); bounds.extend(headquarters.position); map.fitBounds(bounds); var colors = ['#34b4eb', '#ffa142', '#ff4b2b', '#0fe000', '#ff2bb8', '#595959']; for (var path in locations) { var lineSymbol = { path: google.maps.SymbolPath.FORWARD_CLOSED_ARROW, scale: 4, fillOpacity: 1.0, strokeWeight: 2, fillColor: colors[path % colors.length], strokeColor: colors[path % colors.length] }; var line = new google.maps.Polyline({ path: locations[path], icons: [{ icon: lineSymbol, offset: '100%' }], strokeColor: colors[path % colors.length], strokeOpacity: 0.7, strokeWeight: 3, map: map }); animateCircle(line); } } function animateCircle(line) { var count = 0; window.setInterval(function () { var icons = line.get('icons'); count = (count + 1) % 800; if (icons[0].offset == '99.875%') return; icons[0].offset = (count / 8) + '%'; line.set('icons', icons); }, 25); } </script></head><body> <div id="map"></div></body></html>)";

    std::vector<std::pair<std::string, std::string>> values;

    values.emplace_back("lat", to_string(garage.getLatitude()));
    values.emplace_back("lng", to_string(garage.getLongitude()));

    string_util::replace(HTML, "##GARAGE##", string_util::toJSONObject(values));

    values.clear();
    values.emplace_back("lat", to_string(headquarters.getLatitude()));
    values.emplace_back("lng", to_string(headquarters.getLongitude()));

    string_util::replace(HTML, "##HEADQUARTERS##", string_util::toJSONObject(values));

    std::stringstream pickupPointsArrayStream;
    for (const Location &pickupPoint : pickupPoints) {
        values.clear();
        values.emplace_back("lat", to_string(pickupPoint.getLatitude()));
        values.emplace_back("lng", to_string(pickupPoint.getLongitude()));

        std::string singleLocation = string_util::toJSONObject(values);

        pickupPointsArrayStream << singleLocation << ",";
    }

    std::string pickupPointsArray = pickupPointsArrayStream.str();
    pickupPointsArray = pickupPointsArray.substr(0, pickupPointsArray.size() - 1);

    string_util::replace(HTML, "##PICK_UP_POINTS##", pickupPointsArray);

    std::stringstream verticesArrayStream;

    for (const Path<Location> &path : paths) {
        verticesArrayStream << "[";

        std::stringstream pathArrayStream;

        for (const Vertex<Location> &vertex : path.getPath()) {
            values.clear();
            values.emplace_back("lat", to_string(vertex.get().getLatitude()));
            values.emplace_back("lng", to_string(vertex.get().getLongitude()));

            std::string singleLocation = string_util::toJSONObject(values);

            pathArrayStream << singleLocation << ",";
        }

        std::string pathArray = pathArrayStream.str();
        pathArray = pathArray.substr(0, pathArray.size() - 1);
        verticesArrayStream << pathArray << "],";
    }

    std::string verticesArray = verticesArrayStream.str();
    verticesArray = verticesArray.substr(0, verticesArray.size() - 1);

    string_util::replace(HTML, "##LOCATIONS##", verticesArray);

    std::cout << HTML << std::endl;
}

void GoogleMap::show() {

}
