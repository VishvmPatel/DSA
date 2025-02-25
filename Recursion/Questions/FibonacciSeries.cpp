#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int F[31];  // Memoization array

    Solution() {
        memset(F, -1, sizeof(F)); // Initialize all values to -1
    }

    int fib(int n) {
        if (n <= 1) { // Base case
            F[n] = n;
            return n;
        }
        if (F[n] != -1) return F[n]; // If already computed, return cached result

        // Compute only if not stored previously
        F[n] = fib(n - 1) + fib(n - 2);
        return F[n];
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << "Fibonacci(0): " << sol.fib(0) << endl;  // Expected: 0
    cout << "Fibonacci(1): " << sol.fib(1) << endl;  // Expected: 1
    cout << "Fibonacci(2): " << sol.fib(2) << endl;  // Expected: 1
    cout << "Fibonacci(3): " << sol.fib(3) << endl;  // Expected: 2
    cout << "Fibonacci(4): " << sol.fib(4) << endl;  // Expected: 3
    cout << "Fibonacci(5): " << sol.fib(5) << endl;  // Expected: 5
    cout << "Fibonacci(10): " << sol.fib(10) << endl; // Expected: 55
    cout << "Fibonacci(20): " << sol.fib(20) << endl; // Expected: 6765
    cout << "Fibonacci(30): " << sol.fib(30) << endl; // Expected: 832040

    return 0;
}
