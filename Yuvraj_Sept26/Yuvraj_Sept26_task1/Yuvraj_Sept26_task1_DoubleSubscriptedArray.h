#ifndef DOUBLE_SUBSCRIPTED_ARRAY_H
#define DOUBLE_SUBSCRIPTED_ARRAY_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

class DoubleSubscriptedArray {
public:
    // constructor
    DoubleSubscriptedArray(int rows = 1, int cols = 1);

    // copy constructor
    DoubleSubscriptedArray(const DoubleSubscriptedArray& other);

    // destructor
    ~DoubleSubscriptedArray();

    // assignment operator
    const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray& rhs);

    // comparison operators
    bool operator==(const DoubleSubscriptedArray& rhs) const;
    bool operator!=(const DoubleSubscriptedArray& rhs) const {
        return !(*this == rhs);
    }

    // operator() for element access
    int& operator()(int row, int col);
    const int& operator()(int row, int col) const;

    // get dimensions
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // input/output operators
    friend std::istream& operator>>(std::istream& input, DoubleSubscriptedArray& a);
    friend std::ostream& operator<<(std::ostream& output, const DoubleSubscriptedArray& a);

private:
    int rows;
    int cols;
    int* data; // single 1D array storing rows*cols elements

    int index(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            std::cerr << "Error: Subscript (" << row << ", " << col << ") out of range\n";
            std::exit(1);
        }
        return row * cols + col;
    }
};

#endif
