#include "Yuvraj_Oct1_task3_Vector3D.h"
#include <iostream>
using namespace std;

int main() {
    Vector3D v1, v2;
    cout << "Enter vector v1:" << endl;
    cin >> v1;
    cout << "Enter vector v2:" << endl;
    cin >> v2;

    cout << "\nv1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "\nv1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * 2 = " << (v1 * 2) << endl;
    cout << "Dot product (v1 · v2) = " << v1.dot(v2) << endl;

    cout << "\nv1 == v2? " << (v1 == v2 ? "Yes" : "No") << endl;
    cout << "v1 != v2? " << (v1 != v2 ? "Yes" : "No") << endl;

    return 0;
}
