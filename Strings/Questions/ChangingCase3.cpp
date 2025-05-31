#include <iostream>
#include <string>
#include <algorithm>  // For transform()
#include <cctype>     // For toupper(), tolower()
using namespace std;

//Using std::transform() (Modern C++ STL)

// Convert string to uppercase using STL transform
string toUpperSTL(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Convert string to lowercase using STL transform
string toLowerSTL(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    // Test uppercase conversion
    string s1 = "hello world";
    cout << "Original: " << s1 << endl;
    cout << "Uppercase: " << toUpperSTL(s1) << endl << endl;

    // Test lowercase conversion
    string s2 = "HELLO WORLD";
    cout << "Original: " << s2 << endl;
    cout << "Lowercase: " << toLowerSTL(s2) << endl << endl;

    // Test mixed case
    string s3 = "C++ ProGramMing";
    cout << "Original: " << s3 << endl;
    cout << "Uppercase: " << toUpperSTL(s3) << endl;
    cout << "Lowercase: " << toLowerSTL(s3) << endl;

    return 0;
}