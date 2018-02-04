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
void problem11();
void problem12();
void cRetail(float,float);
float gSales(float &);
void fHigh(float &,float &,float &,float &);
int gNumAcc(int &);
void fLow(int &,int &,int &,int &,int &);
float fallDist(float);
int searchL(int[],int,int);
int searchB(int[],int,int);
void selSort(int [],int);

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
            case 11: problem11();break;
            case 12: problem12();break;
            default:   def(inN);
	}
    }while(inN>=1&&inN<=12);

    //Exit Stage Right Here!
    return 0;
}

void Menu(){
    cout<<endl
        <<"Type  1 for: Gaddis 8thEd Chap6 Prob01 - Markup\n"
        <<"Type  2 for: Gaddis 8thEd Chap6 Prob03 - Winning Division\n"
        <<"Type  3 for: Gaddis 8thEd Chap6 Prob04 - Safest Driving Area\n"
        <<"Type  4 for: Gaddis 8thEd Chap6 Prob05 - Falling Distance\n"
        <<"Type  5 for: Gaddis 8thEd Chap7 Prob01 - Largest/Smallest array\n"
        <<"Type  6 for: Gaddis 8thEd Chap7 Prob02 - Rainfall Statistics\n"
        <<"Type  7 for: Gaddis 8thEd Chap7 Prob09 - Payroll\n"
        <<"Type  8 for: Gaddis 8thEd Chap7 Prob12 - Grade Book\n"
        <<"Type  9 for: Gaddis 8thEd Chap8 Prob01 - Account Validation\n"
        <<"Type 10 for: Gaddis 8thEd Chap8 Prob02 - Lottery Winners\n"
        <<"Type 11 for: Gaddis 8thEd Chap8 Prob03 - Lottery Winners Mod\n"
        <<"Type 12 for: Gaddis 8thEd Chap8 Prob04 - Account Validation Mod\n"
        <<"Or type anything else to exit.\n"
        <<"\nProblem: ";
}

void def(int inN){
    cout<<endl<<"Typing "<<inN<<" exits the program."<<endl;
}

void problem1(){
    //Declare Variables
    float c,m;
    
    //Initialize Variables
    cout<<"This program calculates retail price.\n";
    c=m=-1;
    while(c<0){
        cout<<"Enter wholesale cost in USD: ";
        cin>>c;
        if(c<0)cout<<"\nPrice cannot be negative.\n";
    }
    while(m<0){
        cout<<"Enter markup (ex 50 for 50%: ";
        cin>>m;
        if(m<0)cout<<"\nMarkup cannot be negative.\n";
    }
    
    //Output data 
    cRetail(c,m);   
}

void problem2(){
    //Declare Variables
    float nw,ne,sw,se;
    
    //Initialize Variables
    cout<<"This program determines which region in\n"
        <<"a company has the highest sales figure.\n\n";
    cout<<"\nNorthwest\n";
    gSales(nw);
    cout<<"\nNortheast\n";
    gSales(ne);
    cout<<"\nSouthwest\n";
    gSales(sw);
    cout<<"\nSoutheast\n";
    gSales(se);
    
    //Output data 
    fHigh(nw,ne,sw,se);
}

void problem3(){
    //Declare Variables
    int nr,sr,er,wr,cr;
    
    //Initialize Variables
    cout<<"This program determines which region in a\n"
        <<"city had the fewest accidents last year.\n";
    
    cout<<"\nNorth Region\n";
    gNumAcc(nr);
    cout<<"\nSouth Region\n";
    gNumAcc(sr);
    cout<<"\nEast Region\n";
    gNumAcc(er);
    cout<<"\nNorth Region\n";
    gNumAcc(wr);
    cout<<"\nNorth Region\n";
    gNumAcc(cr);
    
    //Output data 
    fLow(nr,sr,er,wr,cr);
}

void problem4(){
    //Declare Variables
    float sec;
    
    //Initialize Variables
    cout<<"This program claculates the distance\n"
        <<"an object falls in a specific time.\n\n";
    sec=10;
    
    //Output data
    cout<<"  Time       Distance\n"
        <<"(Seconds)    (Meters)\n";
    for(int i=1;i<=sec;i++){
        cout<<setw(5)<<i<<fixed<<setprecision(1)
            <<setw(15)<<fallDist(i)<<endl;
    }    
}

void problem5(){
    //Declare Variables
    int min,max;
    
    //Initialize Variables
    const int SIZE=10;
    int num[SIZE];
    cout<<"This program takes in 10 numbers\n"
        <<"and finds the largest & smallest.\n\n"
        <<"Enter a number: ";
    cin>>num[1];
    min=max=num[1];
    
    //Process/Map inputs to outputs
    for(int i=2;i<=SIZE;i++){
        cout<<"Enter another number: ";
        cin>>num[i];
        if(num[i]<min)min=num[i];
        if(num[i]>max)max=num[i];
    }
        
    //Output data 
    cout<<"\nSmallest number: "<<min
        <<"\nLargest number : "<<max<<endl;
}

