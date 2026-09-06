#include "InProgressState.h"
#include "ResolvedState.h"
#include <iostream>
using namespace std;

ComplaintState* InProgressState::resolve() {
	return new ResolvedState();
}

string InProgressState::getName() {
	return "In Progress";
}

bool InProgressState::isUnresolved() {
	return true;
}
