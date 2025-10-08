#include "Yuvraj_Oct1_task4_Matrix.h"
#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    Matrix m1(r, c), m2(r, c);

    cout << "Enter elements for Matrix 1:" << endl;
    cin >> m1;
    cout << "Enter elements for Matrix 2:" << endl;
    cin >> m2;

    cout << "\nMatrix 1:\n" << m1;
    cout << "Matrix 2:\n" << m2;

    cout << "\nMatrix 1 + Matrix 2:\n" << (m1 + m2);
    cout << "Matrix 1 - Matrix 2:\n" << (m1 - m2);
    cout << "Matrix 1 * Matrix 2:\n" << (m1 * m2);

    cout << "\nAre matrices equal? " << (m1 == m2 ? "Yes" : "No") << endl;
    cout << "Are matrices not equal? " << (m1 != m2 ? "Yes" : "No") << endl;

    return 0;
}
