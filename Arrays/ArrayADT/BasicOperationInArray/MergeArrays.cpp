#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;           // Pointer for last valid element in nums1
        int j = n - 1;           // Pointer for last element in nums2
        int k = m + n - 1;       // Pointer for placement in nums1

        // Merge from the end to avoid overwriting elements in nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If any elements left in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // No need to copy from nums1, they are already in place
    }
};

// Helper function to display the contents of the array
void display(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    // Solution
    Solution sol;
    sol.merge(nums1, m, nums2, n);

    // Output result
    cout << "Merged array: ";
    display(nums1);

    return 0;
}
