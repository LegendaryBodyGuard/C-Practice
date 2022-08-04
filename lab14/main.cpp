#include <iostream>
#include <map>
#include "City.hpp"

City cityArray[] = {City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000)};

std::map<std::string, unsigned int> cityMap;

void initMap(std::map<std::string, unsigned int> &cityMap, const City cityArray[], int n);
void printCityMap(std::map<std::string, unsigned int> &cityMap);
unsigned int findPopulation(std::map<std::string, unsigned int> &cityMap, std::string cityName);
void updatePopulation(std::map<std::string, unsigned int> &cityMap, std::string cityName, int updatePop);
void removeFromCityMap(std::map<std::string, unsigned int> &cityMap, std::string cityName);

int main()
{
    std::cout << "Initializing cityMap with cityArray[]:" << std::endl;
    initMap(cityMap, cityArray, 5);
    printCityMap(cityMap);

    std::cout << "\nFind population of Sacramento: " << findPopulation(cityMap, "Sacramento") << std::endl;
    std::cout << "Find population of Chicago: " << findPopulation(cityMap, "Chicago") << std::endl;

    std::cout << "\nFind population of Stockton after update: 350000";
    updatePopulation(cityMap, "Stockton", 350000);
    std::cout << "\nFind population of Portland after update: 700000";
    updatePopulation(cityMap, "Portland", 700000);

    std::cout << "\n\nRemoving San Francisco from cityMap: " << std::endl;
    removeFromCityMap(cityMap, "San Francisco");
    printCityMap(cityMap);
    return 0;
}

void initMap(std::map<std::string, unsigned int> &cityMap, const City cityArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cityMap.insert(std::pair<std::string, unsigned int>(cityArray[i].getName(), cityArray[i].getPopulation()));
    }
}

void printCityMap(std::map<std::string, unsigned int> &cityMap)
{
    for (auto const &pair : cityMap)
    {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

unsigned int findPopulation(std::map<std::string, unsigned int> &cityMap, std::string cityName)
{
    for (auto const &it : cityMap)
    {
        if (it.first.compare(cityName) == 0)
        {
            return it.second;
        }
    }
    return 0;
}

void updatePopulation(std::map<std::string, unsigned int> &cityMap, std::string cityName, int updatePop)
{
    for (auto const &it : cityMap)
    {
        if (it.first.compare(cityName) == 0)
        {
            cityMap.find(cityName)->second = updatePop;
        }
        else
        {
            cityMap.insert(std::pair<std::string, unsigned int>(cityName, updatePop));
        }
    }
}

void removeFromCityMap(std::map<std::string, unsigned int> &cityMap, std::string cityName)
{
    cityMap.erase(cityName);
}