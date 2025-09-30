#include <iostream>
#include <iomanip>

#define SIZE 10

int main() {
    // (a) Declare and initialize array
    double numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4,
                            5.5, 6.6, 7.7, 8.8, 9.9};

    // (b) Declare a pointer to double
    double* nPtr = nullptr;

    // (c) Print elements using array subscript notation
    std::cout << "(c) Array subscript notation:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << std::fixed << std::setprecision(1) << numbers[i] << " ";
    }
    std::cout << "\n\n";

    // (d) Assign starting address of numbers to nPtr
    nPtr = numbers;        // way 1
    nPtr = &numbers[0];    // way 2

    // (e) Print using pointer/offset notation with nPtr
    std::cout << "(e) Pointer/offset notation with nPtr:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << std::fixed << std::setprecision(1) << *(nPtr + i) << " ";
    }
    std::cout << "\n\n";

    // (f) Print using pointer/offset notation with array name
    std::cout << "(f) Pointer/offset notation with array name:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << std::fixed << std::setprecision(1) << *(numbers + i) << " ";
    }
    std::cout << "\n\n";

    // (g) Print using pointer/subscript notation with nPtr
    std::cout << "(g) Pointer/subscript notation with nPtr:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << std::fixed << std::setprecision(1) << nPtr[i] << " ";
    }
    std::cout << "\n\n";

    // (h) Reference the fourth element
    std::cout << "(h) Fourth element of numbers:\n";
    std::cout << "Array subscript notation: " << numbers[3] << "\n";
    std::cout << "Pointer/offset with array name: " << *(numbers + 3) << "\n";
    std::cout << "Pointer subscript with nPtr: " << nPtr[3] << "\n";
    std::cout << "Pointer/offset with nPtr: " << *(nPtr + 3) << "\n\n";

    // (i) Assuming nPtr points to beginning
    nPtr = numbers;  // reset pointer
    std::cout << "(i) Address referenced by nPtr + 8: " << (nPtr + 8) << "\n";
    std::cout << "Value stored there: " << *(nPtr + 8) << "\n\n";

    // (j) Assuming nPtr points to numbers[5]
    nPtr = &numbers[5];
    nPtr -= 4;  // move back 4 positions
    std::cout << "(j) Address referenced by nPtr after -= 4: " << nPtr << "\n";
    std::cout << "Value stored there: " << *nPtr << "\n";

    return 0;
}
