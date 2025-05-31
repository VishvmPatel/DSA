#include <iostream>
using namespace std;

//C-Style String

int main() {
    const char *S = "welcome";  // Correct: pointer to a string literal
    int length = 0;

    // Loop until the null terminator '\0' is found
    for (int i = 0; S[i] != '\0'; i++) {
        length++;
    }

    cout << "Length (C-style): " << length << endl;  // Output: 7
    return 0;
}