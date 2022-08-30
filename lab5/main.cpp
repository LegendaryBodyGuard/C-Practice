#include "City.hpp"
#include "CoastalCity.hpp"
#include <iostream>

unsigned int CoastalCity::coastalCityCount = 0;

int main() {
    CoastalCity ccity1("San Diego", 1500000, "Pacific", 5);

    std::cout << "The address of ccity1: " << &ccity1 << "\n";

    CoastalCity* ccityPtr1 = NULL;

    std::cout << "The address stored in ccityPtr1: " << ccityPtr1;

    ccityPtr1 = &ccity1;

    std::cout << "\nThe address stored in ccityPtr1: " << ccityPtr1;

    std::cout << "\n\nccityPtr1 used to call printInfo()\n" << "Using -> syntax\n";
    ccityPtr1->printInfo();

    std::cout << "\nUsing * syntax:\n";
    (*ccityPtr1).printInfo();

    //std::cout << &ccityPtr2;
    CoastalCity* ccityPtr2 = new CoastalCity("Miamidog", 500000, "Atlantic Ocean", 8);

    std::cout << "\nThe address stored in ccityPtr2: " << ccityPtr2;

    std::cout << "\n\nccityPtr2 used to call printInfo()\n" << "Using -> syntax\n";
    ccityPtr2->printInfo();

    std::cout << "\nUsing * syntax:\n";
    (*ccityPtr2).printInfo();

    delete ccityPtr2;

    std::cout << "\nThe address stored in ccityPtr2: " << ccityPtr2;

    return 0;
}