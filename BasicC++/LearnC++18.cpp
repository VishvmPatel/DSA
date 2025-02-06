#include<bits/stdc++.h>
using namespace std;

// PASS BY VALUE

void doSomething(int num){
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
}
int main(){
    int num = 10;
    doSomething(num); //In this function a copy of the num variable went so in the next step.....
    cout<<num<<endl; // when we did this again 10 was printed which was the original input.
    return 0;
}