#include "UrgentComplaintDecorator.h"
#include <iostream>
using namespace std;

UrgentComplaintDecorator::UrgentComplaintDecorator(ComplaintComponent* component)
    : ComplaintDecorator(component){}

void UrgentComplaintDecorator::display() {
    cout << " [URGENT]";
    ComplaintDecorator::display();
}

bool UrgentComplaintDecorator::isUrgent() {
    return true;
}
