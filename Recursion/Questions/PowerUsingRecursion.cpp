#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            if (n == INT_MIN) {  
                return 1 / (myPow(x, INT_MAX) * x);
            }
            return 1 / myPow(x, -n);
        }
        double half = myPow(x, n / 2);
        if (n % 2 == 0){
            return half * half;
        }
        else{
            return half * half * x;
        } 
    }
};

int main() {
    Solution sol;
    
    // Test cases
    cout << "myPow(2, 10) = " << sol.myPow(2, 10) << endl;  // Expected: 1024
    cout << "myPow(2, -3) = " << sol.myPow(2, -3) << endl;  // Expected: 0.125
    cout << "myPow(2, 0) = " << sol.myPow(2, 0) << endl;    // Expected: 1
    cout << "myPow(2, -2147483648) = " << sol.myPow(2, INT_MIN) << endl;  // Edge case

    return 0;
}
