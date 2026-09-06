#include "ComplaintCategory.h"
#include <iostream>
using namespace std;

ComplaintCategory::ComplaintCategory(string name)
    : ComplaintGroup(name){}

void ComplaintCategory::display() {
    ComplaintGroup::display();
}
