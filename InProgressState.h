#ifndef INPROGRESSSTATE_H
#define INPROGRESSSTATE_H
#include <string>
#include "ComplaintState.h"

class InProgressState : public ComplaintState {


public:
	ComplaintState* resolve();
	std::string getName();
	bool isUnresolved();
};

#endif
