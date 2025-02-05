#include<bits/stdc++.h>
using namespace std;

//Write a program that takes an input of age and prints if you are adult or not
// age >=18 then adult , and if age < 18 then not an adult
int main(){
    int age;
    cin >> age;
    if(age >= 18){
        cout<<"You are an Adult";
    }else{
        cout<<"You are not an Adult";
    }
    return 0;
}