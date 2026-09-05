#ifndef CLOSEDSTATE_H
#define CLOSEDSTATE_H
#include "ComplaintState.h"
#include <string>

class ClosedState :public ComplaintState {

public:
	std::string getName();
	bool isUnresolved();
};

#endif
