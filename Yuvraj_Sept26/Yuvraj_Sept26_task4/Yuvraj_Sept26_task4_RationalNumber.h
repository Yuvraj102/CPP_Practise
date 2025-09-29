#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>


int gcd(int a, int b) {
    a = (a < 0 ? -a : a);
    b = (b < 0 ? -b : b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class RationalNumber {
private:
    int numerator;
    int denominator;

    void reduce() {
        if (denominator < 0) {   // keep denominator positive
            denominator = -denominator;
            numerator = -numerator;
        }
        int g = gcd(numerator, denominator);
        if (g != 0) {
            numerator /= g;
            denominator /= g;
        }
    }

public:
    // Constructor
    RationalNumber(int num = 0, int den = 1) {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        numerator = num;
        denominator = den;
        reduce();
    }

    // Getters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Arithmetic operators
    RationalNumber operator+(const RationalNumber &rhs) const {
        return RationalNumber(numerator * rhs.denominator + rhs.numerator * denominator,
                              denominator * rhs.denominator);
    }

    RationalNumber operator-(const RationalNumber &rhs) const {
        return RationalNumber(numerator * rhs.denominator - rhs.numerator * denominator,
                              denominator * rhs.denominator);
    }

    RationalNumber operator*(const RationalNumber &rhs) const {
        return RationalNumber(numerator * rhs.numerator,
                              denominator * rhs.denominator);
    }

    RationalNumber operator/(const RationalNumber &rhs) const {
        if (rhs.numerator == 0) {
            throw std::invalid_argument("Division by zero rational number");
        }
        return RationalNumber(numerator * rhs.denominator,
                              denominator * rhs.numerator);
    }

    // Relational / equality operators
    bool operator==(const RationalNumber &rhs) const {
        return numerator == rhs.numerator && denominator == rhs.denominator;
    }

    bool operator!=(const RationalNumber &rhs) const { return !(*this == rhs); }

    bool operator<(const RationalNumber &rhs) const {
        return numerator * rhs.denominator < rhs.numerator * denominator;
    }

    bool operator<=(const RationalNumber &rhs) const {
        return *this < rhs || *this == rhs;
    }

    bool operator>(const RationalNumber &rhs) const { return !(*this <= rhs); }

    bool operator>=(const RationalNumber &rhs) const { return !(*this < rhs); }

    // Output operator
    friend std::ostream &operator<<(std::ostream &out, const RationalNumber &r) {
        if (r.denominator == 1) out << r.numerator;
        else out << r.numerator << "/" << r.denominator;
        return out;
    }
};

#endif
