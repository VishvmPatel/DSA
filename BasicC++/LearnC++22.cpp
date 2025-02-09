#include<bits/stdc++.h>
using namespace std;

//Using pointers in arrays

int main(){
    int A[5] = {2,4,6,8,10};
    int *p;
    p=&A[0];

    for(int i = 0; i<5 ; i++){
        cout<<p[i]<<endl;
    }

    return 0;
}