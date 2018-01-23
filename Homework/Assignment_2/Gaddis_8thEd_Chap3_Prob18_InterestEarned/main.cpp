/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 10, 2018, 7:48 PM
 * Purpose:  Interest earned
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float sP,//Principal savings amount in USD
          iR,//Interest rate
          iC,//Number of times interest is compounded during a year
          iE,//Interest earned
          sF;//Final amount in savings
    
    //Initialize Variables
    cout<<"This program calculates interest earned in a savings account.\n"
        <<"Enter the principal (in USD): ";
    cin>>sP;
    cout<<"Enter the interest rate (in %): ";
    cin>>iR;
    cout<<"Enter the number of times interest is compounded: ";
    cin>>iC;
    
    //Process/Map inputs to outputs
    sF=sP*pow(1+(iR/100)/iC,iC);
    iE=sF-sP;
    
    //Output data
    cout<<setw(19)<<left<<"\nInterest rate:"<<setw(14)<<right<<iR<<"%\n"
        <<setw(19)<<left<<"Times compounded:"<<setw(14)<<right<<iC<<endl
        <<fixed<<setprecision(2)
        <<setw(19)<<left<<"Principal:"<<"$"<<setw(13)<<right<<sP<<endl
        <<setw(19)<<left<<"Interest:"<<"$"<<setw(13)<<right<<iE<<endl
        <<setw(19)<<left<<"Amount in Savings:"<<"$"<<setw(13)<<right<<sF<<endl;
    
    //Exit stage right!
    return 0;
}