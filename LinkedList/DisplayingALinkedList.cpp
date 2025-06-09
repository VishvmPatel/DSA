#include <iostream>
#include <iterator> // Required for std::size (C++17+)
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() {
    int A[] = {3, 5, 7, 10, 15};
    constexpr size_t size = sizeof(A) / sizeof(A[0]); // Compile-time size

    Node* head = new Node;
    Node* temp;
    Node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // Create Linked List
    for (size_t i = 1; i < size; i++) { // Use size_t for array indexing
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }

    // Display Linked List
    Node* p = head;
    while (p != nullptr) {
        cout << p->data;
        if (p->next != nullptr) {
            cout << " -> ";
        }
        p = p->next;
    }
    cout << endl;

    // Free memory (prevent leaks)
    p = head;
    while (p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }

    return 0;
}