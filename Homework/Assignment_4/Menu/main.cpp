/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on 01/30/2018 3:15PM
 * Purpose: Assignment 4 Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants Only!

//Function Prototypes
void Menu();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set a Random number seed here.
    
    //Declare Main variables here.
    int inN;
    
    //Loop on each problem
    do{
        Menu();
        cin>>inN;
        switch(inN){
            case 1:  problem1();break;
            case 2:  problem2();break;
            case 3:  problem3();break;
            case 4:  problem4();break;
            case 5:  problem5();break;
            case 6:  problem6();break;
            case 7:  problem7();break;
            case 8:  problem8();break;
            case 9:  problem9();break;
            case 10: problem10();break;
            default:   def(inN);
	}
    }while(inN>=1&&inN<=10);

    //Exit Stage Right Here!
    return 0;
}

void Menu(){
    cout<<endl
        <<"Type  1 for: Gaddis 8thEd Prob01 - Sum of Numbers\n"
        <<"Type  2 for: Gaddis 8thEd Prob03 - Ocean Levels\n"
        <<"Type  3 for: Gaddis 8thEd Prob04 - Calories Burned\n"
        <<"Type  4 for: Gaddis 8thEd Prob05 - Membership Fees\n"
        <<"Type  5 for: Gaddis 8thEd Prob06 - Distance Traveled\n"
        <<"Type  6 for: Gaddis 8thEd Prob07 - Pennies for Pay\n"
        <<"Type  7 for: Gaddis 8thEd Prob09 - Hotel Occupancy\n"
        <<"Type  8 for: Gaddis 8thEd Prob10 - Average Rainfall\n"
        <<"Type  9 for: Gaddis 8thEd Prob12 - Celsius to Fahrenheit\n"
        <<"Type 10 for: Gaddis 8thEd Prob13 - Greatest and Least\n"
        <<"Or type anything else to exit.\n"
        <<"\nProblem: ";
}

void def(int inN){
    cout<<endl<<"Typing "<<inN<<" exits the program."<<endl;
}

void problem1(){
    //Declare Variables
    int n,sum;    
    
    //Initialize Variables
    cout<<"Enter a positive integer: ";
    cin>>n;
    
    if(n<=0){
        cout<<"\nInvalid input.\n"
            <<"Enter a positive integer: ";
        cin>>n;
    }
    
    //Process/Map inputs to outputs
    sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    
    //Output data
    cout<<"\nThe sum of all integers from 1 to "<<n<<" = "<<sum<<endl;
}

void problem2(){
    //Declare/Initialize Variables 
    int year=25;
    float rise=0;
    
    //Output Header 
    cout<<"This table displays the number of millimeters the\n"
        <<"ocean will have risen each year for the next 25 years.\n\n";
    
    //Process/Output table
    cout<<"Year   Increase\n"
        <<"---------------\n";
    for(int i=1;i<=year;i++){
        rise+=1.5f;
        cout<<setw(3)<<i
            <<fixed<<setprecision(1)
            <<setw(9)<<rise<<"mm\n";
        }
}

void problem3(){
    //Declare/Initialize Variables 
    int time=6;//Time in 5min intervals (5x6=30 min total)
    int burn=0;//Calories burned every 5min
    
    //Output Header
    cout<<"Total calories burned over time given a rate of\n"
        <<"3.6 calories per minute burned on a treadmill.\n\n";
    
    //Process/Output Table
    cout<<"Time        Total Burned\n"
        <<"------------------------\n";
    for(int i=1;i<=time;i++){
        burn+=18;//3.6x5=18cal/5min
        cout<<setw(2)<<i*5<<" minutes"
            <<setw(5)<<burn<<" calories\n";
        }
}

void problem4(){
    //Declare Variables 
    float cost,inc;
    int time;
    
    //Initialize Variables
    time=6;//Total time in years
    cost=2500.00f;//Membership cost
    inc=.04;//4% annual increase
    
    //Output Header
    cout<<"Projected membership cost for the next\n"
        <<"6 years with a 4% increase per year.\n\n";
    
    //Process/Output table
    cout<<"Year  Membership fee\n"
        <<"--------------------\n";
    for(int i=1;i<=time;i++){
        cost=cost*(1+inc);//Annual increase
        cout<<setw(3)<<i
            <<fixed<<setprecision(2)
            <<setw(5)<<"$"<<cost<<endl;
        }
}

void problem5(){
    //Declare Variables 
    float time,speed,dist;
    
    //Output header
    cout<<"This program calculates the distance a vehicle\n"
        <<"has traveled for each hour in a time period.\n\n";
    
    //Initialize Variables
    cout<<"What is the speed of the vehicle in mph? ";
    cin>>speed;
    cout<<"How many hours has it traveled? ";
    cin>>time;
    
    //Output data
    cout<<"\nHour  Distance Traveled\n"
        <<"-------------------------\n";
    for(int i=1;i<=time;i++){
        dist=speed*i;//Annual increase
        cout<<setw(3)<<i
            <<setw(11)<<dist<<" miles\n";
        }
}

