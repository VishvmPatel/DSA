#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printTriangle(int n) {
        for(int i = 1; i<=n ; i++ ){
            for(int j =1 ; j<=i ; j++ ){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
};

// LOGIC BEHIND THE PATTERN 
/*
Input: 5

Output:
1
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5
*/