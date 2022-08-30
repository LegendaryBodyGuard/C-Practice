#pragma once
#include <string>
#include <iostream>
#include <utility>

class City
{
public:
    City(std::string name, unsigned int pop)
    {
        namePopulationPair.first = name;
        namePopulationPair.second = pop;
    }

    void setName(std::string name)
    {
        this->namePopulationPair.first = name;
    }
    void setPopulation(unsigned int population)
    {
        this->namePopulationPair.second = population;
    }
    std::string getName() const
    {
        return this->namePopulationPair.first;
    }
    unsigned int getPopulation() const
    {
        return this->namePopulationPair.second;
    }
    virtual void printInfo() const
    {
        std::cout << getName() << ": " << getPopulation() << std::endl;
    }
    bool operator<(const City &city) const
    {
        if (this->getName() < city.getName())
        {
            return true;
        }
        return false;
    }

protected:
    std::pair<std::string, unsigned int> namePopulationPair;
};
