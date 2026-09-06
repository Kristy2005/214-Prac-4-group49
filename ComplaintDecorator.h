#ifndef COMPLAINTDECORATOR_H
#define COMPLAINTDECORATOR_H
#include <vector>
#include <string>
#include "ComplaintComponent.h"
using namespace std;

class ComplaintDecorator : public ComplaintComponent {

protected:
	ComplaintComponent* wrappedComponent;
public:
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
	string getStateName();
	void collectComplaints(vector<ComplaintComponent*>& list);
};

#endif
