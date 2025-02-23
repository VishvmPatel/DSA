#include <iostream>
using namespace std;

int x = 0 ; //Global Variable
int fun(int n) {
    if (n > 0) {
        x++;  // Increment x in each recursive call
        return fun(n - 1) + x;  // Recursive call and accumulation of x
    }
    return 0;  // Base case: when n reaches 0, return 0
}

int main() {
    int r = fun(5);  // Calling the function with n = 5
    cout << r << "\n";  // Output the result

    r = fun(5);
    cout << r << "\n";
    return 0;
}
