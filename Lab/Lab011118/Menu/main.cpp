/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr & John Olmos
 * Created on January 11, 2018, 1:15 PM
 * Purpose:  Validate the Truth Table
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
    int probNum;
    
    //Menu with input choices
    cout<<"Choose from the following menu:"<<endl;
    cout<<"Problem 1 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Problem 2 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Problem 3 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Problem 4 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Problem 5 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Problem 6 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Problem 7 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Problem 8 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Problem 9 -> Author_Edition_Chapter_Problem_Description:"<<endl;
    cout<<"Type 1 to 9 only"<<endl;
    cin>>probNum;
    
    //Output the results
    switch(probNum){
        case 1: {
            cout<<"Put problem 1 here"<<endl;break;
        }
        case 2: {
            cout<<"Put problem 2 here"<<endl;break;
        }
        case 3: {
            cout<<"Put problem 3 here"<<endl;break;
        }
        case 4: {
            cout<<"Put problem 4 here"<<endl;break;
        }
        case 5: {
            cout<<"Put problem 5 here"<<endl;break;
        }
        case 6: {
            cout<<"Put problem 6 here"<<endl;break;
        }
        case 7: {
            cout<<"Put problem 7 here"<<endl;break;
        }
        case 8: {
            cout<<"Put problem 8 here"<<endl;break;
        }
        case 9: {
            cout<<"Put problem 9 here"<<endl;break;
        }
        default:cout<<"You choose to exit"<<endl;break;
    }
    
        
    
    //Exit stage right!
    return 0;
}