#ifndef COMPLAINTGROUP_H
#define COMPLAINTGROUP_H
#include <vector>
#include <string>
#include "ComplaintComponent.h"
#include "ComplaintIterator.h"

class ComplaintGroup : public ComplaintComponent {

private:
	std::string name;
	std::vector<ComplaintComponent*> children;

public:
	ComplaintGroup(std::string name);
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
	std::string getStateName();
	void collectComplaints(std::vector<ComplaintComponent*>& list);
	ComplaintIterator* createAllIterator();
	ComplaintIterator* createUnresolvedIterator();
};

#endif
