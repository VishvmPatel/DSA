#include <iostream>
using namespace std;

int fun(int n) {
    static int x = 0;  // Static variable retains its value across function calls
    if (n > 0) {
        x++;  // Increment x in each recursive call
        return fun(n - 1) + x;  // Recursive call and accumulation of x
    }
    return 0;  // Base case: when n reaches 0, return 0
}

int main() {
    int r = fun(5);  // Calling the function with n = 5
    cout << r << "\n";  // Output the result
    return 0;
}
