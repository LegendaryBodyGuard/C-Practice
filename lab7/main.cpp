#include <iostream>
#include "City.hpp"
#include "CoastalCity.hpp"

unsigned int CoastalCity::coastalCityCount = 0;

int main() {
	CoastalCity* ccityPtr;

	ccityPtr = new CoastalCity("Miami", 500000, "Atlantic Ocean", 8, "Coral Gables", 50000);

	std::cout << "The address of ccity: " << ccityPtr << std::endl;
	std::cout << "The address of adjcity: " << ccityPtr->getAdjCity() << std::endl;
	ccityPtr->printInfo();

	delete ccityPtr;
}