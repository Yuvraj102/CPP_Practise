#include <iostream>
#include "Yuvraj_Sept26_task1_DoubleSubscriptedArray.h"

int main() {
    DoubleSubscriptedArray a(3, 4); // 3x4 array
    DoubleSubscriptedArray b(3, 4);

    std::cout << "Enter 12 integers for array a:\n";
    std::cin >> a;

    std::cout << "Array a:\n" << a;

    std::cout << "\nAssigning a to b...\n";
    b = a;
    std::cout << "Array b:\n" << b;

    std::cout << "\nChanging a(1,2) to 99\n";
    a(1, 2) = 99;

    std::cout << "Array a:\n" << a;
    std::cout << "Array b (unchanged):\n" << b;

    std::cout << "\nComparing arrays:\n";
    if (a == b)
        std::cout << "a and b are equal\n";
    else
        std::cout << "a and b are not equal\n";

    return 0;
}
