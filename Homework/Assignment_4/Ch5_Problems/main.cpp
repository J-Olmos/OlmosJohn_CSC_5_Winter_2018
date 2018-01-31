/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 2, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int n,max,min;
    
    //Initialize Variables
    max=min=0;
    
    //Output Header
    cout<<"This program finds the largest and\n"
        <<"smallest out of the integers entered.\n\n";
    
    //Process/Map inputs to outputs
    cout<<"Enter a series of integers\n"
          "Type -99 to end the series: ";
    while(n!=-99){
        if(n>max){max=n;}
        if(n<min){min=n;}
        cin>>n;
        if(max==0){max=n;}
        if(min==0){min=n;}
    };
        
    //Output data
    cout<<"Largest number : "<<max<<endl
        <<"Smallest number: "<<min<<endl;    
    
    //Exit stage right!
    return 0;
}