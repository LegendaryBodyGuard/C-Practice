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
void printList(const std::list<T>&List);
template <class T>
void printCityList(const std::list<T> List);
template <class T>
void rotateListRight(std::list<T>& List, int rotationValue);
template <class T>
void rotateListLeft(std::list<T>& List, int rotationValue);
template <class T>
void removeFromCityList(std::list<T>& List, std::string userInputCity);
void InsertToCityList(std::list<City>& List1, City cityToAdd, std::string userInputCity);

int main() {
    std::cout << "Initializing intList with A[]: " << std::endl;
    initList(intList, a, 5);
    printList(intList);
    std::cout << "\n";
    std::cout << "\nInitializing intList with cityArray[]: " << std::endl;
    initList(cityList, cityArray, 5);
    printCityList(cityList);
    std::cout << "\nRotating intList to right twice: " << std::endl;
    rotateListRight(intList, 2);
    printList(intList);
    std::cout << "\n";
    std::cout << "\nRotating cityList to right one: " << std::endl;
    rotateListRight(cityList, 1);
    printCityList(cityList);
    std::cout << "\nRotating intList to left one: " << std::endl;
    rotateListLeft(intList, 1);
    printList(intList);
    std::cout << "\n";
    std::cout << "\nRotating intList to left twice: " << std::endl;
    rotateListLeft(cityList, 2);
    printCityList(cityList);
    std::cout << "\n";
    std::cout << "\nRemoving Stockton from cityList: " << std::endl;
    removeFromCityList(cityList, "Sacramento");
    printCityList(cityList);
    std::cout << "\n";
    std::cout << "\nAdding Lodi to cityList before Stockton: " << std::endl;
    InsertToCityList(cityList, City("Lodi",45000), "Stockton");
    printCityList(cityList);
}

template <class T>
void initList(std::list<T>& List, T arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        List.push_back(arr[i]);
    }
}

template <class T>
void printList(const std::list<T> & List) {
    std::string test;
    for (T i : List) {
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
    for (int i = 0; i < rotationValue; i++) {
        T swap = List.back();
        List.pop_back();
        List.push_front(swap);
    }
}

template <class T>
void rotateListLeft(std::list<T>& List, int rotationValue) {
    for (int i = 0; i < rotationValue; i++) {
        T swap = List.front();
        List.pop_front();
        List.push_back(swap);
    }
}

template <class T>
void removeFromCityList(std::list<T>& List, std::string userInputCity) {
    //list.begin() = san diego
    for (std::list<City>::iterator it = List.begin(); it != List.end(); it++) {
        //c = sandiego
        City c = *it;
        //c.(san digeo).compare(stockton) will give you because there not the same 1 == 0
        if (c.getName().compare(userInputCity) == 0) {
            //if it is the same it get erase
            List.erase(it);
            break;
        }
    } 
} 

void InsertToCityList(std::list<City> &List, City cityToAdd, std::string userInputCity) {
    for (std::list<City>::iterator it = List.begin(); it != List.end(); ++it) {
        //c = sandiego
        City c = *it;
        //c.(san digeo).compare(stockton) will give you because there not the same 1 == 0
        if (c.getName().compare(userInputCity) == 0) {
            //if it is the same it get add
            List.insert(it,cityToAdd);
            break;
        }
    }
}