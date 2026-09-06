#ifndef INPROGRESSSTATE_H
#define INPROGRESSSTATE_H
#include <string>
#include "ComplaintState.h"
using namespace std;

class InProgressState : public ComplaintState {


public:
	ComplaintState* resolve();
	string getName();
	bool isUnresolved();
};

#endif
