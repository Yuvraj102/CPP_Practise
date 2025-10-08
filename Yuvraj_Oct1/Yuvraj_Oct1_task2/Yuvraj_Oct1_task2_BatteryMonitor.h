#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <iostream>

class BatteryMonitor {
private:
    int* readings;       // dynamic array
    int size;            // number of readings

public:
    // Constructor
    BatteryMonitor(int n);

    // Copy constructor (deep copy)
    BatteryMonitor(const BatteryMonitor& other);

    // Assignment operator (deep copy)
    BatteryMonitor& operator=(const BatteryMonitor& other);

    // Destructor
    ~BatteryMonitor();

    // Input/output
    void inputReadings();
    void displayReadings() const;

    // Overloaded subscript
    int& operator[](int index);
    const int& operator[](int index) const;

    // Overloaded equality
    bool operator==(const BatteryMonitor& other) const;

    // Overloaded inequality
    bool operator!=(const BatteryMonitor& other) const;
};

#endif
