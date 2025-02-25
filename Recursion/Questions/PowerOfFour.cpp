#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false; // Power of four must be positive
        }
        while (n % 4 == 0) { // Keep dividing by 4 if divisible
            n /= 4;
        }
        return n == 1; // If we reach 1, it's a power of 4
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << boolalpha;  // Print true/false instead of 1/0
    cout << "isPowerOfFour(16): " << sol.isPowerOfFour(16) << endl;  // true (4^2)
    cout << "isPowerOfFour(64): " << sol.isPowerOfFour(64) << endl;  // true (4^3)
    cout << "isPowerOfFour(1): " << sol.isPowerOfFour(1) << endl;    // true (4^0)
    cout << "isPowerOfFour(5): " << sol.isPowerOfFour(5) << endl;    // false (not a power of 4)
    cout << "isPowerOfFour(0): " << sol.isPowerOfFour(0) << endl;    // false
    cout << "isPowerOfFour(20): " << sol.isPowerOfFour(20) << endl;  // false
    cout << "isPowerOfFour(-16): " << sol.isPowerOfFour(-16) << endl; // false (negative numbers)

    return 0;
}
