#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printSquare(int n) {
        for(int i = 0 ; i< n; i++){
            for(int j = 0 ; j<n ;j++){
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};

// LOGIC BEHIND THE PATTERN 
/*
Input:
n = 3
Output:
* * *
* * *
* * *
*/