#ifndef FLOORDEPARTMENT_H
#define FLOORDEPARTMENT_H
#include <string>
#include "ComplaintGroup.h"
using namespace std;


class FloorDepartment : public ComplaintGroup {


public:
	FloorDepartment(string name);
	void display();
};

#endif
