#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing number using the sum formula
int findMissingNumber(const vector<int>& arr) {
    int n = arr.size() + 1; // Since one number is missing, original size is n+1
    int expectedSum = n * (n + 1) / 2; // Sum of first 'n' natural numbers
    int actualSum = 0;

    // Calculate the sum of elements in the array
    for (int num : arr) {
        actualSum += num;
    }

    // The missing number is the difference
    return expectedSum - actualSum;
}

int main() {
    // Test cases
    vector<int> arr1 = {1, 2, 3, 5}; // Missing 4
    vector<int> arr2 = {1, 3, 4, 5}; // Missing 2
    vector<int> arr3 = {2, 3, 4, 5}; // Missing 1
    vector<int> arr4 = {1, 2, 3, 4}; // Missing 5

    cout << "Missing number in [1, 2, 3, 5]: " << findMissingNumber(arr1) << endl;
    cout << "Missing number in [1, 3, 4, 5]: " << findMissingNumber(arr2) << endl;
    cout << "Missing number in [2, 3, 4, 5]: " << findMissingNumber(arr3) << endl;
    cout << "Missing number in [1, 2, 3, 4]: " << findMissingNumber(arr4) << endl;

    return 0;
}