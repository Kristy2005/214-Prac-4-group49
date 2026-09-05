#ifndef COMPLAINT_H
#define COMPLAINT_H
#include <vector>
#include <string>
#include "ComplaintState.h"
#include "ComplaintComponent.h"

class Complaint : public ComplaintComponent {

private:
	int id;
	std::string description;
	time_t loggedAt;
	ComplaintState* currentState;

public:
	Complaint(int id, std::string description, time_t loggedAt);
	~Complaint();
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

private:
	void changeState(ComplaintState* newState);
};

#endif
