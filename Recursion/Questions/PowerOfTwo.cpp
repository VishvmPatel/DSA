#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i < 31; i++) {  // Loop for 2^i (0 to 30)
            int ans = pow(2, i);
            if (ans == n) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << boolalpha;
    cout << "isPowerOfTwo(1): " << sol.isPowerOfTwo(1) << endl;      // Expected: true (2^0)
    cout << "isPowerOfTwo(2): " << sol.isPowerOfTwo(2) << endl;      // Expected: true (2^1)
    cout << "isPowerOfTwo(8): " << sol.isPowerOfTwo(8) << endl;      // Expected: true (2^3)
    cout << "isPowerOfTwo(16): " << sol.isPowerOfTwo(16) << endl;    // Expected: true (2^4)
    cout << "isPowerOfTwo(18): " << sol.isPowerOfTwo(18) << endl;    // Expected: false (not a power of 2)
    cout << "isPowerOfTwo(1024): " << sol.isPowerOfTwo(1024) << endl; // Expected: true (2^10)

    return 0;
}
