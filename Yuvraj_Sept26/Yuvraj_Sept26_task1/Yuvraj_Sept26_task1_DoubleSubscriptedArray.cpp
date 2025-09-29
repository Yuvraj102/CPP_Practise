#include "Yuvraj_Sept26_task1_DoubleSubscriptedArray.h"

// constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c)
    : rows(r > 0 ? r : 1), cols(c > 0 ? c : 1) {
    data = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = 0;
    }
}

// copy constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& other)
    : rows(other.rows), cols(other.cols) {
    data = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
}

// destructor
DoubleSubscriptedArray::~DoubleSubscriptedArray() {
    delete[] data;
}

// assignment operator
const DoubleSubscriptedArray& DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& rhs) {
    if (this != &rhs) {
        if (rows * cols != rhs.rows * rhs.cols) {
            delete[] data;
            rows = rhs.rows;
            cols = rhs.cols;
            data = new int[rows * cols];
        }
        for (int i = 0; i < rows * cols; i++) {
            data[i] = rhs.data[i];
        }
    }
    return *this;
}

// equality
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& rhs) const {
    if (rows != rhs.rows || cols != rhs.cols) return false;
    for (int i = 0; i < rows * cols; i++) {
        if (data[i] != rhs.data[i]) return false;
    }
    return true;
}

// operator() for non-const
int& DoubleSubscriptedArray::operator()(int row, int col) {
    return data[index(row, col)];
}

// operator() for const
const int& DoubleSubscriptedArray::operator()(int row, int col) const {
    return data[index(row, col)];
}

// input
std::istream& operator>>(std::istream& input, DoubleSubscriptedArray& a) {
    for (int i = 0; i < a.rows * a.cols; i++) {
        input >> a.data[i];
    }
    return input;
}

// output
std::ostream& operator<<(std::ostream& output, const DoubleSubscriptedArray& a) {
    for (int r = 0; r < a.rows; r++) {
        for (int c = 0; c < a.cols; c++) {
            output << std::setw(5) << a(r, c);
        }
        output << '\n';
    }
    return output;
}
