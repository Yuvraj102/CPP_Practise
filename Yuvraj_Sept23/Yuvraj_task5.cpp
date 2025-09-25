/*
(Bucket Sort) A bucket sort begins with a one-dimensional array of positive integers to be sorted and a two-dimensional array of integers with rows subscripted from 0 to 9 and columns sub- scripted from 0 to n – 1, where n is the number of values in the array to be sorted. Each row of the two-dimensional array is referred to as a bucket. Write a function bucketSort that takes an integer array and the array size as arguments and performs as follows:
a) Place each value of the one-dimensional array into a row of the bucket array based on the value’s ones digit. For example, 97 is placed in row 7, 3 is placed in row 3 and 100 is placed in row 0. This is called a “distribution pass.”
b) Loopthroughthebucketarrayrowbyrow,andcopythevaluesbacktotheoriginalar- ray. This is called a “gathering pass.” The new order of the preceding values in the one- dimensional array is 100, 3 and 97.
c) Repeat this process for each subsequent digit position (tens, hundreds, thousands, etc.).
On the second pass, 100 is placed in row 0, 3 is placed in row 0 (because 3 has no tens digit) and 97 is placed in row 9. After the gathering pass, the order of the values in the one-dimensional array is 100, 3 and 97. On the third pass, 100 is placed in row 1, 3 is placed in row zero and 97 is placed in row zero (after the 3). After the last gathering pass, the original array is now in sorted order.
Note that the two-dimensional array of buckets is 10 times the size of the integer array being sorted. This sorting technique provides better performance than an insertion sort, but requires much more memory. The insertion sort requires space for only one additional element of data. This is an example of the space-time trade-off: The bucket sort uses more memory than the inser- tion sort, but performs better. This version of the bucket sort requires copying all the data back to the original array on each pass. Another possibility is to create a second two-dimensional bucket array and repeatedly swap the data between the two bucket arrays.
*/

#include <iostream>
#include <vector>
#include <cmath>

void bucketSort(int arr[], int n) {
    // 2D bucket array: 10 rows, n columns
    std::vector<std::vector<int>> buckets(10, std::vector<int>(n, -1));

    // find the maximum element to know the number of digits
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    int maxDigits = 0;
    while (maxVal > 0) {
        maxDigits++;
        maxVal /= 10;
    }

    int divisor = 1; // controls which digit we are on (ones, tens, hundreds...)

    for (int pass = 0; pass < maxDigits; pass++) {
        // clear buckets
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < n; j++) {
                buckets[i][j] = -1;
            }
        }

        // distribution pass
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / divisor) % 10;
            for (int j = 0; j < n; j++) {
                if (buckets[digit][j] == -1) {
                    buckets[digit][j] = arr[i];
                    break;
                }
            }
        }

        // gathering pass
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < n; j++) {
                if (buckets[i][j] != -1) {
                    arr[index++] = buckets[i][j];
                }
            }
        }

        divisor *= 10; // move to next digit
    }
}

// test program
int main() {
    int arr[] = {97, 3, 100, 45, 12, 88, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    bucketSort(arr, n);

    std::cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}
