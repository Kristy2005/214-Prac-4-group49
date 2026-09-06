#include "FloorDepartment.h"
#include <iostream>
using namespace std;

FloorDepartment::FloorDepartment(string name)
    : ComplaintGroup(name){}

void FloorDepartment::display() {
    ComplaintGroup::display();
}
