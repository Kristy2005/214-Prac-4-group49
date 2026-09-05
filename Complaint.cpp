#include "Complaint.h"
#include "LoggedState.h"

Complaint::Complaint(int id, std::string description, time_t loggedAt)
    : id(id), description(description), loggedAt(loggedAt){
    currentState = new LoggedState();
}

Complaint::~Complaint(){
	
    if (currentState != nullptr){
        delete currentState;
        currentState = nullptr;
    }
}

void Complaint::display() {
	// TODO - implement Complaint::display

}

void Complaint::assign() {
	// TODO - implement Complaint::assign

}

void Complaint::startProgress() {
	// TODO - implement Complaint::startProgress

}

void Complaint::resolve() {
	// TODO - implement Complaint::resolve

}

void Complaint::close() {
	// TODO - implement Complaint::close

}

bool Complaint::isUrgent() {
	// TODO - implement Complaint::isUrgent
	return false;
}

bool Complaint::isUnresolved() {
	// TODO - implement Complaint::isUnresolved
	return false;
}

time_t Complaint::getLoggedAt() {
	return this->loggedAt;

}

std::string Complaint::getStateName() {
	// TODO - implement Complaint::getStateName
	return "";
}

void Complaint::collectComplaints(std::vector<ComplaintComponent*>& list) {
	// TODO - implement Complaint::collectComplaints

}

void Complaint::changeState(ComplaintState* newState) {
	// TODO - implement Complaint::changeState

}
