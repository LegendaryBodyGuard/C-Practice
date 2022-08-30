#include <iostream>
#include <vector>
#include <algorithm>
#include "City.hpp"

City cityArray[] = {City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000), City("Redding", 90000), City("Las Vegas", 700000), City("Reno", 300000), City("Portland", 700000), City("Seattle", 750000), City("Eugene", 200000)};
std::vector<City> cityVector;
int steps = 0;

void initVector(std::vector<City> &cityVector, City cityArray[], int n);
void printCityVector(std::vector<City> &cityVector);
bool greaterCity(City c, City c2);
unsigned int cityLinearSearch(std::vector<City> &cityVector, std::string cityName);
unsigned int cityBinarySearch(std::vector<City> &cityVector, std::string cityName);

void initVector(std::vector<City> &cityVector, City cityArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cityVector.push_back(cityArray[i]);
    }
}

void printCityVector(std::vector<City> &cityVector)
{
    for (long unsigned int i = 0; i < cityVector.size(); i++)
    {
        std::cout << cityVector[i].getName() << " " << cityVector[i].getPopulation() << std::endl;
    }
}

bool greaterCity(City c, City c2)
{
    if (c.getName() < c2.getName())
    {
        return true;
    }
    return false;
}

unsigned int cityLinearSearch(std::vector<City> &cityVector, std::string cityName)
{
    steps = 0;
    for (long unsigned int i = 0; i < cityVector.size(); i++)
    {
        steps++;
        if (cityVector[i].getName() == cityName)
        {
            return cityVector[i].getPopulation();
        }
    }
    return 0;
}

unsigned int cityBinarySearch(std::vector<City> &cityVector, std::string cityName)
{
    int lowerbound = 0;
    int upperBound = cityVector.size() - 1;
    int i = 0;
    steps = 0;

    while (lowerbound <= upperBound)
    {
        steps++;

        int midpoint = lowerbound + (upperBound - lowerbound) / 2;
        if (cityVector[midpoint].getName() < cityName)
        {
            lowerbound = midpoint + 1;
        }
        if (cityVector[midpoint].getName() > cityName)
        {
            upperBound = midpoint - 1;
        }
        if (cityVector[midpoint].getName() == cityName)
        {
            return cityVector[midpoint].getPopulation();
        }
        i++;
    }
    return 0;
}

int main()
{
    std::cout << "Initializing cityVector with cityArray[]: " << std::endl;
    initVector(cityVector, cityArray, 11);
    printCityVector(cityVector);
    std::cout << "\nSorting cityVector based on names in ascending Order: " << std::endl;
    sort(cityVector.begin(), cityVector.end(), greaterCity);
    printCityVector(cityVector);

    std::cout << "\nLinear search for the population of San Francisco " << cityLinearSearch(cityVector, "San Francisco") << std::endl;
    std::cout << "\nNumber of comparisons for this search " << steps << std::endl;

    std::cout << "\nLinear search for the population of Boston " << cityLinearSearch(cityVector, "Boston") << std::endl;
    std::cout << "\nNumber of comparisons for this search " << steps << std::endl;

    std::cout << "\nBinary search for the population of San Francisco " << cityBinarySearch(cityVector, "San Francisco") << std::endl;
    std::cout << "\nNumber of comparisons for this search " << steps << std::endl;

    std::cout << "\nBinary search for the population of Boston " << cityBinarySearch(cityVector, "Boston") << std::endl;
    std::cout << "\nNumber of comparisons for this search " << steps << std::endl;
}