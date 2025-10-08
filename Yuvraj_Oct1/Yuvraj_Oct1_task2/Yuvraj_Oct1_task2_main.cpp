#include "Yuvraj_Oct1_task2_BatteryMonitor.h"
#include <iostream>
using namespace std;

int main() {
    BatteryMonitor bm1(5);
    bm1.inputReadings();

    cout << "Battery Monitor 1 Readings: ";
    bm1.displayReadings();

    BatteryMonitor bm2 = bm1; // copy constructor
    cout << "Battery Monitor 2 (copy of 1): ";
    bm2.displayReadings();

    bm2[2] = 99; // modify one reading
    cout << "Modified Battery Monitor 2: ";
    bm2.displayReadings();

    cout << "Battery Monitor 1 == Battery Monitor 2? "
         << (bm1 == bm2 ? "Yes" : "No") << endl;

    BatteryMonitor bm3(5);
    bm3 = bm1; // assignment
    cout << "Battery Monitor 3 (assigned from 1): ";
    bm3.displayReadings();

    cout << "Battery Monitor 1 != Battery Monitor 3? "
         << (bm1 != bm3 ? "Yes" : "No") << endl;

    return 0;
}
