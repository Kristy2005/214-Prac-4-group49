#include "AssignedState.h"
#include "InProgressState.h"
#include <iostream>
using namespace std;

ComplaintState* AssignedState::startProgress() {
	return new InProgressState();
}

string AssignedState::getName() {
	return "Assigned";
}

bool AssignedState::isUnresolved() {
	return true;
}
