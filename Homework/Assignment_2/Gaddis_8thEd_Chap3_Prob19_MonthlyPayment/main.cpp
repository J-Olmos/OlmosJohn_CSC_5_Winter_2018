/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr & John Olmos
 * Created on January 9, 2018, 10:35 PM
 * Purpose:  Monthly payment
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float mP,//Monthly payment in USD
          tP,//Total loan amount
          iP,//Interest paid
          iR,//Interest rate per month
          ln,//Loan amount in USD
          n;//Number of monthly payments
    
    //Initialize Variables
    iR=.01;//Interest is set to 1%/month (12%/year) in decimal
    ln=10e3;//Loan amount is $10,000
    n=36;//Loan over 36 months
    
    //Process/Map inputs to outputs
    float var=pow(1+iR,n);//utility variable for (1+iR)^n
    mP=(var*iR*ln)/(var-1);
    int mPR=(mP+.005)*100;//Half penny round up then truncate
    mP=mPR/100.0;//Shift back right
    tP=mP*n;
    iP=tP-ln;
    
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint
        <<setw(23)<<left<<"Loan Amount:"<<"$"<<setw(9)<<right<<ln<<endl
        <<setw(23)<<left<<"Monthly interest rate:"<<setw(11)<<right<<"1%\n"
        <<setw(23)<<left<<"Number of payments:"<<setw(11)<<right<<"36\n"
        <<setw(23)<<left<<"Monthly payment:"<<"$"<<setw(9)<<right<<mP<<endl
        <<setw(23)<<left<<"Amount Paid Back:"<<"$"<<setw(9)<<right<<tP<<endl
        <<setw(23)<<left<<"Interest Paid:"<<"$"<<setw(9)<<right<<iP<<endl;
    
    //Exit stage right!
    return 0;
}