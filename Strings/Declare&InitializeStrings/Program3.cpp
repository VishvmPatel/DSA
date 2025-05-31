#include <iostream>
#include <string>
using namespace std;

//Taking String Input from User

int main() {
    string userInput;
    
    cout << "Enter a string: ";
    getline(cin, userInput);  // Reads entire line (including spaces)
    
    cout << "You entered: " << userInput << endl;
    
    return 0;
}