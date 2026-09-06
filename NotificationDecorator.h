#ifndef NOTIFICATIONDECORATOR_H
#define NOTIFICATIONDECORATOR_H
#include <string>
#include "ComplaintDecorator.h"
using namespace std;

class NotificationDecorator : public ComplaintDecorator {


public:
	NotificationDecorator(ComplaintComponent* component);
	void display();
	void assign();
	void startProgress();
	void resolve();
	void close();

private:
	void notify(string message);
};

#endif
