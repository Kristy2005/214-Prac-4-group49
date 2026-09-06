#include "ComplaintGroup.h"
#include "AllIterator.h"
#include "UnresolvedIterator.h"
#include <iostream>
#include <algorithm>
using namespace std;

ComplaintGroup::ComplaintGroup(string name)
    : name(name){}

ComplaintGroup::~ComplaintGroup(){
    for(int i = 0; i < static_cast<int>(children.size()); i++){
        if (children[i] != nullptr){
            delete children[i];
            children[i] = nullptr;
        }
    }
    children.clear();
}

void ComplaintGroup::add(ComplaintComponent* component) {
    if (component != nullptr) {
        children.push_back(component);
    }
}

ComplaintComponent* ComplaintGroup::remove(ComplaintComponent* component) {
    auto it = find(children.begin(), children.end(), component);
    if (it != children.end()) {
        ComplaintComponent* removed = *it;
        children.erase(it);
        return removed;
    }
    return nullptr;
}

void ComplaintGroup::display() {
    cout << "Group: " << name << endl;
    for(auto child : children) {
        child->display();
    }
}

void ComplaintGroup::assign() {
    for(auto child : children) {
        child->assign();
    }
}

void ComplaintGroup::startProgress() {
    for(auto child : children) {
        child->startProgress();
    }
}

void ComplaintGroup::resolve() {
    for(auto child : children) {
        child->resolve();
    }
}

void ComplaintGroup::close() {
    for(auto child : children) {
        child->close();
    }
}

bool ComplaintGroup::isUrgent() {
    for(auto child : children) {
        if(child->isUrgent()) return true;
    }
    return false;
}

bool ComplaintGroup::isUnresolved() {
    for(auto child : children) {
        if(child->isUnresolved()) return true;
    }
    return false;
}

time_t ComplaintGroup::getLoggedAt() {
    if (children.empty()) return 0;
    return children[0]->getLoggedAt();
}

string ComplaintGroup::getStateName() {
    return "";
}

void ComplaintGroup::collectComplaints(vector<ComplaintComponent*>& list) {
    for(auto child : children) {
        child->collectComplaints(list);
    }
}

ComplaintIterator* ComplaintGroup::createAllIterator() {
    return new AllIterator(this);
}

ComplaintIterator* ComplaintGroup::createUnresolvedIterator() {
    return new UnresolvedIterator(this);
}
