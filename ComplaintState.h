#ifndef COMPLAINTSTATE_H
#define COMPLAINTSTATE_H
#include <string>

class ComplaintState {


public:
	virtual ~ComplaintState();
	virtual ComplaintState* assign();
	virtual ComplaintState* startProgress();
	virtual ComplaintState* resolve();
	virtual ComplaintState* close();
	virtual std::string getName() = 0;
	virtual bool isUnresolved();
};

#endif
