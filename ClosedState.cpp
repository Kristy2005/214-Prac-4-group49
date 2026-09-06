#include "ClosedState.h"
#include <iostream>
using namespace std;

string ClosedState::getName() {
	return "Closed";
}

bool ClosedState::isUnresolved() {
	return false;
}
