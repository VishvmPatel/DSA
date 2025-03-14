#include <iostream>
using namespace std;

int main() {
    // 📌 Declaration and Initialization
    int A[5] = {2, 4, 6, 8, 10};  // Array of size 5

    // ✅ Accessing using Indexing
    cout << "Accessing using Indexing:" << endl;
    cout << "A[0] = " << A[0] << endl; // Output: 2
    cout << "A[2] = " << A[2] << endl; // Output: 6

    // ✅ Accessing using a For Loop
    cout << "\nAccessing using For Loop:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "A[" << i << "] = " << A[i] << endl;
    }

    // ✅ Accessing using a Range-Based For Loop (C++11 and later)
    cout << "\nAccessing using Range-Based For Loop:" << endl;
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    // ✅ Accessing using Pointers (Pointer Arithmetic)
    cout << "\nAccessing using Pointers:" << endl;
    int* p = A;  // Pointer to the first element
    for (int i = 0; i < 5; i++) {
        cout << "*(p + " << i << ") = " << *(p + i) << endl;
    }

    return 0;
}
