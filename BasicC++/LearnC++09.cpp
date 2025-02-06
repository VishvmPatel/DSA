#include<bits/stdc++.h>
using namespace std;

//ARRAYS - 1D Array

//Datatype has to be constant for all the elements

int main(){
    int arr[5];
    for(int i = 0 ; i<=4; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i<=4; i++){
        cout << arr[i] << " ";
    }
    
    cout<< endl;
    arr[3] += 10;
    cout<<arr[3];
    return 0;
}