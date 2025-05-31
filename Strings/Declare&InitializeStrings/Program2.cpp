#include <iostream>
#include <string>  // Required for std::string
using namespace std;

//Using std::string (C++ String Class)

int main() {
    // Method 1: Direct assignment
    string str1 = "Hello, C++ Strings!";
    
    // Method 2: Using constructor
    string str2("Welcome to C++");
    
    // Method 3: Initialize with repeated characters
    string str3(5, 'A');  // "AAAAA"
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    
    return 0;
}