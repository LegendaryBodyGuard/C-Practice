#pragma once

class City{
    protected:
        std::string name;
        unsigned int population;
        
    public: 
    void setName(std::string name)
    {
        this -> name = name;
    }
    
    void setPopulation(unsigned int population) 
    {
        this -> population = population;
    }

    std::string getName() const
    {
        return this -> name;
    }

    unsigned int getPopulation() const
    {
        return this -> population;
    }

    void printInfo() const
    {
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Population: " << getPopulation() << std::endl;
    }
};