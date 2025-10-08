#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include <iostream>
#include <string>

class HybridVehicle {
private:
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int trips[10];
    int tripCount;

public:
    // Constructor
    HybridVehicle(const std::string& model = "",
                  float eKm = 0.0,
                  float gKm = 0.0,
                  float gUsed = 0.0);

    // Operator overloads
    HybridVehicle operator+(const HybridVehicle& other) const; // combine usage
    bool operator==(const HybridVehicle& other) const;         // compare efficiency
    HybridVehicle& operator=(const HybridVehicle& other);      // deep copy
    HybridVehicle& operator++();                               // prefix ++ adds dummy trip
    int& operator[](int index);                                // trip access
    const int& operator[](int index) const;
    float operator()() const;                                  // total distance
    operator float() const;                                    // efficiency (km/L)

    friend std::ostream& operator<<(std::ostream& os, const HybridVehicle& v);
};

#endif
