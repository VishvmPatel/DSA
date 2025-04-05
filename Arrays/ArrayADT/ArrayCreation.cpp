#include <iostream>
using namespace std;

class Array {
private:
    int* A;     // Pointer to dynamically allocate array
    int size;   // Total size of the array (capacity)
    int length; // Actual number of elements in the array

public:
    // Constructor to initialize the size and allocate memory
    Array(int size) {
        this->size = size;
        A = new int[size]; // Allocate memory for 'size' integers
    }

    // Method to populate the array with user input
    void create() {
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements:" << endl;
        for (int i = 0; i < length; i++) {
            cout << "Array element " << i << " = " << flush;
            cin >> A[i]; // Take element input
        }
    }

    // Method to display array contents
    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    // Destructor to deallocate memory
    ~Array() {
        delete[] A; // Free the allocated memory
        cout << "Array destroyed" << endl;
    }
};

int main() {
    Array arr(10);   // Create an Array object with capacity of 10
    arr.create();    // Fill the array with elements from user
    arr.display();   // Display the elements of the array

    return 0;
}
