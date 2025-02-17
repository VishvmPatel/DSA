#include <stdio.h>

//STATIC ALLOCATIONS

int globalVar = 10;  // Statically allocated in the data segment

void function() {
    int localVar = 20;  // Statically allocated in the stack
    printf("%d\n", localVar);
}

int main() {
    function();
    return 0;
}
