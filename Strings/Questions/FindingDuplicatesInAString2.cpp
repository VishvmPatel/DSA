#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//Using Hashing and Counting

vector<char> findDuplicatesHashtable(const string &s) {
    unordered_map<char, int> charCount;
    unordered_set<char> duplicates;
    
    for (char c : s) {
        charCount[c]++;
        if (charCount[c] > 1) {
            duplicates.insert(c);
        }
    }
    
    vector<char> result(duplicates.begin(), duplicates.end());
    sort(result.begin(), result.end());
    return result;
}

// Example usage:
int main() {
    string input = "hello world";
    vector<char> result = findDuplicatesHashtable(input);
    for (char c : result) {
        cout << c << " ";
    }
    return 0;
}