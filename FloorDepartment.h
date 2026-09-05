#ifndef FLOORDEPARTMENT_H
#define FLOORDEPARTMENT_H
#include <string>
#include "ComplaintGroup.h"


class FloorDepartment : public ComplaintGroup {


public:
	FloorDepartment(std::string name);
	void display();
};

#endif
