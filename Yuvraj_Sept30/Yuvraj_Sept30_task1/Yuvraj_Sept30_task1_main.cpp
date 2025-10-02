#include <iostream>
#include <iomanip>

int main() {
    const int SIZE = 5;

    // (a) Declare and initialize array
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    // (b) Declare pointer
    unsigned int* vPtr;

    // (c) Print using array subscript notation
    std::cout << "(c) values using array subscript notation:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << "\n\n";

    // (d) Assign address of values to vPtr (two ways)
    vPtr = values;       // array name is address of first element
    vPtr = &values[0];   // explicitly address of first element

    // (e) Print using pointer/offset notation with vPtr
    std::cout << "(e) values using pointer/offset notation with vPtr:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(vPtr + i) << " ";
    }
    std::cout << "\n\n";

    // (f) Print using pointer/offset notation with array name
    std::cout << "(f) values using pointer/offset notation with array name:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *(values + i) << " ";
    }
    std::cout << "\n\n";

    // (g) Print using pointer subscript notation
    std::cout << "(g) values using pointer subscript notation:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << vPtr[i] << " ";
    }
    std::cout << "\n\n";

    // (h) Refer to the fifth element
    std::cout << "(h) Fifth element of values in 4 ways:\n";
    std::cout << "Array subscript: " << values[4] << "\n";
    std::cout << "Pointer/offset with array name: " << *(values + 4) << "\n";
    std::cout << "Pointer subscript: " << vPtr[4] << "\n";
    std::cout << "Pointer/offset with vPtr: " << *(vPtr + 4) << "\n\n";

    // (i) Address and value at vPtr + 3
    std::cout << "(i) Address referenced by vPtr + 3: " << (vPtr + 3)
              << " | Value: " << *(vPtr + 3) << "\n\n";

    // (j) Move vPtr to values[4], then vPtr -= 4
    vPtr = &values[4];
    vPtr -= 4; // now should point to values[0]
    std::cout << "(j) After vPtr points to values[4] and vPtr -= 4:\n";
    std::cout << "Address: " << vPtr << " | Value: " << *vPtr << "\n";

    return 0;
}
