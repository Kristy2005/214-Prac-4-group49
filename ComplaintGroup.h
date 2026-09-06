#ifndef COMPLAINTGROUP_H
#define COMPLAINTGROUP_H
#include <vector>
#include <string>
#include "ComplaintComponent.h"
#include "ComplaintIterator.h"
using namespace std;

class ComplaintGroup : public ComplaintComponent {

protected:
	string name;
private:
	vector<ComplaintComponent*> children;

public:
	ComplaintGroup(string name);
	~ComplaintGroup();
	void add(ComplaintComponent* component);
	ComplaintComponent* remove(ComplaintComponent* component);
	void display();
	void assign();
	void startProgress();
	void resolve();
	void close();
	bool isUrgent();
	bool isUnresolved();
	time_t getLoggedAt();
	string getStateName();
	void collectComplaints(vector<ComplaintComponent*>& list);
	ComplaintIterator* createAllIterator();
	ComplaintIterator* createUnresolvedIterator();
};

#endif
