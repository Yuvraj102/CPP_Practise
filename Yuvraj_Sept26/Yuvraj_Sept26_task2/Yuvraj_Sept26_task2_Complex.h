#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    // constructor
    Complex(double = 0.0, double = 0.0);

    // arithmetic operators
    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;

    // comparison operators
    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;

    // friend I/O operators
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);

private:
    double real;
    double imaginary;
};

#endif
