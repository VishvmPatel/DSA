#include <iostream>
using namespace std;

int sumN(int n) {
    if (n == 0) return 0;  // Base case
    return n + sumN(n - 1);  // Only one recursive call
}

int main() {
    int n = 5;
    cout << "Sum of first " << n << " natural numbers: " << sumN(n);
    return 0;
}
