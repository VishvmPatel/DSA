#include<bits/stdc++.h>
using namespace std;

//IF and ELSE IF STATEMENTS

/*
A school has following rules for grading system:
a. Below 25 - F
b. 25 to 44 - E
c. 45 to 49 - D
d. 50 to 59 - C
e. 60 to 79 - B
f. 80 to 100 - A
Ask user to enter marks and print the corresponding grade.
*/
int main(){
    int marks;
    cout<<"Enter your marks: ";
    cin >>marks;
    if(marks < 25){
        cout<<"Your grade is F.";
    }else if(marks <=44 ){
        cout<<"Your grade is E.";
    }else if(marks <=49){
        cout<<"Your grade is D";
    }else if(marks <=59){
        cout<<"Your grade is C";
    }else if(marks <=79){
        cout<<"Your grade is B";
    }else if(marks <=100){
        cout<<"Your grade is A";
    }
    return 0;
}