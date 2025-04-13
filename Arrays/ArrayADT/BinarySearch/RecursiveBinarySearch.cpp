#include <iostream>
using namespace std;

// Recursive Binary Search function
int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;  // Prevents overflow

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return recursiveBinarySearch(arr, low, mid - 1, key);
        else
            return recursiveBinarySearch(arr, mid + 1, high, key);
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    int result = recursiveBinarySearch(arr, 0, size - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
