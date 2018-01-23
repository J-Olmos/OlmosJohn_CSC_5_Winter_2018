/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr & John Olmos
 * Created on January 3, 2018, 1:20 PM
 * Purpose: Free Fall
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int GRAVITY=32; //Gravity in ft/sec^2

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short time, //Time in seconds
                   dist; //Distance in feet
    
    //Input free fall time
    cout<<"This program calculates the distance dropped "
        <<"during free-fall."<<endl
        <<"Input the time in free-fall."<<endl
        <<"Time measured in seconds."<<endl
        <<"In the range of 0 to 40 seconds."<<endl;
    cin>>time;
    
    //Process/Map Inputs to Outputs
    dist=GRAVITY*time*time/2;
    
    //Output Data
    cout<<"An object dropped for "<<time<<" second(s)"
        <<" falls "<<dist<<"ft."<<endl;
    
    //Exit Stage Right!
    return 0;
}