void problem6(){
    //Declare Variables
    float min,max,sum;
    int lM,hM;
    
    //Initialize Variables
    const int SIZE=12;
    float num[SIZE];
    max=min=sum=0;
    lM=hM=1;
    cout<<"This program generates rainfall\n"
        <<"statistics using monthly values.\n\n";
    
    //Process/Map inputs to outputs
    for(int i=1;i<=SIZE;i++){
        do{
            cout<<"Month "<<i<<" Rainfall (in): ";
            cin>>num[i];
        }while(num<0);
        if(i==1)max=min=num[i];
        if(num[i]<min){min=num[i];lM=i;}
        if(num[i]>max){max=num[i];hM=i;}
        sum+=num[i];
    }
        
    //Output data 
    cout<<"\nTotal Rainfall   : "<<sum
        <<"\nMonthly Average  : "<<sum/12
        <<"\nHighest Rainfall : Month "<<hM
        <<"\nLowest Rainfall  : Month "<<lM<<endl;
}

void problem7(){
    //Declare Variables
    const int SIZE=7;
    int hours[SIZE];
    float payRate[SIZE];
    float wages[SIZE];
    
    
    //Initialize Variables
    int empId[SIZE]={5658845, 4520125, 7895122, 8777541, 
                     8451277, 1302850, 7580489};

    cout<<"This program calculates and displays\n"
        <<"employee gross wages per week in USD.\n\n";
    
    //Process/Map inputs to outputs
    for(int i=0;i<SIZE;i++){
        cout<<"Employee ID: "<<empId[i]<<endl;
        do{
            cout<<"Enter hours worked  per week: ";
            cin>>hours[i];
            if(hours[i]<0){cout<<"Hours must be > 0\n";}
        }while(hours[i]<0);
        do{
            cout<<"Enter hourly pay rate (in $): ";
            cin>>payRate[i];
            if(payRate[i]<15){cout<<"Pay must be > $15.00\n";}
        }while(payRate[i]<15);
        wages[i]=hours[i]*payRate[i];
    }
        
    //Output data 
    cout<<"\nEmployee   Gross Wages\n"
        <<"----------------------\n";
    for(int i=0;i<SIZE;i++){
        cout<<empId[i]<<setw(5)<<"$"
            <<fixed<<setprecision(2)
            <<setw(10)<<wages[i]<<endl;
    }
}

void problem8(){
    //Declare Variables
    const int SIZE=5;
    const int TESTS=4;
    string name[SIZE];
    char grade[SIZE];
    float score[SIZE][TESTS];
    float sum[SIZE];
    float avg[SIZE];
    
    //Initialize Variables
    cout<<"This program calculates a student's\n"
        <<"average test score and final grade.\n\n";
    
    //Process/Map inputs to outputs
    for(int i=0;i<SIZE;i++){
        sum[i]=0;
        cout<<"Enter student's first name: ";
        cin>>name[i];
        for(int s=0;s<TESTS;s++){
        score[i][s]=0;
            do{
                cout<<"Enter test "<<s+1<<" score: ";
                cin>>score[i][s];
                if(score[i][s]<0||score[i][s]>100){
                    cout<<"Score must be from 0-100\n";
                }
                sum[i]+=score[i][s];
            }while(score[i][s]<0||score[i][s]>100);  
        }
    }
    
    for(int i=0;i<SIZE;i++){
        avg[i]=sum[i]/4;
        avg[i]>89?grade[i]='A':
        avg[i]>79?grade[i]='B':
        avg[i]>69?grade[i]='C':
        avg[i]>59?grade[i]='D':
                  grade[i]='F';
    }
        
    //Output data
    cout<<"\nName     Average  Grade\n";
    for(int i=0;i<SIZE;i++){
        cout<<fixed<<setprecision(1)
            <<setw(11)<<left<<name[i]
            <<setw(9)<<avg[i]
            <<grade[i]<<endl;
    }
}

void problem9(){
    //Declare Variables
    const int SIZE=18;
    int check,id;
    
    //Initialize Variables
    check=0;
    int accts[SIZE]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 
                     8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 
                     1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    
    //Process/Map inputs to outputs
    cout<<"This program checks if an\n"
        <<"account number is valid.\n\n"
        <<"Enter a 7 digit account number: ";
    cin>>id;        
    check=searchL(accts,SIZE,id);            
        
    //Output data
    cout<<endl<<"The number is "
        <<(check==-1?"invalid\n":"valid\n");
}

