#include<bits/stdc++.h>
using namespace std ;

//NESTED IF

/*
Take age from the user and then decide accordingly
1. If age < 18
  print -> not eligible for job
2. If age >= 18
  print -> "Eligible for job"
3. If age >= 55 and age <=57
  print -> "Eligible for job but retirement soon"
4. If age > 57
  print -> "retirement time"
*/

int main(){
    int age ;
    cin >>age;
    if(age < 18 ){
        cout<<"Not eligible for the job";
    }
    else if(age <= 57){
        if(age >=55){
            cout<<"Eligible for the job but retirement soon.";
        }else{
            cout<<"Eligible for the job";
        }
    }
    else{
        cout<<"Retirement Time.";
    }
    return 0;
}