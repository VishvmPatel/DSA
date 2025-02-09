#include<bits/stdc++.h>
using namespace std;

//POINTER

int main(){
    int a=10;
    int *p;
    p=&a;

    cout<<a<<endl;
    //using pointer
    cout<<*p<<endl;
    //Printing address
    cout<<p<<endl;
    cout<<&a;//this is same as the value of p as both give address of a

    return 0;
}