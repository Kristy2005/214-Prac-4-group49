#include "ResolvedState.h"
#include "ClosedState.h"
#include <iostream>
using namespace std;

ComplaintState* ResolvedState::close() {
	return new ClosedState();
}

string ResolvedState::getName() {
	return "Resolved";
}

bool ResolvedState::isUnresolved() {
	return false;
}
