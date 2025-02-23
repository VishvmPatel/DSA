#include<iostream>
using namespace std;

//HEAD RECURSION
void fun(int n){
    if(n>0){
        fun(n-1);
        cout<<n<<"\n";
    }
}
int main(){
    int n = 3;
    fun(n);
}
