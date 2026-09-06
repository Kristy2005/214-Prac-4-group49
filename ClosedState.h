#ifndef CLOSEDSTATE_H
#define CLOSEDSTATE_H
#include "ComplaintState.h"
#include <string>
using namespace std;

class ClosedState :public ComplaintState {

public:
	string getName();
	bool isUnresolved();
};

#endif
