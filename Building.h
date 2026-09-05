#ifndef BUILDING_H
#define BUILDING_H
#include "ComplaintGroup.h"
#include <string>

class Building :public ComplaintGroup{

public:
	std::string address;
	Building(std::string name, std::string address);
	void display();
	std::string getAddress();
};

#endif
