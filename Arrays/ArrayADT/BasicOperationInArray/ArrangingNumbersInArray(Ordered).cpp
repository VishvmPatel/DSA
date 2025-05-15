#include <iostream>
using namespace std;

// Function to shift and insert negatives in order (stable version)
void rearrangeNegativesOrdered(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            int key = arr[i];
            int j = i - 1;
            // Shift all non-negatives to the right
            while (j >= 0 && arr[j] >= 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            // Place the negative number at the correct position
            arr[j + 1] = key;
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
    rearrangeNegativesOrdered(arr, n);
    cout << "Rearranged array (negatives left, order preserved): ";
    display(arr, n);
    return 0;
}
