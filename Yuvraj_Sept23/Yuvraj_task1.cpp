/*
(Duplicate Elimination) Use a one-dimensional array to solve the following problem. Read
in 20 numbers, each of which is between 10 and 100, inclusive. As each number is read, validate it and store it in the array only if it isn’t a duplicate of a number already read. After reading all the values, display only the unique values that the user entered. Provide for the “worst case” in which all 20 numbers are different. Use the smallest possible array to solve this problem.
*/

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 20;
    int unique[SIZE];   // array to hold unique numbers
    int count = 0;      // how many unique numbers we have

    for (int i = 0; i < SIZE; i++) {
        int num;
        cout << "Enter number " << (i + 1) << " (10–100): ";
        cin >> num;

        // validate range
        if (num < 10 || num > 100) {
            cout << "Invalid number, must be between 10 and 100." << endl;
            i--; // retry this iteration
            continue;
        }

        // check for duplicates
        bool isDuplicate = false;
        for (int j = 0; j < count; j++) {
            if (unique[j] == num) {
                isDuplicate = true;
                break;
            }
        }

        // if not duplicate, store it
        if (!isDuplicate) {
            unique[count] = num;
            count++;
        }
    }

    // display unique values
    cout << "\nUnique numbers entered:" << endl;
    for (int i = 0; i < count; i++) {
        cout << unique[i] << " ";
    }
    cout << endl;

    return 0;
}
