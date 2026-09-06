#include "ComplaintState.h"
using namespace std;

ComplaintState::~ComplaintState() {
}

ComplaintState* ComplaintState::assign() {
	return this;
}

ComplaintState* ComplaintState::startProgress() {
	return this;
}

ComplaintState* ComplaintState::resolve() {
	return this;
}

ComplaintState* ComplaintState::close() {
	return this;
}

bool ComplaintState::isUnresolved() {
	return true;
}
