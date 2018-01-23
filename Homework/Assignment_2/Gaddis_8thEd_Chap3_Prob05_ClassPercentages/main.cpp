/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 10, 2018, 1:54 PM
 * Purpose: Calculate the percentage of males and females in a class
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
    int mS,//Number of male students
        fS;//Number of male students
    float sum,//Total number of students
          mPct,//Percentage of male students
          fPct;//Percentage of female students
    
    //Initialize Variables   
    sum=0;   
    
    cout<<"Enter the number of male students registered in class: ";
    cin>>mS;
    sum+=mS;
    cout<<"Enter the number of female students registered in class: ";
    cin>>fS;
    sum+=fS;
    
    //Process/Map inputs to outputs
    mPct=mS/sum*100;//Percentage of male students in a class
    fPct=fS/sum*100;//Percentage of female students in a class
    
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint
        <<"The class is comprised of "
        <<mPct<<"% males and "<<fPct<<"% females.\n";
    
    //Exit stage right!
    return 0;
}