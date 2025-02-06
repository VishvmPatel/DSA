#include<bits/stdc++.h>
using namespace std;

//Take two numbers and print their sum using functions

int sum(int num1 ,int num2){      //Example of the return function
    int num3 = num1+ num2;
    return num3;
}
int main(){
    int num1, num2;
    cin>>num1>>num2;
    int res = sum(num1, num2);
    cout<<res;
    return 0;
}