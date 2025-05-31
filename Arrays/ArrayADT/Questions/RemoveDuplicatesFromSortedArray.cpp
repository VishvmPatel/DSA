#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: empty array
        if (nums.empty()) {
            return 0;
        }

        // Initialize pointer for unique elements
        size_t k = 1;  // Changed to size_t to match vector size type

        // Traverse the array starting from the second element
        for (size_t i = 1; i < nums.size(); ++i) {
            // If current element is different from the previous, it's unique
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Place the unique element at position k
                ++k;               // Move the pointer forward
            }
        }

        // k now represents the number of unique elements
        return static_cast<int>(k);  // Cast back to int for compatibility
    }
};

// Helper function to print the array (for demonstration)
void printArray(const vector<int>& nums, int k) {
    cout << "Unique elements (" << k << "): [";
    for (int i = 0; i < k; ++i) {
        if (i >= 0 && i < static_cast<int>(nums.size())) {  // Safety check
            cout << nums[i];
            if (i < k - 1) {
                cout << ", ";
            }
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    printArray(nums1, k1); // Output: [1, 2]

    // Test Case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    printArray(nums2, k2); // Output: [0, 1, 2, 3, 4]

    // Test Case 3 (Edge case: single element)
    vector<int> nums3 = {5};
    int k3 = sol.removeDuplicates(nums3);
    printArray(nums3, k3); // Output: [5]

    return 0;
}