#ifndef BUILDING_H
#define BUILDING_H
#include "ComplaintGroup.h"
#include <string>
using namespace std;

class Building :public ComplaintGroup{

public:
	string address;
	Building(string name, string address);
	void display();
	string getAddress();
};

#endif
