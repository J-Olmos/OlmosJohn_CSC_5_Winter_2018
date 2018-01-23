/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr & John Olmos
 * Created on January 3, 2018, 12:45 PM
 * Purpose: Solve a paint coverage problem
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
    unsigned short htfnce, //Height of fence in feet
                   ltfnce, //Length of fence in feet
                   ptcovrg, //Paint coverage in square feet/gallons
                   ngallns; //Number of gallons to cover the fence
    
    //Initialize Variables
    htfnce=6; //6 feet
    ltfnce=100; //100 feet
    ptcovrg=340; //340 square feet/gallon
    
    //Process/Map Inputs to Outputs
    ngallns=2*(htfnce*ltfnce)/ptcovrg+1; //Add 1 to compensate for integer
    
    //Output Data
    cout<<"Height of fence = "<<htfnce<<"ft"<<endl
        <<"Length of fence = "<<ltfnce<<"ft"<<endl
        <<"Number of gallons to cover one side of the fence twice = "
        <<ngallns<<endl;
    
    //Exit Stage Right!
    return 0;
}