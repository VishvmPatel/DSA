#include <iostream>
using namespace std;

//RECURSION

int factorial(int n) {
    if (n == 0)  // Base Case
        return 1;
    return n * factorial(n - 1);  // Recursive Case
}

int main() {
    cout << "Factorial of 5: " << factorial(5);
    return 0;
}
