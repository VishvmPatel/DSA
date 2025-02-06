#include<bits/stdc++.h>
using namespace std;

// PASS BY REFERENCE

void doSomething(int &num){
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
}
int main(){
    int num = 10;
    doSomething(num); //Because of the & the real value went into the function as we used the address of the num variable
    cout<<num<<endl; 
    return 0;
}