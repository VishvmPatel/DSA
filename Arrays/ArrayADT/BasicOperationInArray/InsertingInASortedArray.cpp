#include <iostream>
using namespace std;

// Function to insert x into a sorted array of size n
void insertSorted(int arr[], int& n, int x, int capacity) {
    if (n >= capacity) {
        cout << "Array is full, cannot insert." << endl;
        return;
    }

    int i = n - 1;

    // Shift elements right until the correct position is found
    while (i >= 0 && arr[i] > x) {
        arr[i + 1] = arr[i];
        i--;
    }

    // Insert the element at the correct position
    arr[i + 1] = x;
    n++; // Increase size of array
}

// Function to display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[10] = {1, 3, 5, 7, 9};  // Sorted array
    int n = 5;                      // Current number of elements
    int capacity = 10;              // Total capacity of array
    int x = 6;                      // Element to insert

    cout << "Before insertion: ";
    display(arr, n);

    insertSorted(arr, n, x, capacity);

    cout << "After insertion: ";
    display(arr, n);

    return 0;
}
