#include <iostream>
#include "City.hpp"
#include "CoastalCity.hpp"

unsigned int CoastalCity::coastalCityCount = 0;

int main(){
    CoastalCity ccity1, *ccityPtr1;

    ccity1.setName("San Diego");
    ccity1.setPopulation(1500000);
    ccity1.setWaterName("Pacific Ocean");
    ccity1.setBeachNum(5);

    std::cout << &ccity1 << "\n";
    

    ccityPtr1 = NULL;

    std::cout << ccityPtr1;
    
    ccityPtr1 = &ccity1;
    
    std::cout << ccityPtr1;
    
    ccityPtr1->printInfo();

    (*ccityPtr1).printInfo();

    CoastalCity *ccityPtr2 = new CoastalCity("Miami", 500000, "Atlantic Ocean", 8);

    //std::cout << &ccityPtr2;
    


    return 0;
}