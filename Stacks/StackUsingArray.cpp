#include<iostream>
#include<stdlib.h>
using namespace std;

class Stack{
    int size;
    int top;
    int *S;
public:
    void InitializeStack();
    void display();
    void push(int x);
    int pop();
    int peek(int index);
    int StackTop();
    int isEmpty();
    int isFull();

};

void Stack::InitializeStack()
{
    cout<<"Enter the size of stack : ";
    cin>>size;
    top=-1;
    S=new int[size];
    int i;
    cout<<"How many elements: ";
    cin>>i;
    for(int j=0; j<i; j++)
    {
        cout<<"Element "<<j+1<<": ";
        cin>>S[j];
        top=j;
    }
}

void Stack::display()
{
    if(top==-1)
        cout<<"stack is Empty";
    else{
        int i;
        for(i=top;i>=0;i--)
        {
            cout<<S[i]<<" ";
        }
        cout<<endl;
    }
}

void Stack::push(int x)
{
    if(size-top==1)
    {
        cout<<"stack is overflow\n";
    }
    else{
        top++;
        S[top]=x;
    }
    cout<<"Element "<<x<<" pushed"<<endl;
}

int Stack::pop()
{
    int x=-1;
    if(top==-1)
    {
        cout<<"Stack is underflow\n";
    }
    else{
        x=S[top];
        top--;
    }
    return x;
}

int Stack::peek(int index)
{
    int x=-1;
    if(top-index+1<0)
        cout<<"Invalid Index\n";
    else{
        x=S[top-index+1];
    }
    return x;
}

int Stack::StackTop()
{
    int x=-1;
    if(top!=-1){
        x=S[top];
    }
    return x;
}

int Stack::isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int Stack::isFull()
{
    if(size-top==1)
        return 1;
    else
        return 0;
}

int main()
{
    struct Stack a;
    a.InitializeStack();
    // a.push(1);
    // a.push(4);
    // a.push(8);
    // a.push(9);
    // a.push(11);
    a.display();
    return 0;
}