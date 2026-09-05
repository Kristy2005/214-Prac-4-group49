#ifndef COMPLAINTDECORATOR_H
#define COMPLAINTDECORATOR_H
#include <vector>
#include <string>
#include "ComplaintComponent.h"

class ComplaintDecorator : public ComplaintComponent {

public:
	ComplaintComponent* wrappedComponent;
	ComplaintDecorator(ComplaintComponent* component);
	virtual ~ComplaintDecorator();
	void display();
	void assign();
	void startProgress();
	virtual void resolve();
	void close();
	bool isUrgent();
	bool isUnresolved();
	time_t getLoggedAt();
	std::string getStateName();
	void collectComplaints(std::vector<ComplaintComponent*>& list);
};

#endif
