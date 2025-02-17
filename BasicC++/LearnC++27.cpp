#include <iostream>  // Use iostream for input/output

int main() {
    int* ptr = new int;  // Dynamically allocate memory on the heap

    if (!ptr) {  // Check if allocation was successful
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }

    *ptr = 25;
    std::cout << "Dynamically allocated value: " << *ptr << std::endl;

    delete ptr;  // Free allocated memory to prevent memory leaks
    return 0;
}
