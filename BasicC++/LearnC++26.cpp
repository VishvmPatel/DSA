#include <iostream>  // Use iostream instead of stdio.h

// STATIC ALLOCATION

int globalVar = 10;  // Statically allocated in the data segment

void function() {
    int localVar = 20;  // Statically allocated in the stack
    std::cout << localVar << std::endl;  // Using C++ style output
}

int main() {
    function();
    return 0;
}

