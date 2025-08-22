#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

void create1(int A[],int n)
{
    struct Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[],int n)
{
    struct Node *last, *t;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Concatenate two linked lists
void Concatenate(struct Node *p, struct Node *q) 
{
    third = p;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
}

int main()
{
    int A[]={4,7,17,21,25,30};
    int B[]={5,15,19,23,27,34,37};
    
    create1(A,6);
    cout << "First      : ";
    Display(first);
    
    create2(B,7);
    cout << "Second     : ";
    Display(second);    

    Concatenate(first, second);
    cout << "Concatenated : ";
    Display(third);

    return 0;
}
