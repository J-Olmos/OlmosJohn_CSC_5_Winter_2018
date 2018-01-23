/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 10, 2018, 10:59 PM
 * Purpose:  Adjust ingredients in a recipe
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
    float nC,//Number of cookies to be made
          sgr,//Cups of sugar needed
          btr,//Cups of butter needed
          flr;//Cups of flour needed          
    
    //Initialize Variables
    cout<<"Enter the number of cookies you wish to make: ";
    cin>>nC;
    
    //Process/Map inputs to outputs
    float pct=nC/48;//Used to changes values based on 48 cookie recipe
    sgr=1.5*pct;//1.5 cups of sugar needed for 48 cookies
    btr=1*pct;//1 cup of butter needed for 48 cookies
    flr=2.75*pct;//2.75 cups of flour needed for 48 cookies
    
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint
        <<"To make "<<nC<<" cookies you will need:\n"
        <<sgr<<" cup(s) of sugar\n"
        <<btr<<" cup(s) of butter\n"
        <<flr<<" cup(s) of flour\n";
    
    //Exit stage right!
    return 0;
}