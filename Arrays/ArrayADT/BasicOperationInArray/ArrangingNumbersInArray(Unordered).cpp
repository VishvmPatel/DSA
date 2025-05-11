#include <iostream>
using namespace std;

// Function to rearrange array: -ve numbers on left, +ve/right on right
void rearrangeNegatives(int arr[], int n) {
    int i = 0, j = n - 1;

    while (i <= j) {
        if (arr[i] < 0) {
            i++;  // Already on left, move ahead
        } else if (arr[j] >= 0) {
            j--;  // Already on right, move back
        } else {
            // Swap positive on left with negative on right
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {2, -3, 4, -1, 6, -5, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    rearrangeNegatives(arr, n);

    cout << "Rearranged array (negatives left): ";
    display(arr, n);

    return 0;
}
