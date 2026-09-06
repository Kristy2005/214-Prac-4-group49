#ifndef UNRESOLVEDITERATOR_H
#define UNRESOLVEDITERATOR_H
#include <string>
#include <vector>
#include "ComplaintIterator.h"
#include "ComplaintComponent.h"
using namespace std;


class UnresolvedIterator : public ComplaintIterator {

private:
	vector<ComplaintComponent*> snapshot;
	int currentIndex;

public:
	UnresolvedIterator(ComplaintComponent* root);
	~UnresolvedIterator();
	bool hasNext();
	ComplaintComponent* next();
	void reset();

private:
	void filterUnresolved();
	void sortSnapshot();
};

#endif
