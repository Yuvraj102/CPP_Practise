#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <cfloat>

class FleetVehicle {
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;
    bool isAvailable;
    std::string driverName;

public:
    FleetVehicle()
        : vehicleID(0), fuelLevel(50.0f), distanceTravelled(0.0), status('A'),
          isAvailable(true), driverName("Unassigned") {}

    FleetVehicle(int id, float fuel, double dist, char st, bool avail, const std::string &driver)
        : vehicleID(id), fuelLevel(fuel), distanceTravelled(dist), status(st),
          isAvailable(avail), driverName(driver) {}

    ~FleetVehicle() {
        std::cout << "Destructor called for vehicle ID: " << vehicleID << ";\n";
    }

    // Getters / Setters
    void setVehicleID(int id) { vehicleID = id; }
    int getVehicleID() const { return vehicleID; }

    void setFuelLevel(float fuel) { fuelLevel = fuel; }
    float getFuelLevel() const { return fuelLevel; }

    void setDistanceTravelled(double d) { distanceTravelled = d; }
    double getDistanceTravelled() const { return distanceTravelled; }

    void setStatus(char s) { status = s; }
    char getStatus() const { return status; }

    void setIsAvailable(bool a) { isAvailable = a; }
    bool getIsAvailable() const { return isAvailable; }

    void setDriverName(const std::string &name) { driverName = name; }
    std::string getDriverName() const { return driverName; }

    void updateStatus() {
        if (fuelLevel < 10.0f || !isAvailable) status = 'I';
        else status = 'A';
    }

    void displayInfo() const {
        std::cout << "Vehicle ID: " << vehicleID << "\n";
        std::cout << "Fuel Level: " << fuelLevel << "\n";
        std::cout << "Distance Travelled: " << distanceTravelled << "\n";
        std::cout << "Status: " << status << "\n";
        std::cout << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
        std::cout << "Driver: " << driverName << "\n";
    }
};

// Global functions
void assignDriver(FleetVehicle &vehicle, const std::string &name) {
    vehicle.setDriverName(name);
    std::cout << "Driver assigned: " << vehicle.getDriverName() << "\n";
}

void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0.0f) throw std::invalid_argument("Fuel amount must be positive.");
    vehicle.setFuelLevel(vehicle.getFuelLevel() + fuelAmount);
    std::cout << "Vehicle refueled. Current fuel: " << vehicle.getFuelLevel() << "\n";
}

// Helper input functions
int readInt(const std::string &prompt, int minVal, int maxVal) {
    int v;
    while (true) {
        std::cout << prompt;
        if (!(std::cin >> v)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Invalid integer — try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear rest of line
        if (v < minVal || v > maxVal) {
            std::cout << "  Out of range (" << minVal << " - " << maxVal << ") — try again.\n";
            continue;
        }
        return v;
    }
}

float readFloat(const std::string &prompt, float minVal = -FLT_MAX, float maxVal = FLT_MAX) {
    float v;
    while (true) {
        std::cout << prompt;
        if (!(std::cin >> v)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Invalid number — try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (v < minVal || v > maxVal) {
            std::cout << "  Out of valid range — try again.\n";
            continue;
        }
        return v;
    }
}

double readDouble(const std::string &prompt, double minVal = -1e308, double maxVal = 1e308) {
    double v;
    while (true) {
        std::cout << prompt;
        if (!(std::cin >> v)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Invalid number — try again.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (v < minVal || v > maxVal) {
            std::cout << "  Out of valid range — try again.\n";
            continue;
        }
        return v;
    }
}

std::string readNonEmptyLine(const std::string &prompt) {
    std::string s;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, s);
        if (!s.empty()) return s;
        std::cout << "  Input cannot be empty — try again.\n";
    }
}

char readStatusChar(const std::string &prompt) {
    std::string s;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, s);
        if (s.size() > 0 && (s[0] == 'A' || s[0] == 'I')) return s[0];
        std::cout << "  Enter 'A' or 'I' only.\n";
    }
}

int main() {
    FleetVehicle fleet[3];
    // sample data 
    fleet[0] = FleetVehicle(101, 45.5f, 120.0, 'A', true, "Raj");
    fleet[1] = FleetVehicle(102, 8.0f, 300.0, 'A', true, "Priya");
    

    while (true) {
        std::cout << "\n--- Fleet Menu ---\n";
        std::cout << "1. Add vehicle details\n";
        std::cout << "2. Assign a driver\n";
        std::cout << "3. Refuel a vehicle\n";
        std::cout << "4. Update status\n";
        std::cout << "5. Display vehicle info\n";
        std::cout << "6. Exit\n";
        int choice = readInt("Enter choice (1-6): ", 1, 6);

        if (choice == 6) {
            std::cout << "Exiting.\n";
            break;
        }

        switch (choice) {
            case 1: {
                int idx = readInt("Enter index to store vehicle (0-2): ", 0, 2);
                int id = readInt("Enter Vehicle ID (int): ", 0, 1000000000);
                float fuel = readFloat("Enter Fuel level (float): ", 0.0f, 10000.0f);
                double dist = readDouble("Enter Distance travelled (double): ", 0.0, 1e12);
                char st = readStatusChar("Enter Status (A/I): ");
                int availInt = readInt("Is available? 1=Yes, 0=No : ", 0, 1);
                std::string driver = readNonEmptyLine("Enter driver name (can be multiple words): ");
                fleet[idx] = FleetVehicle(id, fuel, dist, st, (availInt == 1), driver);
                std::cout << "Vehicle stored at index " << idx << ".\n";
                break;
            }
            case 2: {
                int idx = readInt("Enter index (0-2): ", 0, 2);
                std::string driver = readNonEmptyLine("Enter driver name (can be multiple words): ");
                assignDriver(fleet[idx], driver);
                break;
            }
            case 3: {
                int idx = readInt("Enter index (0-2): ", 0, 2);
                float amt = readFloat("Enter fuel amount to add: ", 0.0001f, 1e6f);
                try {
                    refuelVehicle(fleet[idx], amt);
                } catch (const std::exception &e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 4: {
                int idx = readInt("Enter index (0-2): ", 0, 2);
                fleet[idx].updateStatus();
                std::cout << "Status updated.\n";
                break;
            }
            case 5: {
                int idx = readInt("Enter index (0-2): ", 0, 2);
                fleet[idx].displayInfo();
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }

    return 0;
}
