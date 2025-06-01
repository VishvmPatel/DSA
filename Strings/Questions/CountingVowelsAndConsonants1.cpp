#include <iostream>
#include <string>
using namespace std;

//Using Direct Character Checks (ASCII)

void countVowelsConsonants(const string& str) {
    int vowels = 0, consonants = 0;
    for (char c : str) {
        if (isalpha(c)) {  // Check if it's a letter
            c = tolower(c); // Convert to lowercase for uniform comparison
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    cout << "Vowels: " << vowels << "\nConsonants: " << consonants << endl;
}

int main() {
    string s = "Hello, World!";
    countVowelsConsonants(s);  // Output: Vowels: 3, Consonants: 7
    return 0;
}