#ifndef COMPANY_H
#define COMPANY_H
#include "ComplaintGroup.h"
#include <string>

class Company : public ComplaintGroup {


public:
	Company(std::string name);
	void display();
};

#endif
