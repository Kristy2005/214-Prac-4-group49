#include "Company.h"
#include <iostream>
using namespace std;

Company::Company(string name)
    : ComplaintGroup(name){}

void Company::display() {
    ComplaintGroup::display();
}
