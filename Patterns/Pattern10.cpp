#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void printTriangle(int n) {
          int start = 1;
          for(int i = 0; i<n ; i++){
              if(i%2==0) start = 1;
              else start = 0;
              for(int j = 0 ; j<=i ; j++){
                  cout << start<<" ";
                  start = 1-start;
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
0 1 
1 0 1
0 1 0 1 
1 0 1 0 1
*/