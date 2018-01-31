/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on 01/30/2018 3:15PM
 * Purpose: Assignment 4 Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
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
        <<"Type  3 for: Gaddis 8thEd Prob\n"
        <<"Type  4 for: Gaddis 8thEd Prob\n"
        <<"Type  5 for: Gaddis 8thEd Prob\n"
        <<"Type  6 for: Gaddis 8thEd Prob\n"
        <<"Type  7 for: Gaddis 8thEd Prob\n"
        <<"Type  8 for: Gaddis 8thEd Prob\n"
        <<"Type  9 for: Gaddis 8thEd Prob\n"
        <<"Type 10 for: Gaddis 8thEd Prob\n"
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
    cout<<"\nThe sum of integers from 1 to "<<n<<" = "<<sum<<endl;
}

void problem2(){
    //Declare/Initialize Variables 
    int year=25;
    float rise=0;
    
    //Output Header 
    cout<<"This table displays the number of millimeters the\n"
        <<"ocean will have risen each year for the next 25 years.\n\n"
        <<"Year   Increase\n"
        <<"---------------\n";
    
    //Output table
    for(int i=1;i<=year;i++){
        rise+=1.5f;
        cout<<setw(3)<<i
            <<fixed<<setprecision(1)
            <<setw(9)<<rise<<"mm\n";
        }
}

void problem3(){
    
}

void problem4(){
    
}

void problem5(){
    
}

void problem6(){
    
}

void problem7(){
    
}

void problem8(){
    
}

void problem9(){
    
}

void problem10(){
    
}