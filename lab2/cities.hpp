#pragma once 
#include "city.hpp"
#include <vector>

class Cities {
    private:
        std::vector<City> cityList;

    public:
        void readCities();
        void printCityList();
};