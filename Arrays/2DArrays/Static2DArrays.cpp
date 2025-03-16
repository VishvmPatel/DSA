#include <iostream>
using namespace std;

int main() {
    // 📌 Declaration & Initialization of a Static 2D Array
    int A[3][4] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12} 
    };

    // 📌 Accessing and Printing the Static 2D Array
    cout << "Static 2D Array A:" << endl;
    for (int i = 0; i < 3; i++) {       // Loop through rows
        for (int j = 0; j < 4; j++) {   // Loop through columns
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
