#include "ComplaintGroup.h"
#include <iostream>

ComplaintGroup::ComplaintGroup(std::string name)
    : name(name){}

ComplaintGroup::~ComplaintGroup(){

    for(int i = 0; i < static_cast<int>(children.size()); i++){
		
        if (children[i] != nullptr){
            delete children[i];
            children[i] = nullptr;
        }
    }

    children.clear();
}

void ComplaintGroup::add(ComplaintComponent* component) {
	// TODO - implement ComplaintGroup::add

}

ComplaintComponent* ComplaintGroup::remove(ComplaintComponent* component) {
	// TODO - implement ComplaintGroup::remove
	return nullptr;
}

void ComplaintGroup::display() {
	// TODO - implement ComplaintGroup::display
	
}

void ComplaintGroup::assign() {
	// TODO - implement ComplaintGroup::assign
	
}

void ComplaintGroup::startProgress() {
	// TODO - implement ComplaintGroup::startProgress
	
}

void ComplaintGroup::resolve() {
	// TODO - implement ComplaintGroup::resolve
	
}

void ComplaintGroup::close() {
	// TODO - implement ComplaintGroup::close
	
}

bool ComplaintGroup::isUrgent() {
	// TODO - implement ComplaintGroup::isUrgent
	return false;
}

bool ComplaintGroup::isUnresolved() {
	// TODO - implement ComplaintGroup::isUnresolved
	return false;
}

time_t ComplaintGroup::getLoggedAt() {
	// TODO - implement ComplaintGroup::getLoggedAt
	return 0;
}

std::string ComplaintGroup::getStateName() {
	// TODO - implement ComplaintGroup::getStateName
	return "";
}

void ComplaintGroup::collectComplaints(std::vector<ComplaintComponent*>& list) {
	// TODO - implement ComplaintGroup::collectComplaints

}

ComplaintIterator* ComplaintGroup::createAllIterator() {
	// TODO - implement ComplaintGroup::createAllIterator
	return nullptr;
}

ComplaintIterator* ComplaintGroup::createUnresolvedIterator() {
	// TODO - implement ComplaintGroup::createUnresolvedIterator
	return nullptr;
}
