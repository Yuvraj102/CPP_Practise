#include <iostream>
#include <string>
using namespace std;

enum ComponentType {
    COMPONENT_TYPE_ENGINE,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

enum ComponentStatus {
    COMPONENT_STATUS_OPERATIONAL,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

string typeToString(ComponentType t) {
    switch (t) {
        case COMPONENT_TYPE_ENGINE: return "Engine";
        case COMPONENT_TYPE_AVIONICS: return "Avionics";
        case COMPONENT_TYPE_LANDING_GEAR: return "Landing Gear";
        case COMPONENT_TYPE_FUEL_SYSTEM: return "Fuel System";
        default: return "Unknown";
    }
}

string statusToString(ComponentStatus s) {
    switch (s) {
        case COMPONENT_STATUS_OPERATIONAL: return "Operational";
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED: return "Maintenance Required";
        case COMPONENT_STATUS_FAILED: return "Failed";
        default: return "Unknown";
    }
}

class AerospaceComponent {
private:
    int componentIdentifier;
    double componentEfficiency;
    string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;

public:
    AerospaceComponent()
        : componentIdentifier(0), componentEfficiency(100.0),
          componentManufacturer("Unknown"), componentType(COMPONENT_TYPE_ENGINE),
          componentStatus(COMPONENT_STATUS_OPERATIONAL) {}

    AerospaceComponent(int id, double eff, const string &man, ComponentType t, ComponentStatus s)
        : componentIdentifier(id), componentEfficiency(eff),
          componentManufacturer(man), componentType(t), componentStatus(s) {}

    ~AerospaceComponent() {
        cout << "Component " << componentIdentifier << " destroyed." << endl;
    }

    // Getters & setters
    void setIdentifier(int id) { componentIdentifier = id; }
    int getIdentifier() const { return componentIdentifier; }

    void setEfficiency(double eff) { componentEfficiency = eff; }
    double getEfficiency() const { return componentEfficiency; }

    void setManufacturer(const string &m) { componentManufacturer = m; }
    string getManufacturer() const { return componentManufacturer; }

    void setType(ComponentType t) { componentType = t; }
    ComponentType getType() const { return componentType; }

    void setStatus(ComponentStatus s) { componentStatus = s; }
    ComponentStatus getStatus() const { return componentStatus; }

    // Behaviors
    void UpdateStatus() {
        if (componentEfficiency < 50.0)
            componentStatus = COMPONENT_STATUS_FAILED;
        else if (componentEfficiency < 80.0)
            componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        else
            componentStatus = COMPONENT_STATUS_OPERATIONAL;
    }

    void SimulateUsage(int usageHours) {
        for (int i = 0; i < usageHours; i++) {
            componentEfficiency -= (componentEfficiency * 0.005); // reduce 0.5%
            if (componentEfficiency < 0) {
                componentEfficiency = 0;
                break;
            }
        }
        UpdateStatus();
    }

    void PerformMaintenanceCheck() {
        switch (componentStatus) {
            case COMPONENT_STATUS_OPERATIONAL:
                cout << "Component " << componentIdentifier << " is fully operational." << endl;
                break;
            case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
                cout << "Component " << componentIdentifier << " needs maintenance soon." << endl;
                break;
            case COMPONENT_STATUS_FAILED:
                cout << "Component " << componentIdentifier << " has failed! Immediate action required." << endl;
                break;
        }
    }

    void BoostEfficiency() {
        while (componentEfficiency < 100.0) {
            componentEfficiency += 1.0;
            if (componentEfficiency > 100.0) componentEfficiency = 100.0;
        }
        UpdateStatus();
    }

