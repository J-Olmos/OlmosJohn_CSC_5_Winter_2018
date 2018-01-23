/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 10, 2018, 9:43 PM
 * Purpose: Calculate box office
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
    string mov;//User defined name for each month
    int aT,//Adult tickets sold
        cT;//Child tickets sold
    float gP,//Gross box office profit in USD
          nP,//Net box office profit in USD
          dP;//Paid to distributor in USD
    
    //Initialize Variables   
    cout<<"Enter the name of the movie: ";
    getline(cin, mov);
    
    cout<<"Enter the number of adult tickets sold: ";
    cin>>aT;
    
    cout<<"Enter the number of child tickets sold: ";
    cin>>cT;
    
    //Process/Map inputs to outputs
    gP=aT*10.00+cT*6.00;//Ticket prices (Adult $10.00, Child $6.00)
    nP=gP*.2;//Box office net profit = 20% of gross profit
    dP=gP-nP;//Distributor receives remainder
    
    //Output data
    cout<<setw(29)<<left<<endl<<"Movie Name:"<<"\""<<mov<<"\"\n"
        <<setw(29)<<left<<"Adult Tickets Sold:"<<setw(10)<<right<<aT<<endl
        <<setw(29)<<left<<"Child Tickets Sold:"<<setw(10)<<right<<cT<<endl
        <<fixed<<setprecision(2)
        <<setw(29)<<left<<"Gross Box Office Profit:"
        <<"$"<<setw(9)<<right<<gP<<endl
        <<setw(29)<<left<<"Net Box Office Profit:"
        <<"$"<<setw(9)<<right<<nP<<endl
        <<setw(29)<<left<<"Amount Paid to Distributor:"
        <<"$"<<setw(9)<<right<<dP<<endl;
    
    //Exit stage right!
    return 0;
}