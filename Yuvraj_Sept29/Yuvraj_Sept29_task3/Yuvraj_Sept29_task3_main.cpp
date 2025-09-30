#include <iostream>

// a) Function header for exchange
void exchange(double* x, double* y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

// c) Function header for evaluate
int evaluate(int x, int (*poly)(int)) {
    return poly(x); // call the function pointer
}

// Example poly function
int square(int n) {
    return n * n;
}

int main() {
    // Demonstrate exchange
    double a = 5.5, b = 9.9;
    std::cout << "Before exchange: a = " << a << ", b = " << b << std::endl;
    exchange(&a, &b);
    std::cout << "After exchange:  a = " << a << ", b = " << b << std::endl;

    // Demonstrate evaluate with function pointer
    int value = 6;
    int result = evaluate(value, square);
    std::cout << "evaluate(" << value << ", square) = " << result << std::endl;

    // e) Initialize vowel array
    char vowel1[] = "AEIOU";
    char vowel2[6] = { 'A','E','I','O','U','\0' };

    std::cout << "vowel1 = " << vowel1 << std::endl;
    std::cout << "vowel2 = " << vowel2 << std::endl;

    return 0;
}
