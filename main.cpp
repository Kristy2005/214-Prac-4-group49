#include <iostream>
#include <ctime>
#include <string>

#include "ComplaintComponent.h"
#include "Complaint.h"
#include "ComplaintGroup.h"
#include "Company.h"
#include "Building.h"
#include "FloorDepartment.h"
#include "ComplaintCategory.h"
#include "ComplaintState.h"
#include "LoggedState.h"
#include "AssignedState.h"
#include "InProgressState.h"
#include "ResolvedState.h"
#include "ClosedState.h"
#include "ComplaintDecorator.h"
#include "UrgentComplaintDecorator.h"
#include "NotificationDecorator.h"
#include "ComplaintIterator.h"
#include "AllIterator.h"
#include "UnresolvedIterator.h"

// Factory helper demonstrating optional runtime decorator application
ComplaintComponent* configureComplaint(int id, const std::string& description, bool makeUrgent, bool addNotifications) {
    time_t now = std::time(nullptr);
    // 1. Create standard base complaint (Undecorated by default)
    ComplaintComponent* comp = new Complaint(id, description, now);

    // 2. Dynamically apply Urgent decorator if requested
    if (makeUrgent) {
        comp = new UrgentComplaintDecorator(comp);
    }

    // 3. Dynamically apply Notification decorator if requested
    if (addNotifications) {
        comp = new NotificationDecorator(comp);
    }

    return comp;
}

void runScenario1() {
    std::cout << "========================================================\n";
    std::cout << " SCENARIO 1: Escalation Pipeline & Lifecycle Processing\n";
    std::cout << "========================================================\n\n";

    Company* company = new Company("TaskForge Logistics HQ");
    Building* mainBuilding = new Building("Main Distribution Hub", "100 Logistics Way");
    FloorDepartment* floor1 = new FloorDepartment("Floor 1 - Operations");
    ComplaintCategory* maintenance = new ComplaintCategory("Equipment Maintenance");

    company->add(mainBuilding);
    mainBuilding->add(floor1);
    floor1->add(maintenance);

    // Complaint 101: Standard undecorated complaint
    ComplaintComponent* c101 = configureComplaint(101, "Light bulb replacement", false, false);

    // Complaint 102: Dynamically configured with both Urgent and Notification decorators
    ComplaintComponent* c102 = configureComplaint(102, "Main Conveyor Belt Stoppage", true, true);

    // Complaint 103: Configured with Notifications only
    ComplaintComponent* c103 = configureComplaint(103, "Water leak in restroom", false, true);

    maintenance->add(c101);
    maintenance->add(c102);
    maintenance->add(c103);

    std::cout << "--- Initial System Hierarchy ---\n";
    company->display();

    std::cout << "\n--- Traversing All Complaints (Priority Ordered via AllIterator) ---\n";
    ComplaintIterator* allIt = company->createAllIterator();
    while (allIt->hasNext()) {
        ComplaintComponent* comp = allIt->next();
        comp->display();
    }
    delete allIt;

    std::cout << "\n--- Lifecycle State Transitions ---\n";
    std::cout << "Assigning Complaint #102...\n";
    c102->assign();

    std::cout << "Starting progress on Complaint #102...\n";
    c102->startProgress();

    // Snapshot iterator captured while c102 is unresolved (InProgress)
    ComplaintIterator* unresolvedSnapshot = company->createUnresolvedIterator();

    std::cout << "Resolving and closing Complaint #102...\n";
    c102->resolve();
    c102->close();

    std::cout << "\n--- Traversing Unresolved Snapshot (Captured Before Resolution) ---\n";
    while (unresolvedSnapshot->hasNext()) {
        ComplaintComponent* comp = unresolvedSnapshot->next();
        comp->display();
    }
    delete unresolvedSnapshot;

    delete company; // Clean up composite hierarchy and attached decorators
}

void runScenario2() {
    std::cout << "\n========================================================\n";
    std::cout << " SCENARIO 2: Dynamic Restructuring & Runtime Decoration\n";
    std::cout << "========================================================\n\n";

    Company* company = new Company("TaskForge Logistics Network");
    Building* siteA = new Building("Site A - Sorting", "12 Hub Road");
    Building* siteB = new Building("Site B - Receiving", "14 Hub Road");

    FloorDepartment* deptA = new FloorDepartment("Dept A - Inbound");
    FloorDepartment* deptB = new FloorDepartment("Dept B - Outbound");

    company->add(siteA);
    company->add(siteB);
    siteA->add(deptA);
    siteB->add(deptB);

    // Plain complaint created undecorated by default
    Complaint* c104 = new Complaint(104, "Hydraulic Fluid Leak", std::time(nullptr) - 7200);
    deptA->add(c104);

    std::cout << "--- Initial System Setup ---\n";
    company->display();

    ComplaintIterator* preMoveIterator = company->createAllIterator();

    // 1. Structural change at runtime (re-parenting node)
    std::cout << "\n--- Moving Complaint #104 from Dept A to Dept B ---\n";
    ComplaintComponent* removed = deptA->remove(c104);
    if (removed != nullptr) {
        deptB->add(removed);
        std::cout << "Complaint #104 successfully re-assigned to Dept B.\n";
    }

    // 2. Runtime Decorator change: Dynamically wrap the existing object
    std::cout << "\n--- Dynamically Elevating Complaint #104 with Urgent & Notification Decorators ---\n";
    deptB->remove(removed);
    
    // Dynamically stack decorators onto the plain complaint object
    removed = new UrgentComplaintDecorator(removed);
    removed = new NotificationDecorator(removed);
    
    deptB->add(removed);

    ComplaintIterator* postMoveIterator = company->createAllIterator();

    std::cout << "\n--- Pre-Modification Snapshot Output ---\n";
    while (preMoveIterator->hasNext()) {
        ComplaintComponent* comp = preMoveIterator->next();
        comp->display();
    }

    std::cout << "\n--- Post-Modification Output ---\n";
    while (postMoveIterator->hasNext()) {
        ComplaintComponent* comp = postMoveIterator->next();
        comp->display();
    }

    delete preMoveIterator;
    delete postMoveIterator;
    delete company;
}

int main() {
    runScenario1();
    runScenario2();
    return 0;
}