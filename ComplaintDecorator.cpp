#include "ComplaintDecorator.h"
#include <iostream>
using namespace std;

ComplaintDecorator::ComplaintDecorator(ComplaintComponent* component)
    : wrappedComponent(component){}

ComplaintDecorator::~ComplaintDecorator(){
    if (wrappedComponent != nullptr){
        delete wrappedComponent;
        wrappedComponent = nullptr;
    }
}

void ComplaintDecorator::display() {
    if(wrappedComponent) wrappedComponent->display();
}

void ComplaintDecorator::assign() {
    if(wrappedComponent) wrappedComponent->assign();
}

void ComplaintDecorator::startProgress() {
    if(wrappedComponent) wrappedComponent->startProgress();
}

void ComplaintDecorator::resolve() {
    if(wrappedComponent) wrappedComponent->resolve();
}

void ComplaintDecorator::close() {
    if(wrappedComponent) wrappedComponent->close();
}

bool ComplaintDecorator::isUrgent() {
    return wrappedComponent ? wrappedComponent->isUrgent() : false;
}

bool ComplaintDecorator::isUnresolved() {
    return wrappedComponent ? wrappedComponent->isUnresolved() : false;
}

time_t ComplaintDecorator::getLoggedAt() {
    return wrappedComponent ? wrappedComponent->getLoggedAt() : 0;
}

string ComplaintDecorator::getStateName() {
    return wrappedComponent ? wrappedComponent->getStateName() : "";
}

void ComplaintDecorator::collectComplaints(vector<ComplaintComponent*>& list) {
    list.push_back(this);
}
