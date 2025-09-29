#include <iostream>
#include "Yuvraj_Sept26_task3_HugheInt.h"
using namespace std;

int main() {
    HugeInt n1(123456789);
    HugeInt n2("987654321");
    HugeInt n3;

    cout << "n1 = " << n1 << "\n";
    cout << "n2 = " << n2 << "\n";

    n3 = n1 + n2;
    cout << "n1 + n2 = " << n3 << "\n";

    n3 = n2 - n1;
    cout << "n2 - n1 = " << n3 << "\n";

    n3 = n1 * n2;
    cout << "n1 * n2 = " << n3 << "\n";

    n3 = n2 / n1;
    cout << "n2 / n1 = " << n3 << "\n";

    cout << "n1 == n2 ? " << (n1 == n2) << "\n";
    cout << "n1 < n2 ? " << (n1 < n2) << "\n";
    cout << "n1 > n2 ? " << (n1 > n2) << "\n";

    return 0;
}
