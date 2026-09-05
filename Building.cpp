#include "Building.h"
#include <iostream>

Building::Building(std::string name, std::string address)
    : ComplaintGroup(name), address(address){}

void Building::display() {
	// TODO - implement Building::display

}

std::string Building::getAddress() {
	return this->address;
}
