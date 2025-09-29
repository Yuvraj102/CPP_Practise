#include <iostream>
#include "Yuvraj_Sept26_task5_Polynomial.h"

int main() {
    Polynomial p1;
    p1.setCoefficient(2, 3);  // 3x^2
    p1.setCoefficient(1, 2);  // + 2x
    p1.setCoefficient(0, 1);  // + 1

    Polynomial p2;
    p2.setCoefficient(1, 4);  // 4x
    p2.setCoefficient(0, -2); // -2

    std::cout << "P1(x) = " << p1 << std::endl;
    std::cout << "P2(x) = " << p2 << std::endl;

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    std::cout << "P1(x) + P2(x) = " << sum << std::endl;
    std::cout << "P1(x) - P2(x) = " << diff << std::endl;
    std::cout << "P1(x) * P2(x) = " << prod << std::endl;

    p1 += p2;
    std::cout << "After P1 += P2, P1(x) = " << p1 << std::endl;

    return 0;
}
