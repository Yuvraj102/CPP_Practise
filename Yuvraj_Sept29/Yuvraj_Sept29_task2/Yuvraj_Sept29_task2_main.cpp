#include <iostream>

int main() {
    double number1 = 7.3;   // already initialized
    double number2;         // declared
    char* ptr;              // given
    char s1[100] = "Hello"; // initialized string
    char s2[100] = "World"; // initialized string

    // (a) Declare the variable fPtr to be a pointer to an object of type double.
    double* fPtr;

    // (b) Assign the address of variable number1 to pointer variable fPtr.
    fPtr = &number1;

    // (c) Print the value of the object pointed to by fPtr.
    std::cout << *fPtr << std::endl;

    // (d) Assign the value of the object pointed to by fPtr to variable number2.
    number2 = *fPtr;

    // (e) Print the value of number2.
    std::cout << number2 << std::endl;

    // (f) Print the address of number1.
    std::cout << &number1 << std::endl;

    // (g) Print the address stored in fPtr.
    std::cout << fPtr << std::endl;  // Should match &number1

    return 0;
}
