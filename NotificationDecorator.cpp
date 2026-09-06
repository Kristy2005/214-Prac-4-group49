#include "NotificationDecorator.h"
#include <iostream>
using namespace std;

NotificationDecorator::NotificationDecorator(ComplaintComponent* component)
    : ComplaintDecorator(component){}

void NotificationDecorator::display() {
    cout << "[NOTIFICATION SENT] ";
    ComplaintDecorator::display();
}

void NotificationDecorator::assign() {
    ComplaintDecorator::assign();
    notify("assigned");
}

void NotificationDecorator::startProgress() {
    ComplaintDecorator::startProgress();
    notify("started");
}

void NotificationDecorator::resolve() {
    ComplaintDecorator::resolve();
    notify("resolved");
}

void NotificationDecorator::close() {
    ComplaintDecorator::close();
    notify("closed");
}

void NotificationDecorator::notify(string message) {
    cout << "Notification: Complaint has been " << message << endl;
}
