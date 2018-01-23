/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr & John Olmos
 * Created on January 9, 2018, 1:39 PM
 * Purpose:  Convert temperature
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
    float degF,//Degrees Fahrenheit
          degC;//Degrees Celsius
    
    //Initialize Variables
    cout<<"This program converts the temperature in Celsius to Fahrenheit.\n"
        <<"Input the temperature in degrees Celsius to be converted: ";
    cin>>degC;
    
    //Process/Map inputs to outputs
    degF=degC*9/5+32;
    
    //Output data
    cout<<degC<<" degrees Celsius = "<<degF<<" degrees Fahrenheit. \n";
    
    //Exit stage right!
    return 0;
}