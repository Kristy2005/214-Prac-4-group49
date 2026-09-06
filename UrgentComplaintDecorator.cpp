#include "UrgentComplaintDecorator.h"
#include <iostream>
using namespace std;

UrgentComplaintDecorator::UrgentComplaintDecorator(ComplaintComponent* component)
    : ComplaintDecorator(component){}

void UrgentComplaintDecorator::display() {
    ComplaintDecorator::display();
    cout << " [URGENT]";
}

bool UrgentComplaintDecorator::isUrgent() {
    return true;
}