void problem6(){
    //Declare Variables 
    float pay,sum;
    int time;
    
    //Initialize Variables
    pay=0.01f;
    sum=0;
    cout<<"This program calculates salary and pay\n"
        <<"based on the number of days worked.\n\n"
        <<"Enter an integer for days worked: ";
    cin>>time;
    
    //Input validation
    if(time<1){
        cout<<"\nError, days worked cannot be <1.\n"
            <<"Enter an integer for days worked: ";
        cin>>time;
    }
    
    //Output data
    cout<<"\nDay   Salary\n"
        <<"------------\n";
    for(int i=1;i<=time;i++){
        sum+=pay;
        cout<<setw(3)<<i
            <<fixed<<setprecision(2)
            <<setw(5)<<"$"<<pay<<endl;
        pay=pay*2;
        }
    cout<<"Total earned = $"<<sum<<endl;
}

void problem7(){
    //Declare Variables
    int floor,rms,occ,vac,tR,tO,tV;
    
    //Initialize Variables
    tR=tO=tV=0;
    cout<<"This program calculates the\n"
        <<"occupancy rate for a hotel.\n\n"
        <<"How many floors does the hotel have? ";
    cin>>floor;
    
    //Input validation
    if(floor<1){
        cout<<"\nNumber of floors cannot be <1.\n"
            <<"How many floors does the hotel have? ";
        cin>>floor;
    }
    
    //Process/Map inputs to outputs
    for(int i=1;i<=floor;i++){
        rms=occ=vac=0;
        if(i==13){i++;}
        cout<<"How many rooms are on floor "<<i<<"? ";
        cin>>rms;
        //Input validation
        if(rms<10){
            cout<<"\nNumber of rooms cannot be <10.\n"
                <<"How many rooms are on floor "<<i<<"? ";
            cin>>rms;
        }
        cout<<"How many of them are occupied? ";
        cin>>occ;
        vac=rms-occ;
        tV+=vac;
        tO+=occ;
        tR+=rms;
    } 
    
    //Output data
    cout<<"\nTotal hotel rooms: "<<tR
        <<"\nOccupied rooms   : "<<tO
        <<"\nUnoccupied rooms : "<<tV
        <<"\nPercent occupied : "
            <<fixed<<setprecision(2)
            <<100.0f*tO/tR<<"%\n";
}

void problem8(){
    //Declare Variables
    float rain,rT;
    int time;
    
    //Initialize Variables
    rain=rT=0;
    cout<<"This program calculates the\n"
        <<"average rainfall over time.\n\n"
        <<"Enter the number of years: ";
    cin>>time;
    
    //Input validation
    if(time<1){
        cout<<"Number of years must be >=1\n"
            <<"Enter the number of years: ";
        cin>>time;
    }
    
    //Process/Map inputs to outputs
    for(int i=1;i<=time;i++){
        for(int m=1;m<=12;m++){
            cout<<"Inches of rainfall for year "<<i<<" month "<<m<<": ";
            cin>>rain;
            if(rain<0){
                cout<<"Error, Rainfall must be >=0\n"
                    <<"Inches of rainfall for year "<<i<<" month "<<m<<": ";
                cin>>rain;
            }
            rT+=rain;
        }
    } 
    
    //Output data
    cout<<"\nNumber of months : "
            <<setw(3)<<time*12
        <<"\nTotal rainfall   : "
            <<setw(6)<<fixed<<setprecision(2)<<rT<<"in"
        <<"\nAverage rainfall : "
            <<setw(6)<<fixed<<setprecision(2)<<rT/(time*12)
            <<"in per month\n";
}

void problem9(){
    //Declare Variables
    float f;
    
    //Output Header
    cout<<"This program converts and displays\n"
        <<"degrees Celsius to Fahrenheit.\n\n";
    
    //Output table
    cout<<"Celsius  Fahrenheit\n"
        <<"-------------------\n";
    for(int c=0;c<=20;c++){
        f=c*9/5+32;//Annual increase
        cout<<setw(6)<<c
            <<setw(6)<<f<<endl;
    }
}

void problem10(){
    //Declare Variables
    int n,max,min;
    
    //Initialize Variables
    max=min=0;
    
    //Output Header
    cout<<"This program finds the largest and\n"
        <<"smallest out of the integers entered.\n\n";
    
    //Process/Map inputs to outputs
    cout<<"Enter a series of integers\n"
          "Type -99 to end the series: ";
    while(n!=-99){
        if(n>max){max=n;}
        if(n<min){min=n;}
        cin>>n;
        if(max==0){max=n;}
        if(min==0){min=n;}
    };
        
    //Output data
    cout<<"Largest number : "<<max<<endl
        <<"Smallest number: "<<min<<endl;
}