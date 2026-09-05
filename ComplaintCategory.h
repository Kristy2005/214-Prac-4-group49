#ifndef COMPLAINTCATEGORY_H
#define COMPLAINTCATEGORY_H
#include <vector>
#include <string>
#include "ComplaintGroup.h"


class ComplaintCategory : public ComplaintGroup {


public:
	ComplaintCategory(std::string name);

	void display();
};

#endif
