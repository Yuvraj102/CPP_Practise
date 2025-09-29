#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial {
private:
    std::vector<int> coeffs; // coeffs[i] = coefficient of x^i

    void trim() {
        // remove trailing zeros (highest powers with 0 coeff)
        while (!coeffs.empty() && coeffs.back() == 0)
            coeffs.pop_back();
    }

public:
    // Constructors
    Polynomial(int degree = 0) : coeffs(degree + 1, 0) {}
    Polynomial(const std::vector<int>& c) : coeffs(c) { trim(); }

    // Set coefficient
    void setCoefficient(int exponent, int coefficient) {
        if (exponent >= (int)coeffs.size())
            coeffs.resize(exponent + 1, 0);
        coeffs[exponent] = coefficient;
        trim();
    }

    // Get coefficient
    int getCoefficient(int exponent) const {
        if (exponent < 0 || exponent >= (int)coeffs.size())
            return 0;
        return coeffs[exponent];
    }

    // Degree of polynomial
    int degree() const {
        return coeffs.empty() ? -1 : (int)coeffs.size() - 1;
    }

    // Operator overloads
    Polynomial operator+(const Polynomial& rhs) const {
        Polynomial result;
        int maxDeg = std::max(degree(), rhs.degree());
        result.coeffs.resize(maxDeg + 1, 0);
        for (int i = 0; i <= maxDeg; i++)
            result.coeffs[i] = getCoefficient(i) + rhs.getCoefficient(i);
        result.trim();
        return result;
    }

    Polynomial operator-(const Polynomial& rhs) const {
        Polynomial result;
        int maxDeg = std::max(degree(), rhs.degree());
        result.coeffs.resize(maxDeg + 1, 0);
        for (int i = 0; i <= maxDeg; i++)
            result.coeffs[i] = getCoefficient(i) - rhs.getCoefficient(i);
        result.trim();
        return result;
    }

    Polynomial operator*(const Polynomial& rhs) const {
        Polynomial result(degree() + rhs.degree());
        for (int i = 0; i <= degree(); i++) {
            for (int j = 0; j <= rhs.degree(); j++) {
                result.coeffs[i + j] += getCoefficient(i) * rhs.getCoefficient(j);
            }
        }
        result.trim();
        return result;
    }

    // Assignment operators
    Polynomial& operator=(const Polynomial& rhs) {
        if (this != &rhs) {
            coeffs = rhs.coeffs;
        }
        return *this;
    }

    Polynomial& operator+=(const Polynomial& rhs) {
        *this = *this + rhs;
        return *this;
    }

    Polynomial& operator-=(const Polynomial& rhs) {
        *this = *this - rhs;
        return *this;
    }

    Polynomial& operator*=(const Polynomial& rhs) {
        *this = *this * rhs;
        return *this;
    }

    // Print polynomial
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        if (poly.coeffs.empty()) {
            os << "0";
            return os;
        }
        bool first = true;
        for (int i = poly.degree(); i >= 0; --i) {
            int c = poly.coeffs[i];
            if (c == 0) continue;
            if (!first && c > 0) os << " + ";
            if (c < 0) os << " - ";
            if (std::abs(c) != 1 || i == 0)
                os << std::abs(c);
            if (i > 0) {
                os << "x";
                if (i > 1) os << "^" << i;
            }
            first = false;
        }
        return os;
    }
};

#endif
