#include "Yuvraj_Oct1_task1_HybridVehicle.h"
#include <iostream>
using namespace std;

int main() {
    HybridVehicle v1("Prius", 120.5, 80.0, 4.5);
    HybridVehicle v2("Volt", 100.0, 90.0, 5.0);

    v1[0] = 50; v1[1] = 60;
    v2[0] = 70; v2[1] = 40;

    cout << "Vehicle 1: " << v1 << endl;
    cout << "Vehicle 2: " << v2 << endl;

    HybridVehicle v3 = v1 + v2;
    cout << "Combined Vehicle: " << v3 << endl;

    cout << "Efficiency compare (==): " << (v1 == v2 ? "Equal" : "Not Equal") << endl;

    ++v1;
    cout << "After ++: " << v1 << endl;

    cout << "Trip[1] of v2: " << v2[1] << endl;

    cout << "Total Distance v1: " << v1() << endl;

    cout << "Efficiency of v2 (km/L): " << float(v2) << endl;

    HybridVehicle v4;
    v4 = v1;
    cout << "Copied Vehicle v4: " << v4 << endl;

    return 0;
}
