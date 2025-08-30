#include<iostream>
#include<cstring>
using namespace std;

class Stack
{
    int size;
    int top=-1;
    char *S;

public:
    void create(char *s);
    int isEmpty();
    int isFull();
    void push(char x);
    char pop();
};

void Stack::create(char *s)
        {
        size=strlen(s);
        top=-1;
        this->S = new char[size];    //this is the stack
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

void Stack::push(char x)
{
    if(size-top==1)
    {
        cout<<"stack is overflow\n";
    } else {
        top++;
        S[top]=x;
    }
}

char Stack::pop()
{
    char x=-1;
    if(top == -1)
    {
        cout<<"Stack is underflow\n";
    }
    else{
        x=S[top];
        top--;
    }
    return x;
}

int isBalanced(char *s)
{
    int i;
    int j;
    struct Stack st;
    st.create(s);

    for(i=0;s[i]!='\0';i++)
    {
        j = i-1;
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(!(s[i] == s[j]) && st.isEmpty())
                return 0;
            st.pop();
        }
    }
    if(st.isEmpty())
        return 1;
    else
        return 0;
}

int main()
{
    char s[] = "{([hedfsdfllo]))}";

    if(isBalanced(s))
    {
        cout<<"Yes"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}