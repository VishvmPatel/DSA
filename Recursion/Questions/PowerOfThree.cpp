#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 2) {
            if (n % 3) { // If n is not divisible by 3, return false
                return false;
            }
            n /= 3; // Keep dividing by 3
        }
        return n == 1; // If we reach 1, it is a power of 3
    }
};

int main() {
    Solution sol;
    
    // Test cases
    cout << boolalpha;  // Print true/false instead of 1/0
    cout << "isPowerOfThree(27): " << sol.isPowerOfThree(27) << endl;  // true (3^3)
    cout << "isPowerOfThree(9): " << sol.isPowerOfThree(9) << endl;    // true (3^2)
    cout << "isPowerOfThree(81): " << sol.isPowerOfThree(81) << endl;  // true (3^4)
    cout << "isPowerOfThree(1): " << sol.isPowerOfThree(1) << endl;    // true (3^0)
    cout << "isPowerOfThree(0): " << sol.isPowerOfThree(0) << endl;    // false
    cout << "isPowerOfThree(10): " << sol.isPowerOfThree(10) << endl;  // false
    cout << "isPowerOfThree(-27): " << sol.isPowerOfThree(-27) << endl; // false (negative numbers)

    return 0;
}
