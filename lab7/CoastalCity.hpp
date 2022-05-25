#pragma once
#include<iostream>
#include "City.hpp"

class CoastalCity : public City {
private:
    std::string waterName;
    int beachNum;
    static unsigned int coastalCityCount;
    City* adjCity;

public:
    CoastalCity()
    {
        City::name = "N/A";
        City::population = 0;
        waterName = "N/A";
        beachNum = 0;
        coastalCityCount++;
        adjCity = new City();
    }

    CoastalCity(std::string nm, unsigned int pop, std::string wName, int bNum, std::string adjName, int adjPop)
    {
        City::name = nm;
        City::population = pop;
        this->waterName = wName;
        this->beachNum = bNum;
        adjCity = new City(adjName, adjPop);
    }

    ~CoastalCity() {
        delete adjCity;
    }

    void setWaterName(std::string wName)
    {
        this->waterName = wName;
    }

    void setBeachNum(int bNum)
    {
        this->beachNum = bNum;
    }

    std::string getWaterName() const
    {
        return this->waterName;
    }

    int getBeachNum() const
    {
        return this->beachNum;
    }

    static unsigned int getCoastalCityCount()
    {
        return coastalCityCount;
    }

    City* getAdjCity()
    {
        return adjCity;
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
        std::cout << "Adjacent city:" << "\n";
        std::cout << "Name: " << adjCity->getName() << std::endl;
        std::cout << "Population: " << adjCity->getPopulation() << std::endl;
    }
};
