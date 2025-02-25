#include <bits/stdc++.h>

using namespace std;

double e(int x, int n) {
    static double s = 1;  // Initialize static variable to store the result
    if (n == 0)
        return s;
    s = 1 + (x * s) / n;  // Horner's Rule for Taylor Series
    return e(x, n - 1);  // Recursive call
}

int main() {
    cout << fixed << setprecision(10); // Setting precision for better accuracy

    // Test cases
    cout << "e(2, 10): " << e(2, 10) << endl;
    
    // Reset static variable for new test cases
    e(0, 0);  // Resetting function call

    cout << "e(3, 15): " << e(3, 15) << endl;
    
    e(0, 0); // Reset again for the next case

    cout << "e(4, 20): " << e(4, 20) << endl;
    
    e(0, 0); // Reset

    cout << "e(1, 5): " << e(1, 5) << endl;

    return 0;
}
