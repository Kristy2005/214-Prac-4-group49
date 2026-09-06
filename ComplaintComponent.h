#ifndef COMPLAINTCOMPONENT_H
#define COMPLAINTCOMPONENT_H
#include <vector>
#include <string>
using namespace std;

class ComplaintComponent {


public:
	virtual ~ComplaintComponent();
	virtual void display() = 0;
	virtual void assign();
	virtual void startProgress();
	virtual void resolve();
	virtual void close();
	virtual bool isUrgent();
	virtual bool isUnresolved();
	virtual time_t getLoggedAt();
	virtual string getStateName();
	virtual void collectComplaints(vector<ComplaintComponent*>& list) = 0;
};

#endif
