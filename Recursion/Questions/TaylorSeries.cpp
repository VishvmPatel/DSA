#include <bits/stdc++.h>
using namespace std;

//TAYLOR SERIES
class Solution {
public:
    double e(int x, int n) {
        static double p = 1, f = 1;
        double r;
        if (n == 0) {
            return 1;
        }
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + (p / f);
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << fixed << setprecision(10); // Format output for precision
    cout << "e(4, 15): " << sol.e(4, 15) << endl;
    cout << "e(2, 10): " << sol.e(2, 10) << endl;
    cout << "e(5, 20): " << sol.e(5, 20) << endl;
    cout << "e(1, 5): " << sol.e(1, 5) << endl;
    cout << "e(3, 8): " << sol.e(3, 8) << endl;

    return 0;
}
