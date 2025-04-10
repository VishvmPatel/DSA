#include <iostream>
using namespace std;

// Define a structure (or a class) for managing the array
struct Array {
    int A[10];   // Static array with a fixed maximum size of 10
    int size;    // Total capacity of the array
    int length;  // Current number of elements in the array
};

// Function to display the contents of the array
void Display(const Array& arr) {
    cout << "\nElements are: ";
    for (int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

// Function to delete an element at a given index
int Delete(Array* arr, int index) {
    int x = 0;

    // Check if the index is valid
    if (index >= 0 && index < arr->length) {
        x = arr->A[index];  // Store the element to be deleted

        // Shift all elements after the index to the left
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--;  // Reduce the array length
        return x;       // Return the deleted value
    }

    // If index is invalid
    return 0;
}

int main() {
    // Initialize an array with 5 elements and capacity of 10
    Array arr1 = {{2, 3, 4, 5, 6}, 10, 5};

    // Delete element at index 0 and print the deleted value
    cout << "Deleted value: " << Delete(&arr1, 0) << endl;

    // Display the array after deletion
    Display(arr1);

    return 0;
}
