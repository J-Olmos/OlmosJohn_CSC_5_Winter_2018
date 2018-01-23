/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 6, 2018, 4:53 PM
 * Purpose: Calculate and display ocean level over time.
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
    float rise,//Annual rise of ocean level in millimeters
          t5,t7,t10;//Total rise in ocean level after time
    
    //Initialize Variables
    rise=1.5;//Annual ocean rise of 1.5 millimeters
    
    //Process/Map Inputs to Outputs
    t5=rise*5;//Ocean rise after 5 years
    t7=rise*7;//Ocean rise after 5 years
    t10=rise*10;//Ocean rise after 5 years
  
    //Output Data
    cout<<"The ocean level is rising by "<<rise<<" millimeters a year \n"
        <<"In 5 years it will be "<<t5<<" millimeters higher.\n"
        <<"In 7 years it will be "<<t7<<" millimeters higher.\n"
        <<"In 10 years it will be "<<t10<<" millimeters higher.\n";
    
    //Exit Stage Right
    return 0;
}

