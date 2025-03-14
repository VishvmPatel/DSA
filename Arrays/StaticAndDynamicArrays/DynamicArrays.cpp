#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* A = new int[n];  // Dynamic Array allocated on heap

    // Assigning values
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;  // Assigning values 1, 2, 3, ...
    }

    // Printing elements
    cout << "Dynamic Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[] A;  // Deallocate memory to prevent memory leak

    return 0;
}
