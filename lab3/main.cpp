#include <iostream>
#include "CoastalCity.hpp"

int main () {
    CoastalCity city;

    city.City::printInfo();
    city.CoastalCity::printInfo();
    city.City::setName("San Francisco");
    city.City::setPopulation(900000);
    city.CoastalCity::setWaterName("SF Bay");
    city.CoastalCity::setBeachNum(10);
    city.City::printInfo();
    city.CoastalCity::printInfo();
}