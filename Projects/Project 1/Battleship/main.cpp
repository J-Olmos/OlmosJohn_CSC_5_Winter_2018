/* 
 * File:   main.cpp
 * Author: John Olmos
 * Created on Jan 30, 2018, 12:06 AM
 * Purpose: Simple Battleship
 */

//System Libraries Here
#include <iostream> //Input - Output Library
#include <cstdlib>  //Srand to set the seed
#include <fstream>  //File I/O
#include <iomanip>  //Format the output
#include <string>   //Strings
#include <ctime>    //Time library
#include <cmath>    //Math functions
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
    ifstream in;                //Input File
    ofstream out;               //Output File
    bool cB1,cB2,cB3,cB4,cB5,   //Computer battleship location 
         cB6,cB7,cB8,cB9,cB10,  //variable true if at that location
         uB1,uB2,uB3,uB4,uB5,   //User battleship location
         uB6,uB7,uB8,uB9,uB10;  //variable true if at that location
    char c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,    //Offensive Board
         u1,u2,u3,u4,u5,u6,u7,u8,u9,u10;    //Defensive board
    const int HUND=100; //Constant for 100
    int cHits,uHits,//User hit counter
        rnds,       //round counter
        cPick;      //Computer pick
    string uPick;   //User pick
    
    //Input or initialize values Here
    string inName="GameInfo.dat";   //String Name
    char outName[]="GameStats.dat"; //Character Array Name
    in.open(inName.c_str());        //Open the Input file
    out.open(outName);              //Open the Output file
    while(in>>rnds);                //Last value in file becomes rounds
    cB1=cB2=cB3=cB4=cB5=cB6=cB7=cB8=cB9=cB10=false; //Clear offensive ship
    c1=c2=c3=c4=c5=c6=c7=c8=c9=c10='?';             //Mask offensive board
    cHits=uHits=0;  //Reset hit counters
    
    //Output instructions
    cout<<"This is a simple game of Battleship.\n"
        <<"Both you and the computer will place a\n"
        <<"battleship 4 units long on the board.\n";
    
    char conf='n';                  //Set confirmation to 'n'
    while(conf!='y'&&conf!='Y'){    //Loop until ship is set and confirmed
        char uB;
        uB1=uB2=uB3=uB4=uB5=uB6=uB7=uB8=uB9=uB10=false; //Clear defensive ship
        u1=u2=u3=u4=u5=u6=u7=u8=u9=u10=' ';             //Clear defensive board
        //Output directions
        cout<<"\nStart the game by placing your battleship\n"
            <<"Please enter a number from 1-7: ";
        cin>>uB;//Input ship location
        
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
            
            //Output Defensive Header
            cout<<"\nDefensive Board\n"
                <<"------------------------------\n"
                <<"  1  2  3  4  5  6  7  8  9 10\n";

            //Output Defensive Board
            cout<<setw(3)<<u1<<setw(3)<<u2<<setw(3)<<u3<<setw(3)<<u4
                <<setw(3)<<u5<<setw(3)<<u6<<setw(3)<<u7<<setw(3)<<u8
                <<setw(3)<<u9<<setw(3)<<u10<<endl<<endl;

            //Confirmation
            cout<<"Confirm battleship placement? (y/n): ";
            cin>>conf;
        }
    };
    
    //Set computer battleship location
    //Generate battleship start point from 1-7
    unsigned short cB=rand()%7+1;//[1,7]
    
    //Place computer battleship based on generated start
    //turn start and the following three variables to 
    if(cB==1){cB1=cB2=cB3=cB4=true;}
    if(cB==2){cB2=cB3=cB4=cB5=true;}
    if(cB==3){cB3=cB4=cB5=cB6=true;}
    if(cB==4){cB4=cB5=cB6=cB7=true;}
    if(cB==5){cB5=cB6=cB7=cB8=true;}
    if(cB==6){cB6=cB7=cB8=cB9=true;}
    if(cB==7){cB7=cB8=cB9=cB10=true;}
    
    //Output Game start
    cout<<"\n***********************************************"
        <<"\nAll battleships have now been set.\n"
        <<"Try and hit and sink the enemy's battleship\n"
        <<"by hitting all 4 spots before it can sink you.\n"
        <<"[? = Unknown] [0 = Misses] [X = Hits]\n"
        <<"***********************************************\n\n";
    
    //Play Game
    int beg=time(0);//Time the game play
    do{
        //Computer's turn
        do{
            //Computer Pick
            cPick=rand()%10+1;

            //Computer Pick result
            switch(cPick){
            case 1:(u1=='X'||u1=='O')?cPick=0:
                   (uB1)?u1='X',cHits++:u1='O';break;
            case 2:(u2=='X'||u2=='O')?cPick=0:
                   (uB2)?u2='X',cHits++:u2='O';break;
            case 3:(u3=='X'||u3=='O')?cPick=0:
                   (uB3)?u3='X',cHits++:u3='O';break;
            case 4:(u4=='X'||u4=='O')?cPick=0:
                   (uB4)?u4='X',cHits++:u4='O';break;
            case 5:(u5=='X'||u5=='O')?cPick=0:
                   (uB5)?u5='X',cHits++:u5='O';break;
            case 6:(u6=='X'||u6=='O')?cPick=0:
                   (uB6)?u6='X',cHits++:u6='O';break;
            case 7:(u7=='X'||u7=='O')?cPick=0:
                   (uB7)?u7='X',cHits++:u7='O';break;
            case 8:(u8=='X'||u8=='O')?cPick=0:
                   (uB8)?u8='X',cHits++:u8='O';break;
            case 9:(u9=='X'||u9=='O')?cPick=0:
                   (uB9)?u9='X',cHits++:u9='O';break;
            case 10:(u10=='X'||u10=='O')?cPick=0:
                    (uB10)?u10='X',cHits++:u10='O';break;
            }
        }while(cPick==0);
            
        //User's turn
        //User Pick
        cout<<"Enter a number from 1-10: ";
        cin>>uPick;

        //Input validation
        if(uPick!="1"&&uPick!="2"&&uPick!="3"&&uPick!="4"&&uPick!="5"&&
           uPick!="6"&&uPick!="7"&&uPick!="8"&&uPick!="9"&&uPick!="10"){
            cout<<"\nInvalid input, please try again.\n";
        }        

        else {
            //User Pick Result
            int pick=stoi(uPick);
            switch(pick){
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
            
            //Output Computer and Player picks
            cout<<"\nEnemy picked : "<<cPick<<endl
                <<"You picked   : "<<uPick<<endl;
            
            //Output round results
            //Output Defensive Header
            cout<<"\nDefensive Board\n"
                <<"------------------------------\n"
                <<"  1  2  3  4  5  6  7  8  9 10\n";

            //Output Defensive board
            cout<<setw(3)<<u1<<setw(3)<<u2<<setw(3)<<u3<<setw(3)<<u4
                <<setw(3)<<u5<<setw(3)<<u6<<setw(3)<<u7<<setw(3)<<u8
                <<setw(3)<<u9<<setw(3)<<u10<<endl;

            //Output Offensive Header
            cout<<"\nOffensive Board\n"
                <<"------------------------------\n"
                <<"  1  2  3  4  5  6  7  8  9 10\n";

            //Output Offensive board
            cout<<setw(3)<<c1<<setw(3)<<c2<<setw(3)<<c3<<setw(3)<<c4
                <<setw(3)<<c5<<setw(3)<<c6<<setw(3)<<c7<<setw(3)<<c8
                <<setw(3)<<c9<<setw(3)<<c10<<endl<<endl;

            //Output divider and then increment round
            for(int i=1;i<10;i++){cout<<"____";}cout<<endl<<endl;
            rnds++;
        }
    }while(cHits<4&&uHits<4);
    int end=time(0);//End time of Game play    
    
    //Outputs
    //Output result to screen
    cout<<((uHits==cHits)?"Tie!\n":
           (cHits==4)?"You Lost.\n":"You Won!\n")
        <<"\nPlayer Statistics"
        <<"\n-----------------"
        <<"\nRounds   = "<<rnds
        <<"\nMisses   = "<<rnds-uHits
        <<"\nHits     = "<<uHits
        <<fixed<<setprecision(2)
        <<"\nHit rate = "<<static_cast<float>(uHits)/rnds*HUND<<"%";
    if(rnds-uHits>uHits){
        cout<<"\nDifference between misses and hits = "
            <<setprecision(0)<<fdim(rnds-uHits,uHits);
    }else{
        cout<<"\nDifference between hits and misses = "
            <<setprecision(0)<<fdim(uHits,rnds-uHits);
    }
    cout<<"\nTotal play time in integer seconds = "<<end-beg<<endl;            
    
    //Output result to file
    out<<((uHits==cHits)?"Tie!\n":
          (cHits==4)?"You Lost.\n":"You Won!\n")
        <<"\nPlayer Statistics"
        <<"\n-----------------"
        <<"\nRounds   = "<<rnds
        <<"\nMisses   = "<<rnds-uHits
        <<"\nHits     = "<<uHits
        <<fixed<<setprecision(2)
        <<"\nHit rate = "<<static_cast<float>(uHits)/rnds*HUND<<"%";
    if(rnds-uHits>uHits){
        out<<"\nDifference between misses and hits = "
            <<setprecision(0)<<fdim(rnds-uHits,uHits);
    }else{
        out<<"\nDifference between hits and misses = "
            <<setprecision(0)<<fdim(uHits,rnds-uHits);
    }
    out<<"\nTotal play time in integer seconds = "<<end-beg<<endl;
    
    //Exit stage right!
    in.close();
    out.close();
    return 0;
}