#include <iostream>
using namespace std;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[left] <= pivot)
            left++;

        while (left <= right && arr[right] >= pivot)
            right--;

        if (left > right)
            break;

        swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]);
    return right;
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Print function
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
