#include "LoggedState.h"
#include "AssignedState.h"
#include <iostream>
using namespace std;

ComplaintState* LoggedState::assign() {
	return new AssignedState();
}

string LoggedState::getName() {
	return "Logged";
}

bool LoggedState::isUnresolved() {
	return true;
}
