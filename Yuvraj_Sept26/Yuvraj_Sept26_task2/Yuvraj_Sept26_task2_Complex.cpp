#include "Yuvraj_Sept26_task2_Complex.h"

// constructor
Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart), imaginary(imaginaryPart) {}

// addition
Complex Complex::operator+(const Complex& operand2) const {
    return Complex(real + operand2.real,
                   imaginary + operand2.imaginary);
}

// subtraction
Complex Complex::operator-(const Complex& operand2) const {
    return Complex(real - operand2.real,
                   imaginary - operand2.imaginary);
}

// multiplication (a+bi)(c+di) = (ac − bd) + (ad + bc)i
Complex Complex::operator*(const Complex& operand2) const {
    double r = (real * operand2.real) - (imaginary * operand2.imaginary);
    double i = (real * operand2.imaginary) + (imaginary * operand2.real);
    return Complex(r, i);
}

// comparison ==
bool Complex::operator==(const Complex& rhs) const {
    return (real == rhs.real && imaginary == rhs.imaginary);
}

// comparison !=
bool Complex::operator!=(const Complex& rhs) const {
    return !(*this == rhs);
}

// output
std::ostream& operator<<(std::ostream& output, const Complex& c) {
    output << "(" << c.real << ", " << c.imaginary << ")";
    return output;
}

// input
std::istream& operator>>(std::istream& input, Complex& c) {
    input >> c.real >> c.imaginary;
    return input;
}
