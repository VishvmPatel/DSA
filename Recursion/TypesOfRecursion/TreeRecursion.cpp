#include<iostream>
using namespace std;

//TREE RECURSION
void fun(int n){
    if(n>0){
        cout<<n<<"\n";
        fun(n-1);
        fun(n-1);
    }
}

int main(){
    int x=3;
    fun(x);
    return 0;
}