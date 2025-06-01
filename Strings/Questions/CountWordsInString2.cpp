#include <iostream>
using namespace std;

int countWords(char str[]) {
    int word = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            inWord = false;
        } else if (!inWord) {
            word++;
            inWord = true;
        }
    }
    return word;
}

int main() {
    char A[] = "  How   are   you  ";
    cout << "Word count: " << countWords(A) << endl;  // Output: 3
    return 0;
}