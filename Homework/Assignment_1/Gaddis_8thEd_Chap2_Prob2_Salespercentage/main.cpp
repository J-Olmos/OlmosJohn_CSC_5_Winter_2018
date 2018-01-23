/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 5, 2018, 11:00 PM
 * Purpose: Calculate team sales from total
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
    float tsale,//Total Sales
          ecsale,//East Coast Sales
          ecpct;//East Coast percentage out of total sales
    
    //Initialize Variables
    tsale=8.6;//total sales in millions of USD
    ecpct=.58;//East Coast sales are 58% of total sales
    
    //Process/Map Inputs to Outputs
    ecsale=tsale*ecpct;
  
    //Output Data
    cout<<"The company generated $"<<tsale<<" million in sales this year.\n"
        <<"The East Coast sales division generated 58% of total sales or $"
        <<ecsale<<" million.\n";
    
    //Exit Stage Right
    return 0;
}

