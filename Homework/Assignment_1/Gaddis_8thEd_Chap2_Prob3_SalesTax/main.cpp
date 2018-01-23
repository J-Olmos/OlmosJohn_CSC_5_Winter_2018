/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 5, 2018, 11:09 PM
 * Purpose: Calculate sales tax
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
    float ttl,//Total Sale in USD
          stax,//State sales tax
          ctax,//County sales tax
          ttltax;//Total sales tax in USD
    
    //Initialize Variables
    ttl=95.00;//total purchase
    stax=.04;//4% state tax
    ctax=.02;//2% county tax
    
    //Process/Map Inputs to Outputs
    ttltax=ttl*(stax+ctax);
  
    //Output Data
    cout<<"Total purchase was $"<<ttl<<endl
        <<"Total sales tax was $"<<ttltax<<" (6%)\n";
    
    //Exit Stage Right
    return 0;
}

