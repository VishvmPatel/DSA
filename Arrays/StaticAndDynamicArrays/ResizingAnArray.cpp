#include <iostream>
using namespace std;

int main() {
    int *p, *q;
    int i;

    // Allocating memory dynamically for 5 elements
    p = new int[5]{3, 5, 7, 9, 11};  

    // Allocating a larger array of size 10
    q = new int[10];

    // Copying old array values into the new array
    for (i = 0; i < 5; i++)
        q[i] = p[i];

    // Deallocating memory occupied by the old array
    delete[] p;

    // Pointing p to the new array
    p = q;
    q = NULL;  // Making q NULL to avoid dangling pointer issues

    // Printing the first 5 elements of the new array
    for (i = 0; i < 5; i++)
        cout << p[i] << " ";

    // Freeing memory after use
    delete[] p;

    return 0;
}
