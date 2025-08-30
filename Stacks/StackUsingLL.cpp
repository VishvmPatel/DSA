#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class StackLL
{
    
public:
    Node *top = NULL;
    void InitializeStack();
    void Display();
    int isEmpty();
    int isFull();
    void push(int x);
    void pop();
    int peek(int index);
    int StackTop();
    void display(Node* p);
};

void StackLL::InitializeStack()
{
    int n;
    Node *q = NULL;
    cout << "How many elements: ";
    cin >> n;

    if (n <= 0) {
        top = NULL; // Handle empty stack case
        return;
    }

    // Create the first node
    Node *p = new Node;
    cout << "Enter element 1: ";
    cin >> p->data;
    top = q = p;

    // Loop to create and link the rest of the nodes
    for (int i = 1; i < n; i++) {
        p = new Node;
        cout << "Enter element " << i + 1 << ": ";
        cin >> p->data;
        q->next = p; // Link previous node to the new one
        q = p;       // Move q to the new node
    }
    q->next = NULL; // Ensure the last node's `next` is NULL

    Node* s = top; 
    cout<<"Displaying Stack  ";
    display(s);
}

void StackLL::Display()
{
    Node *p = top;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int StackLL::isEmpty()
{
    return top ? 0 : 1;
}

int StackLL::isFull()
{
    Node *t = new Node;
    int x = t ? 1 : 0;
    return x;
}

void StackLL::push(int x)
{
    Node *t = new Node;
    if(t==NULL){
        cout<<"Stack Overflow"<<endl;
    } else{
        t->data = x;
        t->next = top;
        top = t;
        cout<<x<<" inserted"<<endl;
    }
    cout<<"Updated Stack: ";
    Display();
}

void StackLL::pop()
{
    if(!top){
        cout<<"Empty stack"<<endl;
    } else {
        Node *p = top;
        top = top->next;
        cout<<p->data<<" deleted"<<endl;
        delete p;
    }
    Display();
}

int StackLL::peek(int index)
{
    Node *p = top;
    for(int i=0;i<index-1;i++)
    {
        p = p->next;
    }
    return p->data;
}


void StackLL::display(Node* p)
{
    if(p){
        display(p->next);
        cout<<p->data<<" ";
    }
}


int main()
{
    StackLL A;
    A.InitializeStack(); 

    return 0;
}