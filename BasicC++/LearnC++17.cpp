#include<bits/stdc++.h>
using namespace std;

//Example of using some inbuilt functions.

int main(){
    int num1 , num2;
    cin>>num1>>num2;
    int minimum = min(num1,num2);
    int maximum = max(num1,num2);
    cout<<"The minimum of the two numbers is: "<<minimum<<" & "<<"The maximum of the two numbers is: "<<maximum;
    return 0;
}