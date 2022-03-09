#pragma once
#include <iostream>

class City{
    private:
        std::string stateName;
        int statePopulation;

    public:
        void setName(std::string name)
        {
            this->stateName = name;
        }

        void setPopulation(unsigned int population)
        {
            this->statePopulation = population;
        }

        int getPopulation()
        {
            return statePopulation;
        }

        std::string getName()
        {
            return stateName;
        }

        City(){
            stateName = "N/A";
            statePopulation = 0;
        }

        City(std::string name, int population)
        {
            this->stateName = name;
            this->statePopulation = population;
        }
};