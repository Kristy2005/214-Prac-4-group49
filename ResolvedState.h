#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H
#include <string>
#include "ComplaintState.h"

class ResolvedState : ComplaintState {


public:
	ComplaintState* close();
	std::string getName();
	bool isUnresolved();
};

#endif
