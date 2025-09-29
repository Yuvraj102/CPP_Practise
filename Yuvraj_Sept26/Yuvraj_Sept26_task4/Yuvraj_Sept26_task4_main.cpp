#include <iostream>
#include "Yuvraj_Sept26_task4_RationalNumber.h"

int main() {
    RationalNumber r1(2, 4);   // should simplify to 1/2
    RationalNumber r2(3, 9);   // should simplify to 1/3

    std::cout << "r1 = " << r1 << "\n";
    std::cout << "r2 = " << r2 << "\n";

    std::cout << "r1 + r2 = " << (r1 + r2) << "\n";
    std::cout << "r1 - r2 = " << (r1 - r2) << "\n";
    std::cout << "r1 * r2 = " << (r1 * r2) << "\n";
    std::cout << "r1 / r2 = " << (r1 / r2) << "\n";

    std::cout << std::boolalpha;
    std::cout << "r1 == r2 ? " << (r1 == r2) << "\n";
    std::cout << "r1 != r2 ? " << (r1 != r2) << "\n";
    std::cout << "r1 < r2 ? " << (r1 < r2) << "\n";
    std::cout << "r1 > r2 ? " << (r1 > r2) << "\n";

    return 0;
}
