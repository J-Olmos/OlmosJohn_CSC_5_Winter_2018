/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 10, 2018, 1:03 PM
 * Purpose: Calculate test average
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
    float score,//Individual test scores
          ttl,//Total sum of all scores
          avg;//Average test score
    
    //Initialize Variables   
    ttl=0;   
    
    cout<<"Enter 5 test scores:\n";
    cin>>score;//Test 1  
    ttl+=score;
    
    cin>>score;//Test 2  
    ttl+=score;
    
    cin>>score;//Test 3
    ttl+=score;
    
    cin>>score;//Test 4
    ttl+=score;
    
    cin>>score;//Test 5
    ttl+=score;
    
    //Process/Map inputs to outputs
    avg=ttl/5;
    
    //Output data
    cout<<fixed<<setprecision(1)<<showpoint
        <<"The average test score is "<<avg<<endl;
    
    //Exit stage right!
    return 0;
}