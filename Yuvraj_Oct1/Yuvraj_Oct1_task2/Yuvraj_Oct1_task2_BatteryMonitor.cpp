#include "Yuvraj_Oct1_task2_BatteryMonitor.h"

// Constructor
BatteryMonitor::BatteryMonitor(int n) : size(n) {
    readings = new int[size];
    for (int i = 0; i < size; i++) readings[i] = 0;
}

// Copy constructor
BatteryMonitor::BatteryMonitor(const BatteryMonitor& other) {
    size = other.size;
    readings = new int[size];
    for (int i = 0; i < size; i++) readings[i] = other.readings[i];
}

// Assignment operator
BatteryMonitor& BatteryMonitor::operator=(const BatteryMonitor& other) {
    if (this != &other) {
        delete[] readings;
        size = other.size;
        readings = new int[size];
        for (int i = 0; i < size; i++) readings[i] = other.readings[i];
    }
    return *this;
}

// Destructor
BatteryMonitor::~BatteryMonitor() {
    delete[] readings;
}

// Input readings
void BatteryMonitor::inputReadings() {
    for (int i = 0; i < size; i++) {
        std::cout << "Enter reading " << i + 1 << ": ";
        std::cin >> readings[i];
    }
}

// Display readings
void BatteryMonitor::displayReadings() const {
    for (int i = 0; i < size; i++) {
        std::cout << readings[i] << " ";
    }
    std::cout << std::endl;
}

// Subscript operator
int& BatteryMonitor::operator[](int index) {
    return readings[index];
}
const int& BatteryMonitor::operator[](int index) const {
    return readings[index];
}

// Equality operator
bool BatteryMonitor::operator==(const BatteryMonitor& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++) {
        if (readings[i] != other.readings[i]) return false;
    }
    return true;
}

// Inequality operator
bool BatteryMonitor::operator!=(const BatteryMonitor& other) const {
    return !(*this == other);
}
