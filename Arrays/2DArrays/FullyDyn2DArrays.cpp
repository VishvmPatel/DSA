#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 4;

    // Allocating memory for row pointers
    int** C = new int*[rows];

    // Allocating memory for each row
    for (int i = 0; i < rows; i++) {
        C[i] = new int[cols];
    }

    // Assigning values dynamically
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = (i + 1) + (j + 1);  // Example values
        }
    }

    // Printing the fully dynamic 2D array
    cout << "Fully Dynamic 2D Array C:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}
