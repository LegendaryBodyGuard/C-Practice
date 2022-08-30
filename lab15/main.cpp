#include <iostream>
#include <set>
#include <utility>
#include "City.hpp"

int a[] = {2, 8, 1, 7, 3};

City cityArray1[] = {City("Los Angeles", 4000000), City("San Diego", 1500000), City("San Francisco", 900000), City("Sacramento", 500000), City("Stockton", 300000)};
City cityArray2[] = {City("Redding", 90000), City("Stockton", 300000), City("Las Vegas", 700000), City("Reno", 300000), City("Portland", 700000), City("Sacramento", 500000), City("Eugene", 200000)};

std::set<int> intSet;
std::set<City> citySet1;
std::set<City> citySet2;
std::set<City> citySet3;

std::set<std::string> cityNames;

template <typename T>
void initSet(std::set<T> &set, T arr[], int arrSize);
template <typename T>
void printSet(std::set<T> &set);
void printCitySet(std::set<City> &citySet);
void cityNamesSet(std::set<City> &citySet, std::set<std::string> &stringHolder);
template <typename T>
void setIntersection(std::set<T> &citySet1, std::set<T> &citySet2, std::set<T> &citySet3);
template <typename T>
void setUnion(std::set<T> &citySet1, std::set<T> &citySet2, std::set<T> &citySet3);
template <typename T>
bool isSubset(std::set<T> &holder1, std::set<T> &holder2);
void removeFromCitySet(std::set<City> &holder1, std::string nameCity);

int main()
{
    initSet(intSet, a, 5);
    printSet(intSet);
    initSet(citySet1, cityArray1, 5);
    printCitySet(citySet1);
    initSet(citySet2, cityArray2, 7);
    printCitySet(citySet2);
    cityNamesSet(citySet1, cityNames);
    printSet(cityNames);
    setIntersection(citySet1, citySet2, citySet3);
    printCitySet(citySet1);
    printCitySet(citySet2);
    printCitySet(citySet3);
    setUnion(citySet1, citySet2, citySet3);
    printCitySet(citySet3);
    std::cout << "citySet1 is a subset of citySet2? " << isSubset(citySet1, citySet2) << std::endl;
    std::cout << "citySet2 is a subset of citySet3? " << isSubset(citySet2, citySet3) << std::endl;

    return 0;
}

template <typename T>
void initSet(std::set<T> &set, T arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        set.insert(arr[i]);
    }
}

template <typename T>
void printSet(std::set<T> &set)
{
    for (auto elem : set)
    {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

void printCitySet(std::set<City> &citySet)
{
    for (auto elem : citySet)
    {
        elem.printInfo();
    }
    std::cout << '\n';
}

void cityNamesSet(std::set<City> &citySet, std::set<std::string> &stringHolder)
{
    for (auto elem : citySet)
    {
        stringHolder.insert(elem.getName());
    }
}

template <typename T>
void setIntersection(std::set<T> &citySet1, std::set<T> &citySet2, std::set<T> &citySet3)
{
    for (auto elem : citySet1)
    {
        for (auto elem2 : citySet2)
        {
            if (elem.getName() == elem2.getName())
            {
                citySet3.insert(elem);
            }
        }
    }
}

template <typename T>
void setUnion(std::set<T> &citySet1, std::set<T> &citySet2, std::set<T> &citySet3)
{
    citySet3.merge(citySet1);
    citySet3.merge(citySet2);
    /*
    for (auto cities1 : citySet1)
    {
        citySet3.insert(cities1);
    }
    for (auto cities2 : citySet2)
    {
        citySet3.insert(cities2);
    }

    */
}

template <typename T>
bool isSubset(std::set<T> &citySet1, std::set<T> &citySet2)
{
    for (auto elem : citySet1)
    {
        if (citySet2.count(elem) == 0)
        {
            return false;
        }
    }
    return true;
}
