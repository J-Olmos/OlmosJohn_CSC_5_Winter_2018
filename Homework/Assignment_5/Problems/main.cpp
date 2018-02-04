/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 2, 2018, 1:20 PM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
int searchL(int[],int,int);
int searchB(int[],int,int);
void selSort(int [],int);

//Execution Begins Here
int main(int argc, char** argv) {
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
    cout<<"This program checks if an\n"
        <<"account number is valid.\n\n"
        <<"Enter a 7 digit account number: ";
    cin>>id;        
    check=searchB(accts,SIZE,id);            
        
    //Output data
    cout<<endl<<"The number is "
        <<(check==-1?"invalid\n":"valid\n");
        
    //Exit stage right!
    return 0;
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