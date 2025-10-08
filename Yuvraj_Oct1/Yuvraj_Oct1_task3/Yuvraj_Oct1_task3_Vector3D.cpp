#include "Yuvraj_Oct1_task3_Vector3D.h"

// Constructor
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

// Addition
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

// Subtraction
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

// Scalar multiplication
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

// Equality
bool Vector3D::operator==(const Vector3D& other) const {
    return x == other.x && y == other.y && z == other.z;
}

// Inequality
bool Vector3D::operator!=(const Vector3D& other) const {
    return !(*this == other);
}

// Dot product
double Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Output
std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

// Input
std::istream& operator>>(std::istream& is, Vector3D& v) {
    std::cout << "Enter x y z: ";
    is >> v.x >> v.y >> v.z;
    return is;
}
