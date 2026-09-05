#ifndef URGENTCOMPLAINTDECORATOR_H
#define URGENTCOMPLAINTDECORATOR_H
#include "ComplaintDecorator.h"

class UrgentComplaintDecorator : public ComplaintDecorator {


public:
	UrgentComplaintDecorator(ComplaintComponent* component);
	void display();
	bool isUrgent();
};

#endif
