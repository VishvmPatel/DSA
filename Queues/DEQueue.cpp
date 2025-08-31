#include <iostream>
using namespace std;

class DEQueue {
    int *dq;       
    int size;      
    int front;     
    int rear;

public:
    DEQueue(int n);    
    ~DEQueue();        

    bool isEmpty();
    bool isFull();     

    void insertFront(int x); 
    void insertRear(int x);  
    
    int deleteFront();      
    int deleteRear();        

    void display();          
};

DEQueue::DEQueue(int n) {
    size = n;
    dq = new int[size];
    front = -1;
    rear = -1;
}

DEQueue::~DEQueue() {
    delete[] dq;
}

bool DEQueue::isEmpty() {
    return (front == -1);
}

bool DEQueue::isFull() {
    return ((front == 0 && rear == size - 1) || (rear + 1 == front));
}

void DEQueue::insertFront(int x) {
    if (isFull()) {
        cout << "Cannot insert " << x << " - DEQueue is full" << endl;
        return;
    }
    if (isEmpty()) { 
        front = rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front--;
    }
    dq[front] = x;
}

void DEQueue::insertRear(int x) {
    if (isFull()) {
        cout << "Cannot insert " << x << " - DEQueue is full" << endl;
        return;
    }
    if (isEmpty()) {                        // First element being inserted
        front = rear = 0;
    } else if (rear == size - 1) {          // Wrap around to the front
        rear = 0;
    } else {
        rear++;
    }

    dq[rear] = x;
}

int DEQueue::deleteFront() {
    if (isEmpty()) {
        cout << "DEQueue is empty" << endl;
        return -1;
    }

    int x = dq[front];

    if (front == rear) {                    // Only one element was present
        front = rear = -1;
    } else if (front == size - 1) {         // Wrap around to the start
        front = 0;
    } else {
        front++;
    }

    return x;
}

int DEQueue::deleteRear() {
    if (isEmpty()) {
        cout << "DEQueue is empty" << endl;
        return -1;
    }

    int x = dq[rear];

    if (front == rear) {                    // Only one element was present
        front = rear = -1;
    } else if (rear == 0) {                 // Wrap around to the end
        rear = size - 1;
    } else {
        rear--;
    }

    return x;
}

void DEQueue::display() {
    if (isEmpty()) {
        cout << "DEQueue is empty" << endl;
        return;
    }

    int i = front;
    do {
        cout << dq[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
}

int main() {
    DEQueue dq(5); 

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(2);
    dq.insertRear(30);

    dq.display(); 

    cout << "Deleted from front: " << dq.deleteFront() << endl; 
    cout << "Deleted from rear: " << dq.deleteRear() << endl;  

    dq.display();

    dq.insertFront(15);
    dq.display();

    return 0;
}