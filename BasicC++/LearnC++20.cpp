#include<iostream>
using namespace std;

//STRUCTURES

struct Rectangle{
    int length;
    int breadth;
};
int main(){
    struct Rectangle r1={10,15};
    cout<<sizeof(r1)<<endl;
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;
    return 0;
}