#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int> > data;

public:
    // Constructor
    Matrix(int r = 2, int c = 2);

    // Input/Output
    friend std::istream& operator>>(std::istream& is, Matrix& m);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    // Operator Overloads
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
};

#endif
