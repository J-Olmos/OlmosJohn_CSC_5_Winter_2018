/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on January 16, 2018, 3:20 PM
 * Purpose: Assignment 3 Menu and projects
 */

//System Libraries
#include <iostream>
#include <cstdlib> //Random number generator
#include <ctime>   //Time library for random seed
#include <iomanip> //Format library
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
    cout<<"Choose from the following menu:\n";
    cout<<"Problem 1 -> Gaddis_8thEd_Chap4_Prob01_Min/Max\n";
    cout<<"Problem 2 -> Gaddis_8thEd_Chap4_Prob02_RomanNumeralConversion\n";
    cout<<"Problem 3 -> Gaddis_8thEd_Chap4_Prob03_MagicDates\n";
    cout<<"Problem 4 -> Gaddis_8thEd_Chap4_Prob04_AreasOfRectangles\n";
    cout<<"Problem 5 -> Gaddis_8thEd_Chap4_Prob05_BMI\n";
    cout<<"Problem 6 -> Gaddis_8thEd_Chap4_Prob06_MassWeight\n";
    cout<<"Problem 7 -> Gaddis_8thEd_Chap4_Prob07_TimeCalculator\n";
    cout<<"Problem 8 -> Gaddis_8thEd_Chap4_Prob08_PaintMixer\n";
    cout<<"Problem 9 -> Gaddis_8thEd_Chap4_Prob11_MathTutor\n";
    cout<<"Type 1 to 9 only:\n";
    cout<<"\nProblem ";
    cin>>probNum;
    
    //Output the results
    switch(probNum){
        case 1: {     
            //Declare Variables
            float num1,//First number
                  num2;//Second number

            //Initialize Variables
            cout<<"This program takes two numbers and determines\n"
                <<"which is smaller and which is larger.\n";
            cout<<"Please enter two numbers:\n";
            cin>>num1>>num2;

            //Output Data
            num1==num2?//Check if numbers are equal first
                cout<<"\nThe numbers are equal\n":
                cout<<"\nThe smaller number is: "<<(num1<num2?num1:num2)
                    <<"\nThe larger number is: "<<(num1>num2?num1:num2)
                    <<endl;
            break;
        }
        case 2: {
            //Declare Variables
            unsigned short num;//Number to convert

            //Initialize Variables
            cout<<"This is a Roman numeral converter.\n";
            cout<<"Enter a number from 1 to 9: ";
            cin>>num;

            //Output Data
            switch(num){
                case 1:cout<<"\n1 = Roman numeral I\n";break;
                case 2:cout<<"\n2 = Roman numeral II\n";break;
                case 3:cout<<"\n3 = Roman numeral III\n";break;
                case 4:cout<<"\n4 = Roman numeral IV\n";break;
                case 5:cout<<"\n5 = Roman numeral V\n";break;
                case 6:cout<<"\n6 = Roman numeral VI\n";break;
                case 7:cout<<"\n7 = Roman numeral VII\n";break;
                case 8:cout<<"\n8 = Roman numeral VIII\n";break;
                case 9:cout<<"\n9 = Roman numeral IX\n";break;
                case 10:cout<<"\n10 = Roman numeral X\n";break;        
                default:cout<<"\nInvalid input, exiting program.\n";
            }
            break;
        }
        case 3: {
            //Declare Variables
            unsigned short day,
                           mon,//Month in number
                           year,//Two digit year
                           mYear;//Magic year

            //Initialize Variables
            cout<<"This program checks if a date is magic.\n";
            cout<<"Enter a day (1-31): ";
            cin>>day;            
            cout<<"Enter a month (1-12): ";
            cin>>mon;
            cout<<"Enter a two-digit year (00-99): ";
            cin>>year;
            
            //Error/exit if input is invalid
            if (day<=0||day>31||mon<=0||mon>12||year<0||year>99) {
                cout<<"\nError, one or more entry outside of range.\n"
                    <<"Exiting program.\n";
                break;
            }

            //Process/Map Inputs to Outputs
            mYear=day*mon; //Year is magic if it is equal to date*month

            //Output Data
            cout<<"\nThe date "<<day<<"/"<<mon<<"/"<<year
                <<(year==mYear?" is magic!\n":" is not magic.\n");
            break;
        }
        case 4: {
            //Declare Variables
            float l1,//length of rectangle 1
                  w1,//Width of rectangle 1
                  a1,//area of triangle 1
                  l2,//length of rectangle 2
                  w2,//Width of rectangle 2
                  a2;//area of rectangle 2

            //Initialize Variables
            cout<<"This program compares the area of two rectangles.\n";
            cout<<"All input values must be greater than 0.\n";
            cout<<"Enter numbers for the length and width of rectangle 1:\n";
            cin>>l1>>w1;
            cout<<"Enter numbers for the length and width of rectangle 2:\n";
            cin>>l2>>w2;
            
            //Error/exit if input is invalid
            if (l1<=0||w1<=0||l2<=0||w2<=0) {//Error if any input <=0
                cout<<"\nError, all inputs must be > 0.\nExiting program.\n";
                break;
            }
            
            //Process/Map Inputs to Outputs
            a1=l1*w1;//Area = Length*Width
            a2=l2*w2;//

            //Output Data
            (a1==a2)?
                cout<<"\nThe area for both rectangles is the same.\n":
                cout<<"\nRectangle "<<(a1>a2?"1":"2")
                    <<" has a greater area\n";
            break;
        }
        case 5: {
            //Declare Variables
            float wgt,//Weight in pounds
                  hgt,//Height in inches
                  bmi;//Body Mass Index

            //Initialize Variables
            cout<<"This program calculates BMI.\n";
            cout<<"Enter weight (in pounds): ";
            cin>>wgt;
            cout<<"Enter height (in inches): ";
            cin>>hgt;
            
            //Error/exit if input is invalid
            if (wgt<=0||hgt<=0) {
                cout<<"Numbers must be > 0, please run program again.\n";
                break;
            }            

            //Process/Map Inputs to Outputs
            bmi=wgt*703/(hgt*hgt); //BMI=Weight*703/Height^2

            //Output Data
            cout<<fixed<<setprecision(1)<<endl
                <<"A person with a BMI of "<<bmi;
                if(bmi>25)cout<<" is overweight.\n";
                else if(bmi<18.5)cout<<" is underweight.\n";
                else cout<<" has an optimal weight.\n";
            break;
        }
        case 6: {
            //Declare Variables
            float wgt,//Weight in kilograms
                  mass;//Mass in newtons

            //Initialize Variables
            cout<<"This program converts mass to weight.\n";
            cout<<"Enter object mass (in kilograms): ";
            cin>>mass;

            //Error/exit if input is invalid
            if (mass<=0) {
                cout<<"\nError, mass must be >0.\nExiting program.\n";
                break;
            }

            //Process/Map Inputs to Outputs
            wgt=mass*9.8; //Weight (in newtons)= mass*9.8

            //Output Data
            cout<<fixed<<setprecision(1)<<endl
                <<"Object weight = "<<wgt<<" newtons.\n";
                if(wgt>1000)cout<<"Object is too heavy.\n"
                                <<"Max weight is 1,000 newtons.\n";
                if(wgt<10)cout<<"Object is too light.\n"
                                 <<"Min weight is 10 newtons.\n";
            break;
        }
        case 7: {
            //Declare Variables
            int sec;//Time in seconds

            //Initialize Variables
            cout<<"This program converts the time\n";
            cout<<"depending on the number of seconds.\n";
            cout<<"Enter an integer grater than 0: ";
            cin>>sec;

            //Output Data
            cout<<endl;
            if (sec<=0)//Error if input <=0
                cout<<"Error, time must be > 0.\nExiting program.\n";
            else if(sec<60)//Displays seconds if < 60
                cout<<"Time entered = "<<sec<<" seconds.\n";
            else if(sec<3600)//Display minutes if >= 60 seconds    
                cout<<"There"<<(sec/60==1?" is ":" are ")<<sec/60
                    <<" minute(s) in "<<sec<<" seconds.\n";
            else if(sec<86400) //Display hours if >= 3,600 seconds  
                cout<<"There"<<(sec/3600==1?" is ":" are ")<<sec/3600
                    <<" hour(s) in "<<sec<<" seconds.\n";//Days if >= 86,400
            else cout<<"There"<<(sec/86400==1?" is ":" are ")<<sec/86400
                     <<" day(s) in "<<sec<<" seconds.\n";
            break;
        }
        case 8: {
            //Declare Variables
            string c1,//First primary color
                   c2;//second primary color

            //Initialize variables
            cout<<"This program displays the result\n";
            cout<<"of mixing two primary colors.\n";
            cout<<"Enter two primary colors (Red/Yellow/Blue):\n";
            cin>>c1>>c2;
            
            //Check first primary color, convert c1 to "x" if invalid
            ((c1=="YELLOW"||c1=="Yellow"||c1=="yellow")?c1="Yellow":
            (c1=="BLUE"||c1=="Blue"||c1=="blue")?c1="Blue":
            (c1=="RED"||c1=="Red"||c1=="red")?c1="Red":c1="x");
            //Check second primary color, convert c2 to "x" if invalid
            ((c2=="YELLOW"||c2=="Yellow"||c2=="yellow")?c2="Yellow":
            (c2=="BLUE"||c2=="Blue"||c2=="blue")?c2="Blue":
            (c2=="RED"||c2=="Red"||c2=="red")?c2="Red":c2="x");

            //Output Data
            (c1=="x"||c2=="x")?//Error message
                cout<<"\nError, enter Red, Yellow, or Blue only."
                    <<"\nExiting program.\n":
                cout<<"\nMixing "<<c1<<" and "<<c2<<" makes: "
                    <<(c1==c2?c1://Outputs color 1 if the same as color 2
                      (c1=="Red"||c2=="Red")&&(c1=="Yellow"||c2=="Yellow")?
                        "Orange\n"://Red+Yellow
                      (c1=="Red"||c2=="Red")&&(c1=="Blue"||c2=="Blue")?
                        "Purple\n"://Red+Blue
                        "Green\n");//Yellow+Blue
            break;
        }
        case 9: {
            //Declare Variables
            unsigned short op1,    //First random number
                           op2,    //Second random number
                           result, //Result obtained by program
                           answer; //Answer input by user

            //Set the random number seed
            srand(static_cast<unsigned int>(time(0)));

            //Initialize variables
            op1=rand()%900+100; //Three digit number
            op2=rand()%1000;    //Any 1-3 digit number

            //Process/map input to output
            result=op1+op2;

            //Output data
            cout<<"Test your addition skills,\nsolve the following:\n";
            cout<<setw(5)<<op1<<endl;
            cout<<"+ "<<setw(3)<<op2<<endl;
            cout<<"------"<<endl<<(result>1000?" ":"  ");
            cin>>answer;
            result==answer?//Congratulate if correct, otherwise show result
                cout<<"\nCorrect, you got the right answer!\n":
                cout<<"\nIncorrect, the answer is "<<result<<".\n"; 
            break;
        }
        default:cout<<"\nYou choose to exit\n";
        break;
    }
          
    //Exit stage right!
    return 0;
}