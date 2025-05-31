#include <iostream>
#include <string>
using namespace std;

//Manaual Iteration using for loop

int main() {
    string str = "welcome";
    int length = 0;
    
    for (char c : str) {  // Iterate over each character using for-each loop
        length++;
    }
    
    cout << "Length: " << length << endl;
    return 0;
}