#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	
	void printTriangle(int n) {
	    for(int i = 0 ; i<n ; i++){
	        for(int j = 1 ; j<=n-i;j++){
	            cout<<j<<" ";
	        }
	        cout<<endl;
	    }
	}
};

// LOGIC BEHIND THE PATTERN 
/*
Input: 5

Output:
1 2 3 4 5
1 2 3 4
1 2 3 
1 2  
1 
*/