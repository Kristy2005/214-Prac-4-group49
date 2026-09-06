#include "ComplaintComponent.h"
#include <iostream>
using namespace std;

ComplaintComponent::~ComplaintComponent() {
}

void ComplaintComponent::assign() {
}

void ComplaintComponent::startProgress() {
}

void ComplaintComponent::resolve() {
}

void ComplaintComponent::close() {
}

bool ComplaintComponent::isUrgent() {
	return false;
}

bool ComplaintComponent::isUnresolved() {
	return false;
}

time_t ComplaintComponent::getLoggedAt() {
	return 0;
}

string ComplaintComponent::getStateName() {
	return "";
}
