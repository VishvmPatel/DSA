#include <iostream>
using namespace std;

int countWords(const char A[], int length) {
    if (length == 0) return 0;  // Handle empty array
    
    int wordCount = 0;
    
    for (int i = 0; i < length; i++) {
        // Count a new word if:
        // 1. It's the first character (i == 0) and not a space, OR
        // 2. Current character is not a space, and previous was a space
        if (A[i] != ' ' && (i == 0 || A[i-1] == ' ')) {
            wordCount++;
        }
    }
    return wordCount;
}

int main() {
    // Character array without null terminator
    const char A[] = {'H', 'o', 'w', ' ', 'a', 'r', 'e', ' ', 'y', 'o', 'u'};
    int length = sizeof(A) / sizeof(A[0]);  // Manually compute length

    cout << "Word count: " << countWords(A, length) << endl;  // Output: 3
    return 0;
}