    void DisplayDetails() const {
        cout << "ID: " << componentIdentifier << endl;
        cout << "Efficiency: " << componentEfficiency << endl;
        cout << "Manufacturer: " << componentManufacturer << endl;
        cout << "Type: " << typeToString(componentType) << endl;
        cout << "Status: " << statusToString(componentStatus) << endl;
    }
};

// Global functions
void AssignManufacturer(AerospaceComponent &c, const string &m) {
    c.setManufacturer(m);
}

bool IsEfficient(const AerospaceComponent &c) {
    return c.getEfficiency() > 85.0;
}

bool IsSameType(const AerospaceComponent &a, const AerospaceComponent &b) {
    return a.getType() == b.getType();
}

bool IsSameStatus(const AerospaceComponent &a, const AerospaceComponent &b) {
    return a.getStatus() == b.getStatus();
}

void PrintFormattedComponentList(const AerospaceComponent list[], int size) {
    cout << "\nID | Efficiency | Manufacturer | Type | Status" << endl;
    for (int i = 0; i < size; i++) {
        cout << list[i].getIdentifier() << " | "
             << list[i].getEfficiency() << " | "
             << list[i].getManufacturer() << " | "
             << typeToString(list[i].getType()) << " | "
             << statusToString(list[i].getStatus()) << endl;
    }
}

int SearchComponentByIdentifier(const AerospaceComponent list[], int size, int searchID) {
    for (int i = 0; i < size; i++) {
        if (list[i].getIdentifier() == searchID) return i;
    }
    return -1;
}

int main() {
    AerospaceComponent components[3];
    int choice;

    do {
        cout << "\n--- Aerospace Menu ---\n";
        cout << "1. Add component details\n";
        cout << "2. Assign manufacturer\n";
        cout << "3. Simulate usage\n";
        cout << "4. Boost efficiency\n";
        cout << "5. Check maintenance status\n";
        cout << "6. Compare components\n";
        cout << "7. Search by ID\n";
        cout << "8. Display all components\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int idx, id, typeChoice, statusChoice;
            double eff;
            string man;

            cout << "Enter index (0-2): ";
            cin >> idx;
            if (idx < 0 || idx > 2) { cout << "Invalid index.\n"; continue; }

            cout << "Enter Component ID: "; cin >> id;
            cout << "Enter Efficiency (0-100): "; cin >> eff;
            if (eff < 0 || eff > 100) eff = 100.0;

            cout << "Enter Manufacturer: ";
            cin.ignore();
            getline(cin, man);
            if (man.empty()) man = "Unknown";

            cout << "Select Type (0=ENGINE,1=AVIONICS,2=LANDING_GEAR,3=FUEL_SYSTEM): ";
            cin >> typeChoice;
            if (typeChoice < 0 || typeChoice > 3) typeChoice = 0;

            cout << "Select Status (0=OPERATIONAL,1=MAINT_REQ,2=FAILED): ";
            cin >> statusChoice;
            if (statusChoice < 0 || statusChoice > 2) statusChoice = 0;

            components[idx] = AerospaceComponent(id, eff, man,
                               static_cast<ComponentType>(typeChoice),
                               static_cast<ComponentStatus>(statusChoice));
            cout << "Component stored at index " << idx << "." << endl;
        }
        else if (choice == 2) {
            int idx; string man;
            cout << "Enter index (0-2): "; cin >> idx;
            cin.ignore();
            cout << "Enter new Manufacturer: "; getline(cin, man);
            AssignManufacturer(components[idx], man);
        }
        else if (choice == 3) {
            int idx, hours;
            cout << "Enter index (0-2): "; cin >> idx;
            cout << "Enter usage hours: "; cin >> hours;
            components[idx].SimulateUsage(hours);
        }
        else if (choice == 4) {
            int idx; cout << "Enter index (0-2): "; cin >> idx;
            components[idx].BoostEfficiency();
        }
        else if (choice == 5) {
            int idx; cout << "Enter index (0-2): "; cin >> idx;
            components[idx].PerformMaintenanceCheck();
        }
        else if (choice == 6) {
            int a, b;
            cout << "Enter index A (0-2): "; cin >> a;
            cout << "Enter index B (0-2): "; cin >> b;
            cout << "Same Type? " << (IsSameType(components[a], components[b]) ? "Yes" : "No") << endl;
            cout << "Same Status? " << (IsSameStatus(components[a], components[b]) ? "Yes" : "No") << endl;
        }
        else if (choice == 7) {
            int id; cout << "Enter Component ID: "; cin >> id;
            int pos = SearchComponentByIdentifier(components, 3, id);
            if (pos != -1) {
                cout << "Component found at index " << pos << endl;
                components[pos].DisplayDetails();
            } else {
                cout << "Component not found." << endl;
            }
        }
        else if (choice == 8) {
            PrintFormattedComponentList(components, 3);
        }
    } while (choice != 9);

    return 0;
}
