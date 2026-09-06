#ifndef COMPLAINTCATEGORY_H
#define COMPLAINTCATEGORY_H
#include <vector>
#include <string>
#include "ComplaintGroup.h"
using namespace std;


class ComplaintCategory : public ComplaintGroup {


public:
	ComplaintCategory(string name);

	void display();
};

#endif
