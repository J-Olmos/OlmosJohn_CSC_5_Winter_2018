/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 6, 2018, 4:31 PM
 * Purpose: Calculate and display the average of five values
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
    short a,b,c,d,e;//Five variable integers
    float sum,avg;//Sum and average of five variables
    
    //Initialize Variables
    a=28;
    b=32;
    c=37;
    d=24;
    e=33;
    
    //Process/Map Inputs to Outputs
    sum=a+b+c+d+e;
    avg=sum/5;
  
    //Output Data
    cout<<"The average of "<<a<<", "<<b<<", "<<c<<", "<<d<<", and "<<e
        <<" = "<<avg<<endl;
    
    //Exit Stage Right
    return 0;
}

