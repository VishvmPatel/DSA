#include <vector>
#include <iostream>
using namespace std;

void countDuplicates(const vector<int>& A) {
    int n = A.size();
    if (n == 0) return;

    int i = 0;
    while (i < n) {
        int current = A[i];
        int j = i + 1;
        while (j < n && A[j] == current) {
            j++;
        }
        if (j - i > 1) {
            cout << "Element " << current << " appears " << j - i << " times." << endl;
        }
        i = j;
    }
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 3, 4, 5, 5, 5, 5};
    countDuplicates(nums);
    return 0;
}