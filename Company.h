#ifndef COMPANY_H
#define COMPANY_H
#include "ComplaintGroup.h"
#include <string>
using namespace std;

class Company : public ComplaintGroup {


public:
	Company(string name);
	void display();
};

#endif
