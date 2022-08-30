#include <iostream>
#include "CoastalCity.hpp"

int main () {
    CoastalCity city;

    city.printInfo();
    city.setName("San Francisco");
    city.setPopulation(900000);
    city.setWaterName("SF Bay");
    city.setBeachNum(10);
    city.printInfo();
}