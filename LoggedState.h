#ifndef LOGGEDSTATE_H
#define LOGGEDSTATE_H
#include <string>
#include "ComplaintState.h"

class LoggedState : public ComplaintState {


public:
	ComplaintState* assign();
	std::string getName();
	bool isUnresolved();
};

#endif
