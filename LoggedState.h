#ifndef LOGGEDSTATE_H
#define LOGGEDSTATE_H
#include <string>
#include "ComplaintState.h"
using namespace std;

class LoggedState : public ComplaintState {


public:
	ComplaintState* assign();
	string getName();
	bool isUnresolved();
};

#endif
