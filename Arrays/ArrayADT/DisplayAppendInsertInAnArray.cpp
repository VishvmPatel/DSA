#include <iostream>
using namespace std;

// Define a structure (or a class) for the Array
struct Array {
    int A[10];      // Fixed-size array with a maximum size of 10
    int size;       // Total capacity of the array
    int length;     // Current number of elements in the array
};

// Function to display the contents of the array
void Display(const Array& arr) {
    cout << "\nElements are: ";
    for (int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

// Function to append an element at the end of the array
void Append(Array* arr, int x) {
    // Only append if there is space
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;  // Place x at the end and increase length
    } else {
        cout << "Array is full. Cannot append!" << endl;
    }
}

// Function to insert an element at a specific index
void Insert(Array* arr, int index, int x) {
    // Make sure index is valid and there's room in the array
    if (index >= 0 && index <= arr->length && arr->length < arr->size) {
        // Shift elements to the right
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        // Insert the new value
        arr->A[index] = x;
        arr->length++;  // Update length
    } else {
        cout << "Invalid index or array full. Cannot insert!" << endl;
    }
}

int main() {
    // Initialize the array with 5 elements, size is 10
    Array arr1 = {{2, 3, 4, 5, 6}, 10, 5};

    Append(&arr1, 10);       // Append 10 at the end
    Insert(&arr1, 0, 12);    // Insert 12 at index 0
    Display(arr1);           // Display the result

    return 0;
}
