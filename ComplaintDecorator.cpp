#include "ComplaintDecorator.h"
#include <iostream>

ComplaintDecorator::ComplaintDecorator(ComplaintComponent* component)
    : wrappedComponent(component){}

ComplaintDecorator::~ComplaintDecorator(){
	
    if (wrappedComponent != nullptr){
        delete wrappedComponent;
        wrappedComponent = nullptr;
    }
}

void ComplaintDecorator::display() {
	// TODO - implement ComplaintDecorator::display

}

void ComplaintDecorator::assign() {
	// TODO - implement ComplaintDecorator::assign

}

void ComplaintDecorator::startProgress() {
	// TODO - implement ComplaintDecorator::startProgress

}

void ComplaintDecorator::resolve() {
	// TODO - implement ComplaintDecorator::resolve

}

void ComplaintDecorator::close() {
	// TODO - implement ComplaintDecorator::close

}

bool ComplaintDecorator::isUrgent() {
	// TODO - implement ComplaintDecorator::isUrgent
	return false;
}

bool ComplaintDecorator::isUnresolved() {
	// TODO - implement ComplaintDecorator::isUnresolved
	return false;
}

time_t ComplaintDecorator::getLoggedAt() {
	// TODO - implement ComplaintDecorator::getLoggedAt
	return 0;
}

std::string ComplaintDecorator::getStateName() {
	// TODO - implement ComplaintDecorator::getStateName
	return "";
}

void ComplaintDecorator::collectComplaints(std::vector<ComplaintComponent*>& list) {
	// TODO - implement ComplaintDecorator::collectComplaints

}
