/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 5, 2018, 11:33 PM
 * Purpose: Calculate and display tax, tip, and total for a meal
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
    float meal,//meal cost in USD
          tax,//tax percentage
          ttax,//total tax in USD
          tip,//tip percentage
          ttip,//total tip in USD
          bill;//total bill in USD
    
    //Initialize Variables
    meal=88.67;//total meal charge
    tax=.0675;//6.75% tax
    tip=.2;//20% tip
    
    //Process/Map Inputs to Outputs
    ttax=meal*tax;
    ttip=(ttax+meal)*tip;
    bill=meal+ttax+ttip;
  
    //Output Data
    cout<<"Meal cost  $"<<meal<<endl
        <<"Tax        $"<<ttax<<endl
        <<"20% tip    $"<<ttip<<endl
        <<"Total bill $"<<bill<<endl;
    
    //Exit Stage Right
    return 0;
}

