#include <iostream>
using namespace std;

//INDIRECT RECURSION
void funA(int n);  // Function declaration
void funB(int n);

void funA(int n) {
    if (n > 0) {
        cout << n << " ";  // Print n
        funB(n - 1);  // Call funB
    }
}

void funB(int n) {
    if (n > 1) {
        cout << n << " ";  // Print n
        funA(n / 2);  // Call funA
    }
}

int main() {
    funA(20);
    return 0;
}
