#include <iostream>
#include <string>
using namespace std;

//Using ASCII Codes

string toLowerASCII(string str) {
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c += 32;  // 'A' (65) → 'a' (97)
        }
    }
    return str;
}

string toUpperASCII(string str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // 'a' (97) → 'A' (65)
        }
    }
    return str;
}

int main() {
    string s1 = "HELLO World";
    cout << "Lowercase: " << toLowerASCII(s1) << endl;
    
    string s2 = "hello WORLD";
    cout << "Uppercase: " << toUpperASCII(s2) << endl;
    
    return 0;
}