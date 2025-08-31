#include<iostream>
#include<stdlib.h>

using namespace std;

class CircularQueue{
    int size;
    int front, rear;
    int *cq;
public:
    CircularQueue(int n);
    int isEmpty();
    int isFull();
    void enqueue(int x);
    int dequeue();
    void display();
    ~CircularQueue();
};

CircularQueue::CircularQueue(int n)
{
    size = n;
    cq = new int[n];
    front = rear = 0;
}

int CircularQueue::isEmpty()
{
    return rear == front;
}

int CircularQueue::isFull()
{
    return front == ((rear+1)%size);
}

void CircularQueue::enqueue(int x)
{
    if(isFull()){
        cout<<"Cannoot insert "<<x<<" - queue is full"<<endl;
    } else {
        rear = ((rear+1) % size);
        cq[rear] = x;
    }
}

int CircularQueue::dequeue()
{
    int x = -1;
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return x;
    } else {
        front = ((front + 1) % size );
        x = cq[front];
        return x; 
    }
}

void CircularQueue::display()
{
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = (front + 1) % size; // Start from the next position of front
    do {
        cout << cq[i] << " ";
        i = (i + 1) % size; // Move circularly
    } while (i != (rear + 1) % size); // Stop when you reach (rear + 1) % size
    cout << endl;
}

CircularQueue::~CircularQueue(){
    delete []cq;
}

int main()
{
    CircularQueue q(4);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    cout<<"Deleted "<<q.dequeue()<<endl;
    q.enqueue(67);
    q.display();

    return 0;
}