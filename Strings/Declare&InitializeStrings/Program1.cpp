#include <iostream>
using namespace std;

//Using C-Style Character Arrays (Null-Terminated)

int main() {
    // Method 1: Initialize with a string literal
    char str1[] = "Hello, World!";
    
    // Method 2: Initialize character by character
    char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    
    return 0;
}