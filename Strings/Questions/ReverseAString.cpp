#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

// Helper function to print the vector
void printVector(const vector<char>& v) {
    for (char c : v) {
        cout << c;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    // Test Case 1: Even-length string
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    cout << "Original: ";
    printVector(s1);
    sol.reverseString(s1);
    cout << "Reversed: ";
    printVector(s1);  // Output: "olleh"
    
    // Test Case 2: Odd-length string
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    cout << "\nOriginal: ";
    printVector(s2);
    sol.reverseString(s2);
    cout << "Reversed: ";
    printVector(s2);  // Output: "hannaH"
    
    // Test Case 3: Empty string
    vector<char> s3 = {};
    cout << "\nOriginal: ";
    printVector(s3);
    sol.reverseString(s3);
    cout << "Reversed: ";
    printVector(s3);  // Output: ""
    
    // Test Case 4: Single-character string
    vector<char> s4 = {'A'};
    cout << "\nOriginal: ";
    printVector(s4);
    sol.reverseString(s4);
    cout << "Reversed: ";
    printVector(s4);  // Output: "A"
    
    return 0;
}