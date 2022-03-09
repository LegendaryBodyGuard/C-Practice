#include "cities.hpp"
#include <iostream>
#include <vector>
// #include "city.hpp"

void Cities::readCities()
{
    
    City test1;
    std::string name;
    int population;
                                
    std::cout << "Enter city name and population. To end, enter x.\n";
    while (true)
    {
        std::cout << "City: ";
        std::cin >> name;
        if (name == "x")
        {
            break;
        }
        test1.setName(name);
        
        // std::cout << test1.getName() << "\n" ;

        std::cout << "Population: ";
        std::cin >> population;
        // if (population == "x")
        // {
        //     break;
        // }
        test1.setPopulation(population);

        // std::cout << test1.getPopulation() << "\n";
        cityList.push_back(test1);
        // cityList.push_back(population);
    }
}

void Cities::printCityList()
{
    std::cout << "\nThe state California has the following cities/populations:\n";
    for (int i = 0; i < cityList.size(); i++)
    {
        std::cout << cityList[i].getName() << ": " << cityList[i].getPopulation() << "\n";
    }
}

// int main()
// {
//     Cities test;
//     test.readCities();
//     test.printCityList();
//     return 0;
// }