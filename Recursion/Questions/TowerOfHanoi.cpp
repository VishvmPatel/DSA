#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int steps;  // Keep steps private

  public:
    Solution() { steps = 0; } // Constructor to initialize steps

    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n > 0) {
            towerOfHanoi(n - 1, from, aux, to);
            cout << "Move from " << from << " to " << to << endl;
            steps++; // Increment step counter
            towerOfHanoi(n - 1, aux, to, from);
        }
        return steps;
    }
};

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    Solution sol;
    int totalSteps = sol.towerOfHanoi(n, 1, 3, 2);

    cout << "Total steps required: " << totalSteps << endl;
    return 0;
}
