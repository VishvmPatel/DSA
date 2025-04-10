#include <iostream>
using namespace std;

//Function of Linear Search
int LinearSearch(int arr[], int length, int key) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == key)
            return i;  // Found the key, return index
    }
    return -1; // Not found
}

int main() {
    int A[] = {2, 23, 14, 5, 6, 9, 8, 12};
    int length = sizeof(A) / sizeof(A[0]);
    int key = 14;

    int index = LinearSearch(A, length, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
