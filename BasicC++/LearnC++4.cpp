//DATA TYPES
#include<bits/stdc++.h>
using namespace std;
int main(){
    // int 
    int a = 10;
    // long
    long b = 15; // has a larger range than int
    long long c = 150000000; // to create a much larger range

    // float , double
    float x = 5.6;
    double y = 5;
    cout<<"Value of y is: " <<y<<" and value of x is: "<<x<<"\n";

    //String and getline
    /*string s;
    cin>>s;
    cout<<s; // Now as we know that this will only take upto one word so we use getline
    */
    string str;
    getline(cin,str);
    cout<<str;
    return 0;
}