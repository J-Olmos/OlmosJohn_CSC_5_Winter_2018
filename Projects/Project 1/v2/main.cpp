/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on Jan 30, 2018, 12:06 AM
 * Purpose: Simple Battleship
 */

//System Libraries Here
#include <iostream>  //Input - Output Library
#include <ctime>     //Time for rand
#include <cstdlib>   //Srand to set the seed
#include <fstream>   //File I/O
#include <iomanip>   //Format the output
#include <string>    //Strings
#include <cmath>     //Math functions
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    ifstream in;               //Input File
    ofstream out;              //Output File
    bool cB1,cB2,cB3,cB4,cB5,cB6,cB7,cB8,cB9,cB10,
         uB1,uB2,uB3,uB4,uB5,uB6,uB7,uB8,uB9,uB10;
    char c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,
         u1,u2,u3,u4,u5,u6,u7,u8,u9,u10;
    unsigned short cB;
    int cHits,uHits,rnds;
    char conf,uB;
    string guess;
    int cGuess;
    int width;
    
    //Input or initialize values Here
    string inName="GameInfo.dat";   //String Name
    char outName[]="GameStats.dat"; //Character Array Name
    in.open(inName.c_str());        //Open the Input file
    out.open(outName);              //Open the Output file
    while(in>>width); //Last value in file becomes the width
    cB1=cB2=cB3=cB4=cB5=cB6=cB7=cB8=cB9=cB10=false;
    c1=c2=c3=c4=c5=c6=c7=c8=c9=c10='?';
    cHits=uHits=rnds=0;
    conf='n';
    
    //Output instructions
    cout<<"This is a simple game of Battleship.\n"
        <<"Both you and the computer will place a\n"
        <<"battleship 4 units long on the board.\n";
    
    while(conf!='y'){
        uB1=uB2=uB3=uB4=uB5=uB6=uB7=uB8=uB9=uB10=false;
        u1=u2=u3=u4=u5=u6=u7=u8=u9=u10=' ';
        
        cout<<"\nStart the game by placing your battleship\n"
            <<"Please enter a number from 1-7: ";
        cin>>uB;
        
        //Input validation
        if(uB<48||uB>55){
            cout<<"\nInvalid input, please try again.\n";
        }
        
        //Set user battleship location
        else{            
            if(uB==49){uB1=uB2=uB3=uB4=true;u1=u2=u3=u4='B';}
            else if(uB==50){uB2=uB3=uB4=uB5=true;u2=u3=u4=u5='B';}
            else if(uB==51){uB3=uB4=uB5=uB6=true;u3=u4=u5=u6='B';}
            else if(uB==52){uB4=uB5=uB6=uB7=true;u4=u5=u6=u7='B';}
            else if(uB==53){uB5=uB6=uB7=uB8=true;u5=u6=u7=u8='B';}
            else if(uB==54){uB6=uB7=uB8=uB9=true;u6=u7=u8=u9='B';}
            else {uB7=uB8=uB9=uB10=true;u7=u8=u9=u10='B';}
            
            //Output User Header
            cout<<"\nDefensive Board\n";
            for(int i=1;i<=width;i++){
                cout<<setw(3)<<"---";
            }cout<<endl;
            for(int i=1;i<=width;i++){
                cout<<setw(3)<<i;
            }cout<<endl;

            //Output User Grid
            cout<<setw(3)<<u1<<setw(3)<<u2<<setw(3)<<u3<<setw(3)<<u4
                <<setw(3)<<u5<<setw(3)<<u6<<setw(3)<<u7<<setw(3)<<u8
                <<setw(3)<<u9<<setw(3)<<u10<<endl<<endl;

            //Confirmation
            cout<<"Confirm battleship placement? (y/n): ";
            cin>>conf;
        }
    };
    
    //Set computer battleship location
    //Generate starting point from 1-7
    cB=rand()%7+1;//[1,7]
    //Place computer battleship
    switch(cB){
        case 1:cB1=cB2=cB3=cB4=true;break;
        case 2:cB2=cB3=cB4=cB5=true;break;
        case 3:cB3=cB4=cB5=cB6=true;break;
        case 4:cB4=cB5=cB6=cB7=true;break;
        case 5:cB5=cB6=cB7=cB8=true;break;
        case 6:cB6=cB7=cB8=cB9=true;break;
        case 7:cB7=cB8=cB9=cB10=true;break;
    }
    
    //Output Header
    cout<<"\n***********************************************"
        <<"\nAll battleships have now been set.\n"
        <<"Try and hit and sink the enemy's battleship\n"
        <<"by hitting all 4 spots before it can sink you.\n"
        <<"[? = Unknown] [0 = Misses] [X = Hits]\n"
        <<"***********************************************\n\n"
    ;
    //Play Game
    int beg=time(0);//Time the game play
    do{
        //User Guess
        cout<<"Enter a number from 1-10: ";
        cin>>guess;

        //Input validation
        if(guess!="1"&&guess!="2"&&guess!="3"&&guess!="4"&&guess!="5"&&
           guess!="6"&&guess!="7"&&guess!="8"&&guess!="9"&&guess!="10"){
            cout<<"\nInvalid input, please try again.\n";
        }        

        else {
            //Computer's turn
            do{
                //Computer Guess
                cGuess=rand()%10+1;

                //Computer Guess result
                if(cGuess==1){
                    (u1=='X'||u1=='O')?cGuess=0:
                    (uB1)?u1='X',cHits++:u1='O';
                }
                else if(cGuess==2){
                    (u2=='X'||u2=='O')?cGuess=0:
                    (uB2)?u2='X',cHits++:u2='O';
                }
                else if(cGuess==3){
                    (u3=='X'||u3=='O')?cGuess=0:
                    (uB3)?u3='X',cHits++:u3='O';
                }
                else if(cGuess==4){
                    (u4=='X'||u4=='O')?cGuess=0:
                    (uB4)?u4='X',cHits++:u4='O';
                }
                else if(cGuess==5){
                    (u5=='X'||u5=='O')?cGuess=0:
                    (uB5)?u5='X',cHits++:u5='O';
                }
                else if(cGuess==6){
                    (u6=='X'||u6=='O')?cGuess=0:
                    (uB6)?u6='X',cHits++:u6='O';
                }
                else if(cGuess==7){
                    (u7=='X'||u7=='O')?cGuess=0:
                    (uB7)?u7='X',cHits++:u7='O';
                }
                else if(cGuess==8){
                    (u8=='X'||u8=='O')?cGuess=0:
                    (uB8)?u8='X',cHits++:u8='O';
                }
                else if(cGuess==9){
                    (u9=='X'||u9=='O')?cGuess=0:
                    (uB9)?u9='X',cHits++:u9='O';
                }
                else{
                    (u10=='X'||u10=='O')?cGuess=0:
                    (uB10)?u10='X',cHits++:u10='O';
                }
            }while(cGuess==0);
            
            //User Guess Result
            switch(cB){
                case 1:(cB1)?c1='X',uHits++:c1='O';break;
                case 2:(cB2)?c2='X',uHits++:c2='O';break;
                case 3:(cB3)?c3='X',uHits++:c3='O';break;
                case 4:(cB4)?c4='X',uHits++:c4='O';break;
                case 5:(cB5)?c5='X',uHits++:c5='O';break;
                case 6:(cB6)?c6='X',uHits++:c6='O';break;
                case 7:(cB7)?c7='X',uHits++:c7='O';break;
                case 8:(cB8)?c8='X',uHits++:c8='O';break;
                case 9:(cB9)?c9='X',uHits++:c9='O';break;
                case 10:(cB10)?c10='X',uHits++:c10='O';break;
            }
            
            //Output Computer and Player Guesses
            cout<<"\nEnemy guessed : "<<cGuess<<endl;
            cout<<"You guessed   : "<<guess<<endl;
            
            //Output round results
            //Output Defensive Header
            cout<<"\nDefensive Board\n"
                <<"------------------------------\n"
                <<"  1  2  3  4  5  6  7  8  9 10\n";

            //Output Defensive Grid
            cout<<setw(3)<<u1<<setw(3)<<u2<<setw(3)<<u3<<setw(3)<<u4
                <<setw(3)<<u5<<setw(3)<<u6<<setw(3)<<u7<<setw(3)<<u8
                <<setw(3)<<u9<<setw(3)<<u10<<endl;

            //Output Offensive Header
            cout<<"\nOffensive Board\n"
                <<"------------------------------\n"
                <<"  1  2  3  4  5  6  7  8  9 10\n";

            //Output Offensive Grid
            cout<<setw(3)<<c1<<setw(3)<<c2<<setw(3)<<c3<<setw(3)<<c4
                <<setw(3)<<c5<<setw(3)<<c6<<setw(3)<<c7<<setw(3)<<c8
                <<setw(3)<<c9<<setw(3)<<c10<<endl<<endl;

            //Output split and then increment round
            cout<<"___________________________________\n\n";
            rnds++;
        }
    }while(cHits<4&&uHits<4);
    
    
    //Output result to screen
    cout<<((cHits==4)?"You Lost.\n":"You Won!\n")
        <<"\nPlayer Statistics"
        <<"\n-----------------"
        <<"\nRounds   = "<<rnds
        <<"\nMisses   = "<<rnds-uHits
        <<"\nHits     = "<<uHits
        <<setprecision(2)
        <<"\nHit rate = "<<static_cast<float>(uHits)/rnds*100<<"%";
    if(cHits==4){
        cout<<"\nDifference between misses and hits = "
            <<fdim(rnds-uHits,uHits);
    }else{
        cout<<"\nDifference between hits and misses = "
            <<fdim(uHits,rnds-uHits);
    }
    int end=time(0);//End time of Game play
    cout<<"\nTotal play time in integer seconds = "<<end-beg<<endl;            
    
    //Output result to file
    out<<((cHits==4)?"You Lost.":"You Won!")
        <<"\nPlayer Statistics"
        <<"\n-----------------"
        <<"\nRounds   = "<<rnds
        <<"\nMisses   = "<<rnds-uHits
        <<"\nHits     = "<<uHits
        <<setprecision(2)
        <<"\nHit rate = "<<static_cast<float>(uHits)/rnds*100<<"%";
    if(cHits==4){
        out<<"\nDifference between misses and hits = "
            <<fdim(rnds-uHits,uHits);
    }else{
        out<<"\nDifference between hits and misses = "
            <<fdim(uHits,rnds-uHits);
    }
    out<<"\nTotal play time in integer seconds = "<<end-beg<<endl;
    
    //Exit stage right!
    return 0;
}