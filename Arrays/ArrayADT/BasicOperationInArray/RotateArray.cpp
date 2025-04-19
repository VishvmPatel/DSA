#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ✅ Method 1: Using Extra Array
    void rotateWithExtraArray(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        vector<int> temp(n);

        // Copy last k elements to front
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Copy first n - k elements after that
        for (int i = k; i < n; i++) {
            temp[i] = nums[i - k];
        }

        // Assign temp to original array
        nums = temp;
    }

    // ✅ Method 2: In-place Reverse Method (O(1) space)
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }
    }

    void rotateInPlace(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        // Reverse entire array
        reverse(nums, 0, n - 1);

        // Reverse first k elements
        reverse(nums, 0, k - 1);

        // Reverse the rest
        reverse(nums, k, n - 1);
    }

    // ✅ Helper to print array
    void printArray(const vector<int>& nums) {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums2 = nums1; // Copy for second method

    int k = 3;

    cout << "Original array: ";
    sol.printArray(nums1);

    // Method 1: Extra array
    sol.rotateWithExtraArray(nums1, k);
    cout << "Rotated using extra array: ";
    sol.printArray(nums1);

    // Method 2: In-place reverse
    sol.rotateInPlace(nums2, k);
    cout << "Rotated using in-place reverse: ";
    sol.printArray(nums2);

    return 0;
}
