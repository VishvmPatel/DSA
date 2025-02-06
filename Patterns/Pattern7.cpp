#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printTriangle(int n) {
        for(int i = 0; i<n ; i++){
            //space
            for(int j = 0 ; j<n-i-1;j++ ){
                cout<<" ";
            }
            //star
            for(int j = 0; j< 2*i+1 ; j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }
};

// LOGIC BEHIND THE PATTERN 
/*
Input: 5
Output:
    *
   ***  
  *****
 *******
*********
*/