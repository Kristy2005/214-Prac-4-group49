#ifndef ASSIGNEDSTATE_H
#define ASSIGNEDSTATE_H
#include "ComplaintState.h"
#include <vector>
#include <string>
using namespace std;

class AssignedState : public ComplaintState{


public:
	ComplaintState* startProgress();
	string getName();
	bool isUnresolved();
};

#endif
