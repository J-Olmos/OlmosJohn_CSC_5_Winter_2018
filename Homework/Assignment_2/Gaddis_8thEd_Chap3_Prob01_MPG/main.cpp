/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 10, 2018, 12:27 PM
 * Purpose: Calculate miles per gallon
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
    float tank,//Capacity in gallons for a gas tank
          dist,//Maximum range on a full tank
          mpg;//Gas milage in miles/gallon
    
    //Initialize Variables
    cout<<"Enter the amount of gas (in gallons) your car's tank can hold: ";
    cin>>tank;
    cout<<"Enter the range (in miles) for your car on a full tank of gas: ";
    cin>>dist;    
    
    //Process/Map inputs to outputs
    mpg=dist/tank;
    
    //Output data
    cout<<fixed<<setprecision(1)
        <<"Your estimated gas milage is "<<mpg<<" mpg.\n";
    
    //Exit stage right!
    return 0;
}