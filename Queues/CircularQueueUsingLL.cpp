#include<iostream>
#include<stdlib.h>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};
class LLQueue{
    Node *front, *rear;
public:
    LLQueue();
    LLQueue(int *n, int size);
    void display();
    void enqueue(int x);
    int dequeue();
    ~LLQueue();
};

LLQueue::LLQueue()
{
    front = rear = NULL;
}

LLQueue::LLQueue(int *n, int size)
{
    if(size < 1 ){
        cout<<"Size is too small"<<endl;
        return;
    } else {
        front = new Node;
        front->data = n[0];
        front->next = NULL;
        rear = front;
        for(int i=1; i<size; i++){
            Node *t = new Node;
            t->data = n[i];
            t->next = NULL;
            rear->next = t;
            rear = t;
        }
    }   
}

void LLQueue::display()
{
    Node *p = front;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void LLQueue::enqueue(int x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
        cout<<"Queue is full\n";
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
    cout<<"Queue Updated: ";
    display();
}

int LLQueue::dequeue()
{
    Node *p = front;
    front = front->next;
    return p->data;
    delete p;
}

LLQueue::~LLQueue()
{
    while(front){
        Node *p = front;
        front = front->next;
        delete p;
    }
}

int main()
{
    LLQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<"Deleted "<<q.dequeue()<<endl;
    q.enqueue(14);
    q.enqueue(15);

    q.display();

    return 0;
}