void problem10(){
    //Declare Variables
    const int SIZE=10;
    int check,win;
    
    //Initialize Variables
    int picks[SIZE]={13579, 26791, 26792, 33445, 55555,
                     62483, 77777, 79422, 85647, 93121};
    
    //Process/Map inputs to outputs
    cout<<"Linear Search\n"
        <<"This program checks if the winning lotto\n"
        <<"number matches a set of ticket numbers.\n\n"
        <<"Enter this week's winning 5-digit number: ";
    cin>>win;        
    check=searchL(picks,SIZE,win);            
        
    //Output data
    cout<<endl<<"You do"
        <<(check==-1?" not ":" ")
        <<"have a winning lotto ticket\n";
}

void problem11(){
    //Declare Variables
    const int SIZE=10;
    int check,win;
    
    //Initialize Variables
    int picks[SIZE]={13579, 26791, 26792, 33445, 55555,
                     62483, 77777, 79422, 85647, 93121};
    
    //Process/Map inputs to outputs
    cout<<"Binary Search\n"
        <<"This program checks if the winning lotto\n"
        <<"number matches a set of ticket numbers.\n\n"
        <<"Enter this week's winning 5-digit number: ";
    cin>>win;        
    check=searchB(picks,SIZE,win);            
        
    //Output data
    cout<<endl<<"You do"
        <<(check==-1?" not ":" ")
        <<"have a winning lotto ticket\n";
}

void problem12(){
    //Declare Variables
    const int SIZE=18;
    int check,id;
    
    //Initialize Variables
    check=0;
    int accts[SIZE]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 
                     8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 
                     1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    
    //Select Sort
    selSort(accts,SIZE);
    
    //Process/Map inputs to outputs
    cout<<"Sort and binary search"
        <<"This program checks if an\n"
        <<"account number is valid\n\n"
        <<"Enter a 7 digit account number: ";
    cin>>id;        
    check=searchB(accts,SIZE,id);            
        
    //Output data
    cout<<endl<<"The number is "
        <<(check==-1?"invalid\n":"valid\n");
}

void cRetail(float c,float m){
    cout<<fixed<<setprecision(2)<<showpoint<<endl
        <<"Retail price = $"<<(c*(m/100+1))<<endl;
}

float gSales(float &sale){
    sale=-1;
    while(sale<0){
        cout<<"Enter sales figure: $";
        cin>>sale;
        if(sale<0)cout<<"\nSales cannot be negative.\n";
    }
}

void fHigh(float &r1,float &r2,float &r3,float &r4){
    float max=r1;
    if (r2>max)max=r2;
    if (r3>max)max=r3;
    if (r4>max)max=r4;
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    if (r1==max){cout<<"Winner: Northwest division with $"<<max<<endl;}
    if (r2==max){cout<<"Winner: Northeast division with $"<<max<<endl;}
    if (r3==max){cout<<"Winner: Southwest division with $"<<max<<endl;}
    if (r4==max){cout<<"Winner: Southeast division with $"<<max<<endl;}
}

int gNumAcc(int &num){
    num=-1;
    while(num<0){
        cout<<"Enter the number of accidents: ";
        cin>>num;
        if(num<0)cout<<"\nNumber of crashes cannot be negative.\n";
    }
}

void fLow(int &r1,int &r2,int &r3,int &r4,int &r5){
    int min=r1;
    if (r2<min)min=r2;
    if (r3<min)min=r3;
    if (r4<min)min=r4;
    if (r5<min)min=r5;
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    if (r1==min){cout<<"Lowest: North region with "<<min<<" accidents\n";}
    if (r2==min){cout<<"Lowest: South region with "<<min<<" accidents\n";}
    if (r3==min){cout<<"Lowest: East region with "<<min<<" accidents\n";}
    if (r4==min){cout<<"Lowest: West region with "<<min<<" accidents\n";}
    if (r5==min){cout<<"Lowest: Central region with "<<min<<" accidents\n";}
}

float fallDist(float i){
    float d=1.0f/2*9.8*i*i;
    return d;
}

int searchL(int a[],int n,int val){
    for(int i=0;i<n;i++){
        if(val==a[i])return i;
    }
    return -1;
}

int searchB(int a[],int n,int val){
    //Declare start/end with mid
    int bRng=0;
    int eRng=n-1;
    //Loop until found
    while(bRng<=eRng){
        int mid=(bRng+eRng)/2;
        if(a[mid]==val)return mid;
        else if (a[mid]>val)eRng=mid-1;
        else bRng=mid+1;
    }
    return -1;
}

void  selSort(int a[],int n){
    int mI,mV;
    for(int scan=0;scan<n-1;scan++){
        mI=scan;
        mV=a[scan];
        for(int i=scan+1;i<n;i++){
            if(a[i]<mV){
                mV=a[i];
                mI=i;
            }
        }
        a[mI]=a[scan];
        a[scan]=mV;
    }
}