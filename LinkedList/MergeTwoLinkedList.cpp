#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create1(int A[], int n)
{
    struct Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    struct Node *last, *t;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
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
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Merge two sorted linked lists into third
void Merge(struct Node *p, struct Node *q)
{
    Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int main()
{
    int A[] = {4, 7, 17, 21, 25, 30};
    int B[] = {5, 15, 19, 23, 27, 34, 37};
    create1(A, 6);
    cout << "First    : ";
    Display(first);
    create2(B, 7);
    cout << "Second   : ";
    Display(second);

    Merge(first, second);
    cout << "Merged   : ";
    Display(third);

    return 0;
}
