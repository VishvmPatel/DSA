#include <iostream>
using namespace std;

void fun(int n) {
    static int x = 0;  // Static variable (retains value across calls)
    if (n > 0) {
        x++;  // Increment x in each call
        fun(n - 1);
    }
    cout << x << " ";  // Print after recursion unwinds
}

int main() {
    fun(5);
    return 0;
}
