#include <iostream>
#include <list>
#include "City.hpp"

int a[] = { 2,8,1,7,3 };
City cityArray[] = { City("Los Angeles",4000000), City("San Diego",1500000), City("San Francisco",900000), City("Sacramento",500000),
City("Stockton",300000) };
std::list<int> intList;
std::list<City> cityList;

template <class T>
void initList(std::list<T>& List, T arr[], int arrSize);
template <class T>
void printList(std::list<T>& List);
template <class T>
void printCityList(const std::list<T> List);
template <class T>
void rotateListRight(std::list<T>& List, int rotationValue);
template <class T>
void rotateListLeft(std::list<T>& List, int rotationValue);
template <class T>
void removeFromCityList(std::list<T> List, std::string userInputCity);
template <class T>
void InsertToCityList(std::list<T> List1, City cityToadd, std::string userInputCity);

int main() {
    initList(intList, a, 5);
    printList(intList);
    std::cout << "\n";
    initList(cityList, cityArray, 5);
    printCityList(cityList);
    std::cout << "\n";
    rotateListRight(intList, 2);
    printList(intList);
    std::cout << "\n";
    rotateListLeft(intList, 1);
    printList(intList);
}

template <class T>
void initList(std::list<T>& List, T arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        List.push_back(arr[i]);
    }
}

template <class T>
void printList(std::list<T>& List) {
    std::string test;
    for (auto const& i : List) {
        std::cout << test << i;
        test = ",";
    }
}

template <class T>
void printCityList(const std::list<T> List) {
    for (City cities : List) {
        cities.printInfo();
    }
}

template <class T>
void rotateListRight(std::list<T>& List, int rotationValue) {
    T swap = 0;
    for (int i = 0; i < rotationValue; i++) {
        swap = List.back();
        List.pop_back();
        List.push_front(swap);
    }
}

template <class T>
void roateListLeft(std::list<T>& List, int rotationValue) {
    T swap = 0;
    for (int i = 0; i < rotationValue; i++) {
        swap = List.front();
        List.pop_front();
        List.push_back(swap);
    }
}