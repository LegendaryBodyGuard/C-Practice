#pragma once
#include<iostream>
#include "City.hpp"

class CoastalCity: public City{
    private:
        std::string waterName;
        int beachNum;
        static unsigned int coastalCityCount;
        
    public:
        CoastalCity()
        {
            City::name = "N/A";
            City::population = 0;
            waterName = "N/A";
            beachNum = 0;
            coastalCityCount++;
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

        static unsigned int getCoastalCityCount()
        {
            return coastalCityCount;
        }

        CoastalCity operator*(unsigned int ccc)
        {
            CoastalCity cc;
            cc.setName(this->name);
            cc.setPopulation(this->population);
            cc.setWaterName(this->waterName);
            cc.setBeachNum(this->beachNum * ccc);

            return cc;
        }

        CoastalCity operator+(CoastalCity c)
        {
            CoastalCity cc;
            cc.setName(this->name.append(c.getName()));
            cc.setPopulation(this->population + c.getPopulation());
            cc.setWaterName(this->waterName.append(c.getWaterName()));
            cc.setBeachNum(this->beachNum + c.getBeachNum());
            
            return cc;
        }

        void printInfo() const
        {
            City::printInfo();
            std::cout << "Water: " << getWaterName() << std::endl;
            std::cout << "No. of Beaches: " << getBeachNum() << std::endl;
        }
};
