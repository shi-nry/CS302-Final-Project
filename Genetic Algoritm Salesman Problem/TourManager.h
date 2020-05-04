// TourManager.h : Holds the cities of a tour
//

#ifndef TOURMANAGER_H
#define TOURMANAGER_H

#include <string>
#include <vector>
#include "City.h"

class TourManager {
    private:
        std::vector<City> destinationCities;

    public:
        void addCity(City city);
        City getCity(int index);
        int numberOfCities();

};

//Adds a destination city
void TourManager::addCity(City city) {

    destinationCities.push_back(city);
}

//Get a city
City TourManager::getCity(int index) {
    
    return (City)destinationCities.at(index);
}

//Get number of destination cities
int TourManager::numberOfCities() {
    
    return destinationCities.size();
}

#endif