#include<iostream>
using namespace std;

//LOGIC 
int sum(int n){
    if(n==0){
        return 0;
    }
    else{
        return sum(n-1) + n;
    }
}

//MAIN FUNCTION
int main(){
    int r = sum(5);
    cout<<r<<" ";
    return 0;
}