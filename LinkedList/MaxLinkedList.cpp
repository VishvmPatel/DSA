#include <iostream>
#include <climits>  // For INT_MIN
using namespace std;

struct Node {
    int data;
    Node* next;  // No need for 'struct' in C++
};

Node* first = nullptr;  // Use nullptr instead of NULL

void create(int A[], int n) {
    Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++) {  // Fixed: Declare 'i' in loop
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

int Max(Node* p) {
    int max_val = INT_MIN;  // Use INT_MIN from <climits>
    while (p != nullptr) {
        if (max_val < p->data)
            max_val = p->data;
        p = p->next;
    }
    return max_val;
}

int RMax(Node* p) {
    if (p == nullptr)
        return INT_MIN;
    int x = RMax(p->next);
    return (x > p->data) ? x : p->data;
}

int main() {
    int A[] = {4, 5, 78, 8, 94, 7222};
    create(A, 6);
    cout << "Maximum (Iterative): " << Max(first) << endl;
    cout << "Maximum (Recursive): " << RMax(first) << endl;

    // Free memory
    Node* temp = first;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}