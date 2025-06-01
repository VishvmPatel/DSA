#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//Using STL find() with a Vowel Set

void countVowelsConsonants(const string& str) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int vowelCount = 0, consonantCount = 0;
    for (char c : str) {
        if (isalpha(c)) {
            c = tolower(c);
            if (vowels.find(c) != vowels.end()) {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
    }
    cout << "Vowels: " << vowelCount << "\nConsonants: " << consonantCount << endl;
}

int main() {
    string s = "C++ Programming";
    countVowelsConsonants(s);  // Output: Vowels: 3, Consonants: 9
    return 0;
}