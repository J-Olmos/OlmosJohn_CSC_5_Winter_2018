/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 10, 2018, 1:18 PM
 * Purpose: Calculate average rainfall
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
    string m1,m2,m3;//User defined name for each month
    float rain,//Rainfall values for each month
          sum,avg;//Total rainfall sum, and total rainfall average
    
    //Initialize Variables   
    sum=0;   
    
    cout<<"This program calculates the average rainfall for three months.\n"
        <<"Enter the name of each month.\n" 
        <<"First month: ";
    cin>>m1;
    cout<<"Second month: ";
    cin>>m2;
    cout<<"Third month: ";
    cin>>m3;
    
    cout<<"Enter the rainfall (in inches) for each month.\n"
        <<"Rainfall in "<<m1<<": ";  
    cin>>rain;
    sum+=rain;
    
    cout<<"Rainfall in "<<m2<<": ";  
    cin>>rain;
    sum+=rain;
    
    cout<<"Rainfall in "<<m3<<": ";  
    cin>>rain;
    sum+=rain;
    
    //Process/Map inputs to outputs
    avg=sum/3;
    
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint<<endl
        <<"The average rainfall for "<<m1<<", "<<m2<<", and "<<m3
        <<" is "<<avg<<" inches.\n";
    
    //Exit stage right!
    return 0;
}