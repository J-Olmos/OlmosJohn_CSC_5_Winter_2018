/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 5, 2018, 10:52 PM
 * Purpose: add two numbers
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
    short a,b,total;//Three integer variables
    
    //Initialize Variables
    a=50;
    b=100;
    
    //Process/Map Inputs to Outputs
    total=a+b;
  
    //Output Data
    cout<<a<<" + "<<b<<" = "<<total<<endl;
    
    //Exit Stage Right
    return 0;
}

