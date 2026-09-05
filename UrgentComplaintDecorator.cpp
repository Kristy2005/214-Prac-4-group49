#include "UrgentComplaintDecorator.h"

UrgentComplaintDecorator::UrgentComplaintDecorator(ComplaintComponent* component)
    : ComplaintDecorator(component){}

void UrgentComplaintDecorator::display() {
	// TODO - implement UrgentComplaintDecorator::display

}

bool UrgentComplaintDecorator::isUrgent() {
	// TODO - implement UrgentComplaintDecorator::isUrgent
	return false;
}
