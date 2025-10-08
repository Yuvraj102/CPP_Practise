#include "Yuvraj_Oct1_task1_HybridVehicle.h"
#include <iomanip>

// Constructor
HybridVehicle::HybridVehicle(const std::string& model, float eKm, float gKm, float gUsed)
    : modelName(model), electricKm(eKm), gasolineKm(gKm), gasolineUsed(gUsed), tripCount(0) {
    for (int i = 0; i < 10; i++) trips[i] = 0;
}

// Combine two vehicles
HybridVehicle HybridVehicle::operator+(const HybridVehicle& other) const {
    HybridVehicle result("Combined",
                         electricKm + other.electricKm,
                         gasolineKm + other.gasolineKm,
                         gasolineUsed + other.gasolineUsed);
    result.tripCount = tripCount + other.tripCount;
    for (int i = 0; i < tripCount; i++) result.trips[i] = trips[i];
    for (int j = 0; j < other.tripCount; j++) result.trips[tripCount + j] = other.trips[j];
    return result;
}

// Compare efficiency
bool HybridVehicle::operator==(const HybridVehicle& other) const {
    float eff1 = (gasolineUsed > 0) ? (gasolineKm / gasolineUsed) : 0;
    float eff2 = (other.gasolineUsed > 0) ? (other.gasolineKm / other.gasolineUsed) : 0;
    return eff1 == eff2;
}

// Deep copy
HybridVehicle& HybridVehicle::operator=(const HybridVehicle& other) {
    if (this != &other) {
        modelName = other.modelName;
        electricKm = other.electricKm;
        gasolineKm = other.gasolineKm;
        gasolineUsed = other.gasolineUsed;
        tripCount = other.tripCount;
        for (int i = 0; i < 10; i++) trips[i] = other.trips[i];
    }
    return *this;
}

// Prefix ++
HybridVehicle& HybridVehicle::operator++() {
    if (tripCount < 10) {
        trips[tripCount++] = 10; // dummy trip
    }
    return *this;
}

// Subscript operator
int& HybridVehicle::operator[](int index) {
    return trips[index];
}
const int& HybridVehicle::operator[](int index) const {
    return trips[index];
}

// Total distance
float HybridVehicle::operator()() const {
    float sum = electricKm + gasolineKm;
    for (int i = 0; i < tripCount; i++) sum += trips[i];
    return sum;
}

// Efficiency
HybridVehicle::operator float() const {
    return (gasolineUsed > 0) ? (gasolineKm / gasolineUsed) : 0;
}

// Print details
std::ostream& operator<<(std::ostream& os, const HybridVehicle& v) {
    os << "Model: " << v.modelName
       << " | ElectricKm: " << v.electricKm
       << " | GasolineKm: " << v.gasolineKm
       << " | GasolineUsed: " << v.gasolineUsed
       << " | Trips: ";
    for (int i = 0; i < v.tripCount; i++) os << v.trips[i] << " ";
    return os;
}
