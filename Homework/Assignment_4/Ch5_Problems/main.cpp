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
    int year=25;
    float rise=0;
    
    //Initialize Variables
    cout<<"This table displays the number of millimeters the\n"
        <<"ocean will have risen each year for the next 25 years.\n\n"
        <<"Year   Increase\n"
        <<"---------------\n";
    
    //Process/Map inputs to outputs
    for(int i=1;i<=year;i++){
        rise+=1.5f;
        cout<<setw(3)<<i
            <<fixed<<setprecision(1)
            <<setw(9)<<rise<<"mm\n";
        }
    
    //Output data
    
    //Exit stage right!
    return 0;
}