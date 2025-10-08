#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D {
private:
    double x, y, z;

public:
    // Constructor
    Vector3D(double x = 0, double y = 0, double z = 0);

    // Overloaded operators
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(double scalar) const; // scalar multiplication
    bool operator==(const Vector3D& other) const;
    bool operator!=(const Vector3D& other) const;

    // Dot product
    double dot(const Vector3D& other) const;

    // Friend functions for input/output
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v);
    friend std::istream& operator>>(std::istream& is, Vector3D& v);
};

#endif
