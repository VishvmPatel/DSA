#include<iostream>

using namespace std;

class Queue{
    int size;
    int rear, front;
    int *q;
public:
    Queue(int n)
    {
        size = n;
        q = new int[size];
        rear = front = -1;
    }

    ~Queue() {
    delete [] q;
    }

    int isEmpty() {
        return rear == front;
    }

    int isFull() { 
        return size - rear == 1;
        }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            rear++;
            q[rear] = x;
        }
    }

    int dequeue() {
        int x = -1;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            x = q[++front];
        }
        return x;
    }

    int first() {
        if (!isEmpty()) {
            return q[front];
        }
        cout << "Queue is empty" << endl;
        return -1;
    }

    int last() {
        if (!isEmpty()) {
            return q[rear];
        }
        cout << "Queue is empty" << endl;
        return -1;
    }

    void Display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = front+1; i <= rear; i++) { // Fixed loop
                cout << q[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue Q(6);
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.Display();

    return 0;
}