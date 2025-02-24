#include <iostream>
using namespace std;

//NESTED RECURSION
int nestedRec(int n) {
    if (n > 100) return n - 10;  // Base case
    return nestedRec(nestedRec(n + 11));  // Recursive call within itself
}

int main() {
    cout << "Result: " << nestedRec(95);
    return 0;
}
