#pragma once
#include "City.hpp"

class CoastalCity: public City{
    private:
        std::string waterName;
        int beachNum;
        
    public:
        CoastalCity()
        {
            name = "N/A";
            population = 0;
            waterName = "N/A";
            beachNum = 0;
        }

        void setWaterName(std::string waterName)
        {
            this -> waterName = waterName;
        }

        void setBeachNum(int beachNum)
        {
            this -> beachNum = beachNum;
        }

        std::string getWaterName() const
        {
             return this -> waterName;
        }

        int getBeachNum() const
        {
            return this -> beachNum;
        }

        void printInfo() const
        {
            City::printInfo();
            std::cout << "Water: " << getWaterName() << std::endl;
            std::cout << "No. of Beaches: " << getBeachNum() << std::endl;
        }
};