#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<char> findDuplicatesBits(const string &s) {
    int checker = 0;
    unordered_set<char> duplicates;
    
    for (char c : s) {
        int val = c - 'a'; // Assuming only lowercase letters
        if ((checker & (1 << val)) > 0) {
            duplicates.insert(c);
        }
        checker |= (1 << val);
    }
    
    vector<char> result(duplicates.begin(), duplicates.end());
    sort(result.begin(), result.end());
    return result;
}

// Example usage for lowercase letters:
int main() {
    string input = "helloworld";
    vector<char> result = findDuplicatesBits(input);
    for (char c : result) {
        cout << c << " ";
    }
    return 0;
}