#include <iostream>
using namespace std;

// Swap two integers by reference
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Linear search with move-to-front
int LinearSearch(int arr[], int length, int key) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == key) {
            swap(arr[i], arr[0]);  // Move to front for faster future access
            return i;
        }
    }
    return -1;
}

int main() {
    int A[] = {2, 23, 14, 5, 6, 9, 8, 12};
    int length = sizeof(A) / sizeof(A[0]);
    int key = 14;

    int index = LinearSearch(A, length, key);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
        cout << "Array after Move-to-Front: ";
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
