#include <iostream>
using namespace std;

int main() {
    int A[5] = {1, 2, 3, 4, 5};  // Static Array with fixed size

    // Accessing elements
    cout << "Static Array: ";
    for (int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;  // No need to deallocate, memory is automatically managed
}
