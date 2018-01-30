/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 2, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n,sum;    
    
    //Initialize Variables
    cout<<"Enter a positive integer: ";
    cin>>n;
    
    if(n<=0){
        cout<<"\nInvalid input.\n"
            <<"Enter a positive integer: ";
        cin>>n;
    }
    
    //Process/Map inputs to outputs
    sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    
    //Output data
    cout<<"\nThe sum integers from 1 to "<<n<<" = "<<sum<<endl;
    
    //Exit stage right!
    return 0;
}