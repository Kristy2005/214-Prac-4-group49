#include "Building.h"
#include <iostream>
using namespace std;

Building::Building(string name, string address)
    : ComplaintGroup(name), address(address){}

void Building::display() {
    ComplaintGroup::display();
}

string Building::getAddress() {
    return this->address;
}
