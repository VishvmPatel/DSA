#include<bits/stdc++.h>
using namespace std;

//Functions are set of code which performs something for you.
//Functions are used to modularise the code
//Functions are used to increase readability
//Functions are used to use the code multiple times
//void -> which does not returns anything
//return
//parameterised
//non-parameterised

void printName(string name){
    cout<<"Hey "<<name <<endl;
}
int main(){
    string name;
    cin>>name;
    printName(name);

    string name2;
    cin>>name2;
    printName(name2);
    return 0;
}