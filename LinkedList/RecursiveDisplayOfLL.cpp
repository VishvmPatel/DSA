#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* first = nullptr;

void create(int A[], int n) {
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void Display(Node* p) {
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void RDisplay(Node* p) {
    if (p != nullptr) {
        RDisplay(p->next);
        cout << p->data << " ";
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    cout << "Linked List (Forward): ";
    Display(first);
    cout << "Linked List (Reverse): ";
    RDisplay(first);
    cout << endl;

    // Free memory (prevent leaks)
    Node* temp = first;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}