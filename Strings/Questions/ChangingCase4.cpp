#include <iostream>
#include <string>
using namespace std;

// Convert to lowercase using bitwise OR (sets 6th bit)
string toLowerBitwise(string str) {
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c |= 32;  // 01000001 (A) → 01100001 (a)
        }
    }
    return str;
}

// Convert to uppercase using bitwise AND (clears 6th bit)
string toUpperBitwise(string str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c &= ~32;  // 01100001 (a) → 01000001 (A)
        }
    }
    return str;
}

int main() {
    // Test lowercase conversion
    string s1 = "HELLO World 123!";
    cout << "Original:  " << s1 << endl;
    cout << "Lowercase: " << toLowerBitwise(s1) << endl << endl;

    // Test uppercase conversion
    string s2 = "hello WORLD 456!";
    cout << "Original:  " << s2 << endl;
    cout << "Uppercase: " << toUpperBitwise(s2) << endl << endl;

    // Test mixed conversion
    string s3 = "BitWise Magic!";
    cout << "Original:  " << s3 << endl;
    cout << "Lowercase: " << toLowerBitwise(s3) << endl;
    cout << "Uppercase: " << toUpperBitwise(s3) << endl;

    return 0;
}