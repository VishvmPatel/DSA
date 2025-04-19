#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
using namespace std;

class Solution {
public:
    // ✅ 1. Reverse using for loop
    void reverseNestedWrong(vector<int>& arr) {
        for(int i = 0, j = arr.size()-1 ; i < j ; i++ , j--){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }    

    // ✅ 2. Reverse using for loop with two pointers (recommended)
    void reverseForLoop(vector<int>& arr) {
        for (int i = 0, j = arr.size() - 1; i < j; i++, j--) {
            swap(arr[i], arr[j]);
        }
    }

    // ✅ 3. Reverse using while loop with two pointers
    void reverseWhileLoop(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            swap(arr[i++], arr[j--]);
        }
    }

    // ✅ 4. Reverse using STL
    void reverseUsingSTL(vector<int>& arr) {
        reverse(arr.begin(), arr.end());
    }

    // ✅ 5. Reverse using a temporary array
    void reverseWithTemp(vector<int>& arr) {
        vector<int> temp(arr.rbegin(), arr.rend());
        arr = temp;
    }

    // ✅ Helper to print array
    void printArray(const vector<int>& arr) {
        for (int val : arr)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    Solution sol;
    vector<int> original = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    sol.printArray(original);

    // Test each reversal method
    vector<int> arr1 = original;
    sol.reverseForLoop(arr1);
    cout << "Reversed with for loop: ";
    sol.printArray(arr1);

    vector<int> arr2 = original;
    sol.reverseWhileLoop(arr2);
    cout << "Reversed with while loop: ";
    sol.printArray(arr2);

    vector<int> arr3 = original;
    sol.reverseUsingSTL(arr3);
    cout << "Reversed with STL: ";
    sol.printArray(arr3);

    vector<int> arr4 = original;
    sol.reverseWithTemp(arr4);
    cout << "Reversed with temporary array: ";
    sol.printArray(arr4);

    // Optional: test the flawed nested version (just to see what happens)
    vector<int> arr5 = original;
    sol.reverseNestedWrong(arr5);
    cout << "Reversed with nested loop (flawed logic): ";
    sol.printArray(arr5);

    return 0;
}
