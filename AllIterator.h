#ifndef ALLITERATOR_H
#define ALLITERATOR_H
#include "ComplaintIterator.h"
#include "ComplaintComponent.h"
#include <vector>
#include <string>
using namespace std;


class AllIterator : public ComplaintIterator{

private:
	vector<ComplaintComponent*> snapshot;
	int currentIndex;

public:
	AllIterator(ComplaintComponent* root);
	~AllIterator();
	bool hasNext();
	ComplaintComponent* next();
	void reset();

private:
	void sortSnapshot();
};

#endif
