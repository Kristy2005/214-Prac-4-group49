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


// Factory helper that builds a complaint and optionally wraps it with decorators.
// This demonstrates the Decorator pattern at runtime, without changing the
// complaint's original interface.
ComplaintComponent* configureComplaint(int id, const std::string& description, bool makeUrgent, bool addNotifications) {
    time_t now = std::time(nullptr);

    // 1. Create a base complaint with no extra behaviour.
    ComplaintComponent* comp = new Complaint(id, description, now);

    // 2. Attach an urgent decorator if the scenario requires it.
    if (makeUrgent) {
        comp = new UrgentComplaintDecorator(comp);
    }

    // 3. Attach a notification decorator if the scenario requires it.
    if (addNotifications) {
        comp = new NotificationDecorator(comp);
    }

    return comp;
}

// Scenario 1: create a complaint hierarchy, display it, process lifecycle changes,
// and then iterate over the unresolved complaints that existed before resolution.
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

    // Complaint 101: Standard undecorated complaint.
    ComplaintComponent* c101 = configureComplaint(101, "Light bulb replacement", false, false);

    // Complaint 102: Has both Urgent and Notification decorators applied at runtime.
    ComplaintComponent* c102 = configureComplaint(102, "Main Conveyor Belt Stoppage", true, true);

    // Complaint 103: Notification decorator only.
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

    // Snapshot iterator captured while c102 is unresolved (InProgress).
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

    // Frees the full composite hierarchy and all decorator layers.
    delete company;
}

// Scenario 2: dynamic movement of complaints within the hierarchy and runtime
// decoration changes to demonstrate the flexibility of the Composite + Decorator design.
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

    // A plain complaint is created without any extra decoration initially.
    Complaint* c104 = new Complaint(104, "Hydraulic Fluid Leak", std::time(nullptr) - 7200);
    deptA->add(c104);

    std::cout << "--- Initial System Setup ---\n";
    company->display();

    ComplaintIterator* preMoveIterator = company->createAllIterator();

    // 1. Structural change at runtime: re-parent the complaint into another department.
    std::cout << "\n--- Moving Complaint #104 from Dept A to Dept B ---\n";
    ComplaintComponent* removed = deptA->remove(c104);
    if (removed != nullptr) {
        deptB->add(removed);
        std::cout << "Complaint #104 successfully re-assigned to Dept B.\n";
    }

    // 2. Runtime Decorator change: dynamically wrap the existing complaint object.
    std::cout << "\n--- Dynamically Elevating Complaint #104 with Urgent & Notification Decorators ---\n";
    deptB->remove(removed);

    // This demonstrates that extra behaviour can be added after creation.
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

/*
#include <thread>
#include <chrono>

ComplaintComponent* logInteractiveComplaint(int assignedId) {
    std::string description;
    char choice;

    std::cout << "========================================================\n";
    std::cout << "         TASKFORGE: INTERACTIVE COMPLAINT LOGGING       \n";
    std::cout << "========================================================\n\n";

    std::cout << "System generated Complaint ID assigned: #" << assignedId << "\n";
    std::cout << "Enter complaint description: ";
    
    // Clear any leftover characters in the buffer before reading full line
    if (std::cin.peek() == '\n') std::cin.ignore();
    std::getline(std::cin, description);

    // Create the core leaf object
    time_t now = std::time(nullptr);
    ComplaintComponent* comp = new Complaint(assignedId, description, now);

    // Decorator selection 1: Urgent
    std::cout << "\n[Decorator Configuration]\n";
    std::cout << "Mark this complaint as URGENT? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        comp = new UrgentComplaintDecorator(comp);
        std::cout << "-> Applied: UrgentComplaintDecorator\n";
    }

    // Decorator selection 2: Notification
    std::cout << "Enable SMS/Email NOTIFICATIONS for this complaint? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        comp = new NotificationDecorator(comp);
        std::cout << "-> Applied: NotificationDecorator\n";
    }

    // Flush any remaining trailing newlines from stream
    std::cin.ignore(10000, '\n');

    return comp;
}

int main() {
    std::cout << "Starting TaskForge Interactive System Demo...\n\n";

    // Build base hierarchy
    Company* company = new Company("TaskForge Logistics HQ");
    Building* hub = new Building("Main Hub", "500 Supply Chain Way");
    FloorDepartment* ops = new FloorDepartment("Operations Floor");
    ComplaintCategory* category = new ComplaintCategory("Logistics & Fleet Issue");

    company->add(hub);
    hub->add(ops);
    ops->add(category);

    // 1. Physically Log a Complaint
    static int nextId = 201;
    ComplaintComponent* userComplaint = logInteractiveComplaint(nextId);
    category->add(userComplaint);

    std::cout << "\n--------------------------------------------------------\n";
    std::cout << "[SYSTEM NOTICE] Complaint #" << nextId << " has been logged into the system.\n";
    std::cout << "--------------------------------------------------------\n";

    std::cout << "\n--- Current System Hierarchy ---\n";
    company->display();

    // 2. Demonstrate Iterator Traversal
    std::cout << "\n--- Iterating Through Logging System ---\n";
    ComplaintIterator* iterator = company->createAllIterator();
    while (iterator->hasNext()) {
        ComplaintComponent* item = iterator->next();
        item->display();
    }
    delete iterator;

    // 3. Automated State Progression with Timed Delays & Final Interactive Confirmation
    std::cout << "\n--- Automated Lifecycle State Processing ---\n";
    
    // Step A: Assigning
    std::cout << "\n[System] Dispatching technician to complaint #" << nextId << "...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    userComplaint->assign();

    // Step B: Progress
    std::cout << "\n[System] Work underway on site...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    userComplaint->startProgress();

    // Step C: Resolving
    std::cout << "\n[System] Technician completing repair...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    userComplaint->resolve();

    // Step D: User Interaction for Final Verification & Closure
    std::cout << "\n--------------------------------------------------------\n";
    std::cout << "Technician reports issue resolved. Press Enter to inspect and close Complaint #" << nextId << "...";
    std::cin.get();

    userComplaint->close();

    std::cout << "\nComplaint #" << nextId << " successfully closed and archived!\n";

    delete company;
    return 0;
}
*/