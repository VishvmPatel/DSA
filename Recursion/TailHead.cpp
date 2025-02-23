#include<iostream>
using namespace std;

//TAIL RECURSION
void fun1(int n){
    if(n>0){
        cout<<n<<" ";
        fun1(n-1);
    }
}

//HEAD RECURSION
void fun2(int n){
    if(n>0){
        fun2(n-1);
        cout<<n<<" ";
    }
}

int main(){
    int x=3;
    fun1(x);
    cout<<"\n";
    fun2(x);
    return 0;
}