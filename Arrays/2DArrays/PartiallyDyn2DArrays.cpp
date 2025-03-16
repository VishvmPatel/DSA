#include <iostream>
using namespace std;

int main() {
    // Creating an array of integer pointers (rows allocated dynamically)
    int* B[3];
    
    for (int i = 0; i < 3; i++) {
        B[i] = new int[4];  // Allocating columns dynamically
    }

    // Assigning values to the dynamically allocated array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            B[i][j] = (i + 1) * (j + 1);  // Example values
        }
    }

    // Printing the partially dynamic 2D array
    cout << "Partially Dynamic 2D Array B:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < 3; i++) {
        delete[] B[i];
    }

    return 0;
}
