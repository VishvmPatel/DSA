#include<bits/stdc++.h>
using namespace std;

//STRINGS

int main(){
    string s = "HalfBloodPrince";
    int len = s.size();
    cout<<len<<"\n";
    cout<< s[2]<<"\n";
    s[len-1]='z';
    cout<<s[len-1];
    return 0;
}