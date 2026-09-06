#include "UnresolvedIterator.h"
#include <iostream>
#include <algorithm>
using namespace std;

UnresolvedIterator::UnresolvedIterator(ComplaintComponent* root)
    : currentIndex(0) {
    if(root) {
        root->collectComplaints(snapshot);
        filterUnresolved();
        sortSnapshot();
    }
}

UnresolvedIterator::~UnresolvedIterator() {
}

bool UnresolvedIterator::hasNext() {
    return (size_t)currentIndex < snapshot.size();
}

ComplaintComponent* UnresolvedIterator::next() {
    if(hasNext()) {
        return snapshot[currentIndex++];
    }
    return nullptr;
}

void UnresolvedIterator::reset() {
    currentIndex = 0;
}

void UnresolvedIterator::filterUnresolved() {
    vector<ComplaintComponent*> filtered;
    for(auto c : snapshot) {
        if(c->isUnresolved()) {
            filtered.push_back(c);
        }
    }
    snapshot = filtered;
}

void UnresolvedIterator::sortSnapshot() {
    sort(snapshot.begin(), snapshot.end(), [](ComplaintComponent* a, ComplaintComponent* b) {
        if (a->isUrgent() != b->isUrgent()) {
            return a->isUrgent(); // true (1) > false (0), so urgent comes first
        }
        return a->getLoggedAt() < b->getLoggedAt();
    });
}
