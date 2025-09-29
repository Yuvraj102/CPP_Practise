// HugeInt.cpp
#include <cctype>
#include "Yuvraj_Sept26_task3_HugheInt.h"

// default / conversion constructor (long → HugeInt)
HugeInt::HugeInt(long value) {
    for (int i = 0; i < digits; i++)
        integer[i] = 0;

    for (int j = digits - 1; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
}

// conversion constructor (string → HugeInt)
HugeInt::HugeInt(const std::string &number) {
    for (int i = 0; i < digits; i++)
        integer[i] = 0;

    int length = number.size();
    for (int j = digits - length, k = 0; j < digits; j++, k++) {
        if (isdigit(number[k]))
            integer[j] = number[k] - '0';
    }
}

// addition operator (HugeInt + HugeInt)
HugeInt HugeInt::operator+(const HugeInt &op2) const {
    HugeInt temp;
    int carry = 0;

    for (int i = digits - 1; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    return temp;
}

// addition operator (HugeInt + int)
HugeInt HugeInt::operator+(int op2) const {
    return *this + HugeInt(op2);
}

// addition operator (HugeInt + string)
HugeInt HugeInt::operator+(const std::string &op2) const {
    return *this + HugeInt(op2);
}

// subtraction (HugeInt - HugeInt) [assumes *this >= op2]
HugeInt HugeInt::operator-(const HugeInt &op2) const {
    HugeInt temp;
    int borrow = 0;

    for (int i = digits - 1; i >= 0; i--) {
        int diff = integer[i] - op2.integer[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        temp.integer[i] = diff;
    }
    return temp;
}

// multiplication (HugeInt * HugeInt)
HugeInt HugeInt::operator*(const HugeInt &op2) const {
    HugeInt result;

    for (int i = digits - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = digits - 1, k = digits - 1 - (digits - 1 - i);
             j >= 0 && k >= 0; j--, k--) {
            int product = integer[i] * op2.integer[j] + result.integer[k] + carry;
            result.integer[k] = product % 10;
            carry = product / 10;
        }
    }
    return result;
}

// division (HugeInt / HugeInt) – simple long division
HugeInt HugeInt::operator/(const HugeInt &divisor) const {
    HugeInt quotient(0);
    HugeInt remainder(0);

    for (int i = 0; i < digits; i++) {
        // shift remainder left and add next digit
        for (int j = 0; j < digits - 1; j++)
            remainder.integer[j] = remainder.integer[j + 1];
        remainder.integer[digits - 1] = integer[i];

        int count = 0;
        while (!(remainder < divisor)) {
            remainder = remainder - divisor;
            count++;
        }
        quotient.integer[i] = count;
    }

    return quotient;
}

// relational operators
bool HugeInt::operator==(const HugeInt &rhs) const {
    for (int i = 0; i < digits; i++)
        if (integer[i] != rhs.integer[i]) return false;
    return true;
}

bool HugeInt::operator!=(const HugeInt &rhs) const { return !(*this == rhs); }

bool HugeInt::operator<(const HugeInt &rhs) const {
    for (int i = 0; i < digits; i++) {
        if (integer[i] < rhs.integer[i]) return true;
        if (integer[i] > rhs.integer[i]) return false;
    }
    return false;
}

bool HugeInt::operator<=(const HugeInt &rhs) const {
    return (*this < rhs) || (*this == rhs);
}

bool HugeInt::operator>(const HugeInt &rhs) const {
    return !(*this <= rhs);
}

bool HugeInt::operator>=(const HugeInt &rhs) const {
    return !(*this < rhs);
}

// output operator
std::ostream &operator<<(std::ostream &output, const HugeInt &num) {
    int i;
    for (i = 0; (num.integer[i] == 0) && (i < HugeInt::digits - 1); i++)
        ; // skip leading zeros

    for (; i < HugeInt::digits; i++)
        output << num.integer[i];

    return output;
}
