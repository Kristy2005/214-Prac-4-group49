#include "Complaint.h"
#include "LoggedState.h"
#include <iostream>
using namespace std;

Complaint::Complaint(int id, string description, time_t loggedAt)
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
    cout << "Complaint #" << id << ": " << description 
              << " [" << getStateName() << "]" << (isUrgent() ? " [URGENT]" : "") << endl;
}

void Complaint::assign() {
    changeState(currentState->assign());
}

void Complaint::startProgress() {
    changeState(currentState->startProgress());
}

void Complaint::resolve() {
    changeState(currentState->resolve());
}

void Complaint::close() {
    changeState(currentState->close());
}

bool Complaint::isUrgent() {
    return false;
}

bool Complaint::isUnresolved() {
    return currentState->isUnresolved();
}

time_t Complaint::getLoggedAt() {
    return this->loggedAt;
}

string Complaint::getStateName() {
    return currentState->getName();
}

void Complaint::collectComplaints(vector<ComplaintComponent*>& list) {
    list.push_back(this);
}

void Complaint::changeState(ComplaintState* newState) {
    if (newState != nullptr && newState != currentState) {
        delete currentState;
        currentState = newState;
    }
}
