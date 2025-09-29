#include <iostream>
#include "Yuvraj_Sept26_task2_Complex.h"

int main() {
    Complex x;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    std::cout << "Initial values:\n";
    std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\n";

    // test input
    std::cout << "\nEnter a complex number (real and imaginary parts): ";
    std::cin >> x;
    std::cout << "You entered: " << x << "\n";

    // addition
    Complex sum = y + z;
    std::cout << "\ny + z = " << sum << " = " << y << " + " << z << "\n";

    // subtraction
    Complex diff = y - z;
    std::cout << "y - z = " << diff << " = " << y << " - " << z << "\n";

    // multiplication
    Complex prod = y * z;
    std::cout << "y * z = " << prod << " = " << y << " * " << z << "\n";

    // comparisons
    std::cout << "\nComparison tests:\n";
    if (y == z)
        std::cout << y << " and " << z << " are equal\n";
    else
        std::cout << y << " and " << z << " are not equal\n";

    if (y != z)
        std::cout << y << " and " << z << " are different\n";

    return 0;
}
