#include "AllIterator.h"
#include <iostream>
#include <algorithm>
using namespace std;

AllIterator::AllIterator(ComplaintComponent* root)
    : currentIndex(0) {
    if(root) {
        root->collectComplaints(snapshot);
        sortSnapshot();
    }
}

AllIterator::~AllIterator() {
}

bool AllIterator::hasNext() {
    return (size_t)currentIndex < snapshot.size();
}

ComplaintComponent* AllIterator::next() {
    if(hasNext()) {
        return snapshot[currentIndex++];
    }
    return nullptr;
}

void AllIterator::reset() {
    currentIndex = 0;
}

void AllIterator::sortSnapshot() {
    sort(snapshot.begin(), snapshot.end(), [](ComplaintComponent* a, ComplaintComponent* b) {
        return a->getLoggedAt() < b->getLoggedAt();
    });
}
