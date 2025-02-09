#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int &y = x;  // y is a reference to x

    cout << "x: " << x << ", y: " << y << endl; // Output: x: 10, y: 10

    y = 20; // Modifying y modifies x
    cout << "x: " << x << ", y: " << y << endl; // Output: x: 20, y: 20

    return 0;
}
