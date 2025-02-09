#include<bits/stdc++.h>
using namespace std;

//Creating pointer in heap

int main(){
    int *p;
    p = new int[5];
    p[0]=10; p[1]=15; p[2]=14; p[3] = 21; p[4] =31;

    for(int i = 0; i<5 ; i++){
        cout<<p[i]<<endl;
    }
    return 0;
}