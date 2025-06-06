#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Compare with other letters

vector<char> findDuplicatesCompare(const string &s) {
    unordered_set<char> duplicates;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                duplicates.insert(s[i]);
            }
        }
    }
    
    vector<char> result(duplicates.begin(), duplicates.end());
    sort(result.begin(), result.end());
    return result;
}

// Example usage:
int main() {
    string input = "hello world";
    vector<char> result = findDuplicatesCompare(input);
    for (char c : result) {
        cout << c << " ";
    }
    return 0;
}