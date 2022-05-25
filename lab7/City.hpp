#pragma once
#include<iostream>

class City {
protected:
    std::string name;
    unsigned int population;

public:
    City()
    {
        name = "N/A";
        population = 0;
    }

    City(std::string cityNm, int cityPop)
    {
        name = cityNm;
        population = cityPop;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setPopulation(unsigned int population)
    {
        this->population = population;
    }

    std::string getName() const
    {
        return this->name;
    }

    unsigned int getPopulation() const
    {
        return this->population;
    }

    virtual void printInfo() const
    {
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Population: " << getPopulation() << std::endl;
    }
};