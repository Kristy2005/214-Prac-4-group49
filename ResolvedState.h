#ifndef RESOLVEDSTATE_H
#define RESOLVEDSTATE_H
#include <string>
#include "ComplaintState.h"
using namespace std;

class ResolvedState : public ComplaintState {


public:
	ComplaintState* close();
	string getName();
	bool isUnresolved();
};

#endif
