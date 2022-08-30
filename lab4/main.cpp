#include <iostream>
#include "CoastalCity.hpp"
#include "City.hpp"
#include <vector>

int main () {
    CoastalCity *coastal = NULL;
    CoastalCity *coastal1 = NULL;
    City *city = NULL;
    City *city1 = NULL;

    std::vector<City*> cities;

    city = new City();
    city->setName("Denver");
    city->setPopulation(750000);
    cities.push_back(city);


    city1 = new City();
    city1->setName("Reno");
    city1->setPopulation(250000);
    cities.push_back(city1);

    coastal = new CoastalCity();
    coastal->setName("San Diego");
    coastal->setPopulation(250000);
    coastal->setWaterName("Pacific Ocean");
    coastal->setBeachNum(5);
    cities.push_back(coastal);

    coastal1 = new CoastalCity();
    coastal1->setName("Miami");
    coastal1->setPopulation(500000);
    coastal1->setWaterName("Atlantic Ocean");
    coastal1->setBeachNum(8);
    cities.push_back(coastal1);

    for (int i = 0; i < cities.size(); i++) {
        
        cities[i]->printInfo();
        std::cout << "\n";
    }

}