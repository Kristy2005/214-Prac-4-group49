#ifndef ASSIGNEDSTATE_H
#define ASSIGNEDSTATE_H
#include "ComplaintState.h"
#include <vector>
#include <string>

class AssignedState : public ComplaintState{


public:
	ComplaintState* startProgress();
	std::string getName();
	bool isUnresolved();
};

#endif
