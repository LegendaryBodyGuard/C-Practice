#include <iostream>
#include <vector>
#include "City.hpp"

City cityArray[] = {City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000), City("Redding", 90000), City("Las Vegas", 700000), City("Reno", 300000), City("Portland", 700000), City("Seattle", 750000), City("Eugene", 200000)};
std::vector<City> cityVector;

void initVector(std::vector<City> &cityVector, City cityArray[], int size);
void printCityVector(std::vector<City> &cityVector);
void citySelectionSort(std::vector<City> &cityvector);
void cityInsertionSort(std::vector<City> &cityVector);

void initVector(std::vector<City> &cityVector, City cityArray[], int size)
{

    for (int i = 0; i < size; i++)
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

void citySelectionSort(std::vector<City> &cityVector)
{
    for (long unsigned int i = 0; i < cityVector.size() - 1; i++)
    {
        long unsigned int min = i;
        for (long unsigned int j = i + 1; j < cityVector.size(); j++)
        {
            if (cityVector[j].getPopulation() < cityVector[min].getPopulation())
            {
                min = j;
            }
        }
        if (min != i)
        {
            std::swap(cityVector[min], cityVector[i]);
        }
    }
}

void cityInsertionSort(std::vector<City> &cityVector)
{
    for (long unsigned int i = 1; i < cityVector.size(); i++)
    {
        unsigned int valueToInsert = cityVector[i].getPopulation();
        City value = cityVector[i];
        int holePosition = i - 1;
        while (holePosition >= 0 && cityVector[holePosition].getPopulation() > valueToInsert)
        {
            cityVector[holePosition + 1] = cityVector[holePosition];
            holePosition = holePosition - 1;
        }
        cityVector[holePosition + 1] = value;
    }
}

int main()
{
    initVector(cityVector, cityArray, 11);
    printCityVector(cityVector);

    std::cout << "\n";
    citySelectionSort(cityVector);
    printCityVector(cityVector);
    cityVector.clear();

    std::cout << "\n";
    initVector(cityVector, cityArray, 11);
    printCityVector(cityVector);

    std::cout << "\n";
    cityInsertionSort(cityVector);
    printCityVector(cityVector);
    return 0;
}