#ifndef COMPLAINTITERATOR_H
#define COMPLAINTITERATOR_H
#include "ComplaintComponent.h"

class ComplaintIterator {


public:
	virtual ~ComplaintIterator();
	virtual bool hasNext() = 0;
	virtual ComplaintComponent* next() = 0;
	virtual void reset() = 0;
};

#endif
