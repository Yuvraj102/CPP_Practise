// HugeInt.h
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>

class HugeInt {
    friend std::ostream &operator<<(std::ostream &, const HugeInt &);

public:
    static const int digits = 30; // maximum digits in a HugeInt

    HugeInt(long = 0);              // conversion/default constructor
    HugeInt(const std::string &);   // conversion constructor

    // addition operators
    HugeInt operator+(const HugeInt &) const;
    HugeInt operator+(int) const;
    HugeInt operator+(const std::string &) const;

    // subtraction
    HugeInt operator-(const HugeInt &) const;

    // multiplication
    HugeInt operator*(const HugeInt &) const;

    // division
    HugeInt operator/(const HugeInt &) const;

    // relational operators
    bool operator==(const HugeInt &) const;
    bool operator!=(const HugeInt &) const;
    bool operator<(const HugeInt &) const;
    bool operator<=(const HugeInt &) const;
    bool operator>(const HugeInt &) const;
    bool operator>=(const HugeInt &) const;

private:
    short integer[digits];
};

#endif
