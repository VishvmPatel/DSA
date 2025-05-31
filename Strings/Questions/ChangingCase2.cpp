#include <iostream>
#include <string>
#include <cctype>  // Required for toupper(), tolower()
using namespace std;

//Using toupper() and tolower() (C Library)

string toUpperC(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    return str;
}

string toLowerC(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

int main() {
    string s1 = "hello world";
    cout << "Uppercase: " << toUpperC(s1) << endl;
    
    string s2 = "HELLO WORLD";
    cout << "Lowercase: " << toLowerC(s2) << endl;
    
    return 0;
}