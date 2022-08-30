#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include "City.hpp"

City cityArray[] = {City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000)};
std::queue<City> cityQueue;
std::deque<City> cityStack;
std::vector<City> cityVector;

void initQueue(std::queue<City> &cityQueue, City cityArray[], int n);
void printCityQueue(std::queue<City> &cityQueue);
void initstack(std::deque<City> &cityStack, City cityArray[], int n);
void printCityStack(std::deque<City> &cityStack);
void initVector(std::vector<City> &cityVector, City cityArray[], int n);
void printCityVector(std::vector<City> &cityVector);

void initQueue(std::queue<City> &cityQueue, City cityArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cityQueue.push(cityArray[i]);
    }
}

void printCityQueue(std::queue<City> &cityQueue)
{
    while (!cityQueue.empty())
    {
        std::cout << cityQueue.front().getName() << " " << cityQueue.front().getPopulation() << std::endl;
        cityQueue.pop();
    }
}

void initstack(std::deque<City> &cityStack, City cityArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cityStack.push_front(cityArray[i]);
    }
}

void printCityStack(std::deque<City> &cityStack)
{
    std::deque<City> clonecityStack;

    while (!cityStack.empty())
    {
        clonecityStack.push_front(cityStack.front());
        // std::cout << "clone 2" << clonecityStack.front().getName() << " " << clonecityStack.front().getPopulation() << std::endl;
        cityStack.pop_front();
    }
    while (!clonecityStack.empty())
    {
        cityStack.push_front(clonecityStack.front());

        clonecityStack.pop_front();
    }
    while (!cityStack.empty())
    {
        std::cout << cityStack.front().getName() << " " << cityStack.front().getPopulation() << std::endl;

        cityStack.pop_front();
    }
}

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

bool vectorDecend(City c1, City c2)
{
    if (c1.getName() > c2.getName())
    {
        return true;
    }
    return false;
}

bool vectorAscend(City c1, City c2)
{
    if (c1.getPopulation() < c2.getPopulation())
    {
        return true;
    }
    return false;
}

int main()
{
    std::cout << "Initializing cityQueue with cityArray[]: " << std::endl;
    initQueue(cityQueue, cityArray, 5);
    printCityQueue(cityQueue);
    std::cout << "\nInitializing cityStack with cityArray[]: " << std::endl;
    initstack(cityStack, cityArray, 5);
    printCityStack(cityStack);
    std::cout << "\nInitializing cityVector with cityArray[]: " << std::endl;
    initVector(cityVector, cityArray, 5);
    printCityVector(cityVector);

    std::cout << "\nSorting cityVector based on names in descending order: " << std::endl;
    sort(cityVector.begin(), cityVector.end(), vectorDecend);
    printCityVector(cityVector);
    std::cout << "\n";

    std::cout << "Sorting cityVector based on populations in ascending order: " << std::endl;
    sort(cityVector.begin(), cityVector.end(), vectorAscend);
    printCityVector(cityVector);
    return 0;
}