/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 6th, 2018, 12:33 AM
 * Purpose:  Mini Battleship
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Contains srand
#include <ctime>     //Time Library
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
#include <string>    //Strings
#include <fstream>   //File I/O
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Column Dimension
const int COLS=5;

//Function Prototypes
void dIntro();
void sOffBd(char [][COLS],char [][COLS],int);
void sDefBd(char [][COLS],char [][COLS],int);
void cPlace(fstream &,string,char [][COLS],int);
void uPlace(char [][COLS],char [][COLS],int);
bool vShip1(string,string);
bool vShip2(string,string);
bool vShip3(string,string);
bool valShip(char [][COLS],string,string,int,int);
void setShip(char [][COLS],char [][COLS],string,string,int);
void dStart();
bool pick(char [][COLS],char [][COLS],int);
bool cPick(char [][COLS],char [][COLS],int);
void dBoard(char [][COLS],int);
void result(ofstream &,string,int,int,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream compSP;
    ofstream results;
    const int ROWS=5;
    char cS[ROWS][COLS];
    char uS[ROWS][COLS];
    char cB[ROWS][COLS];    
    char uB[ROWS][COLS];
    int uHits,cHits,rnds;
    
    //Initialize Variables
    string testName="GameInfo.dat";
    uHits=cHits=rnds=0;
    
    //Clear Board
    sDefBd(uB,uS,ROWS);
    sOffBd(cB,cS,ROWS);
    
    //Output Intro
    dIntro();
    
    //Computer Ship Placement
    cPlace(compSP,testName,cS,ROWS);
    
    //Output Defensive Board
    dBoard(uB,ROWS);
    
    //User Ship Placement
    uPlace(uB,uS,ROWS); 
    
    //Start Game
    dStart();
    
    //Start Game Timer
    int beg=time(0);
    
    do{
        //User Pick
        uHits+=pick(cB,cS,ROWS);

        //Computer Pick
        cHits+=cPick(uB,uS,ROWS);

        //Output round results
        cout<<"\n  Defensive Board\n";
        dBoard(uB,ROWS);
        cout<<"\n  Offensive Board\n";
        dBoard(cB,ROWS);
        
        //Increment rounds
        rnds++;
    }while(cHits<9&&uHits<9);
    
    //Stop Game Timer
    int end=time(0);
    
    //Output Results
    int time=end-beg;
    string resName="GameStats.dat";
    result(results,resName,cHits,uHits,rnds,time);
    
    
    //Exit stage right!
    return 0;
}

void dIntro(){
    cout<<"This is a simple game of Battleship.\n"
        <<"To start you will need to place your\n"
        <<"ships on the 5x5 board shown below.\n\n"; 
}

void sDefBd(char array1[][COLS],char array2[][COLS],int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            array1[row][col]=' ';
            array2[row][col]='0';
        }
    }
}

void sOffBd(char array1[][COLS],char array2[][COLS],int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            array1[row][col]='?';
            array2[row][col]='0';
        }
    }
}

void cPlace(fstream & input,string fn,char cS[][COLS],int rows){
    //Open the file
    input.open(fn.c_str(),ios::in);
    
    //Read the data from the file
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            input>>cS[row][col];
        }
    }
            
    //Close the file
    input.close();
}

void uPlace(char uB[][COLS],char uS[][COLS],int ROWS){
    const int BSIZE=4;
    const int SSIZE=3;
    const int DSIZE=2;
    string place,dir;
    bool valid=false;
    
    //Set User Battleship Location
    do{
        do{
            cout<<"\nSet your Battleship (4 spaces long)"
                <<"\nSelect a starting space (ex B2): ";
            cin>>place;
            if((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
               place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
               place[1]!='4'&&place[1]!='5')){
                cout<<"\nInvalid entry\n";
            }
        }while((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
               place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
               place[1]!='4'&&place[1]!='5'));
        cout<<"Place vertically? (y/n): ";
        cin>>dir;
        
        //Validate Placement
        valid=vShip1(place,dir);
    }while(!valid);        
    
    //Place Battleship on Defensive Board
    setShip(uB,uS,place,dir,BSIZE);
    
    //Output Defensive Board
    cout<<"\n  Defensive Board\n";    
    dBoard(uB,ROWS);
    
    
    //Set User Submarine Location
    valid=false;
    do{
        do{
            cout<<"\nSet your Submarine (3 spaces long)"
                <<"\nSelect a space (ex B2): ";
            cin>>place;
            if((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
               place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
               place[1]!='4'&&place[1]!='5')){
                cout<<"\nInvalid entry\n";
            }
        }while((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
               place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
               place[1]!='4'&&place[1]!='5'));
        cout<<"Place vertically? (y/n): ";
        cin>>dir;
        
        //Validate Placement
        valid=vShip2(place,dir);
        valid=valShip(uS,place,dir,SSIZE,ROWS);
    }while(!valid);        
    
    //Place Battleship on Defensive Board
    setShip(uB,uS,place,dir,SSIZE);
    
    //Output Defensive Board
    cout<<"\n  Defensive Board\n";    
    dBoard(uB,ROWS);
    
    
    //Set User Destroyer Location
    valid=false;
    do{
        do{
            cout<<"\nSet your Destroyer (2 spaces long)"
                <<"\nSelect a space (ex B2): ";
            cin>>place;
            if((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
               place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
               place[1]!='4'&&place[1]!='5')){
                cout<<"\nInvalid entry\n";
            }
        }while((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
               place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
               place[1]!='4'&&place[1]!='5'));
        cout<<"Place vertically? (y/n): ";
        cin>>dir;
        
        //Validate Placement
        valid=vShip3(place,dir);
        valid=valShip(uS,place,dir,DSIZE,ROWS);
    }while(!valid);        
    
    //Place Battleship on Defensive Board
    setShip(uB,uS,place,dir,DSIZE);
    
    //Output Defensive Board
    cout<<"\n  Defensive Board\n";    
    dBoard(uB,ROWS);
}

bool vShip1(string place, string dir){
    bool check1=false;
    bool check2=false;
    //Validate input
        if(dir[0]!='Y'&&dir[0]!='y'){
            if(place[0]=='A'||place[0]=='B'||place[0]=='C'||
               place[0]=='D'||place[0]=='E')check1=true;
            if(place[1]=='1'||place[1]=='2')check2=true;
        }else{
            if(place[0]=='A'||place[0]=='B')check1=true;
            if(place[1]=='1'||place[1]=='2'||place[1]=='3'||
               place[1]=='4'||place[1]=='5')check2=true;
        }
        if(check1&&check2){
            return true;
        }else{
            cout<<"\nError, ship does not fit\n";
            return false;
        }
}

bool vShip2(string place, string dir){
    bool check1=false;
    bool check2=false;
    //Validate input
        if(dir[0]!='Y'&&dir[0]!='y'){
            if(place[0]=='A'||place[0]=='B'||place[0]=='C'||
               place[0]=='D'||place[0]=='E')check1=true;
            if(place[1]=='1'||place[1]=='2'||place[1]=='3')check2=true;
        }else{
            if(place[0]=='A'||place[0]=='B'||place[0]=='C')check1=true;
            if(place[1]=='1'||place[1]=='2'||place[1]=='3'||
               place[1]=='4'||place[1]=='5')check2=true;
        }
        if(check1&&check2){
            return true;
        }else{
            cout<<"\nError, ship does not fit\n";
            return false;
        }
}

bool vShip3(string place, string dir){
    bool check1=false;
    bool check2=false;
    //Validate input
        if(dir[0]!='Y'&&dir[0]!='y'){
            if(place[0]=='A'||place[0]=='B'||place[0]=='C'||
               place[0]=='D'||place[0]=='E')check1=true;
            if(place[1]=='1'||place[1]=='2'||
               place[1]=='3'||place[1]=='4')check2=true;
        }else{
            if(place[0]=='A'||place[0]=='B'||
               place[0]=='C'||place[0]=='D')check1=true;
            if(place[1]=='1'||place[1]=='2'||place[1]=='3'||
               place[1]=='4'||place[1]=='5')check2=true;
        }
        if(check1&&check2){
            return true;
        }else{
            cout<<"\nError, ship does not fit\n";
            return false;
        }
}

bool valShip(char a[][COLS],string s,string o,int n,int rows){
    char test[rows][COLS];
    char r,c;
    r=s[0]-65;
    c=s[1]-49;
    
    //clear test board
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            test[row][col]='0';
        }
    }
    
    //Place ship on test board
    if(o[0]=='Y'||o[0]=='y'){
        for(int i=0;i<n;i++){
            test[r+i][c]='1';
            //Check if place is occupied
            if(test[r+i][c]==a[r+i][c]){
                cout<<"\nError, ships overlap\n";
                return false;
            }
        }
    }else{
        for(int i=0;i<n;i++){
            test[r][c+i]='1';
            //Check if place is occupied
            if(test[r][c+i]==a[r][c+i]){
                cout<<"\nError, ships overlap\n";
                return false;
            }
        }
    }
}

void setShip(char a1[][COLS],char a2[][COLS],string s,string o,int rows){
    char row,col;
    row=s[0]-65;
    col=s[1]-49;
    if(o[0]=='Y'||o[0]=='y'){
        for(int i=0;i<rows;i++){
            a1[row+i][col]='S';
            a2[row+i][col]='1';
        }
    }else{
        for(int i=0;i<rows;i++){
            a1[row][col+i]='S';
            a2[row][col+i]='1';
        }
    }
}

void dStart(){
    cout<<"\n***********************************************"
        <<"\nAll battleships have now been set.\n"
        <<"Try and hit and sink the enemy's battleship\n"
        <<"by hitting all 4 spots before it can sink you.\n"
        <<"[? = Unknown] [0 = Misses] [X = Hits]\n"
        <<"***********************************************\n\n";
}

bool pick(char cB[][COLS],char cS[][COLS],int rows){
    string place="F6";
    
    //User Pick
    while((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
           place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
           place[1]!='4'&&place[1]!='5')){
        cout<<"\nSelect a space (ex B2): ";
        cin>>place;
        if((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
           place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
           place[1]!='4'&&place[1]!='5')){
            cout<<"\nInvalid entry\n";
        }
    }
    
    //Output Pick
    cout<<"\nYou picked  : "<<place<<endl;
    
    //Convert to Char
    char col=place[0]-65;
    char row=place[1]-49;
    
    //Pick Results
    if(cS[col][row]=='1'){
        cB[col][row]='X';
        return true;
    }else{
        cB[col][row]='O';
        return false;
    }
}

bool cPick(char uB[][COLS],char uS[][COLS],int rows){
    int col,row;
    int guess=0;
    int hit=0;
    
    //Computer Pick
    do{
        do{
            col=rand()%5;//Pick row [0,4]
            row=rand()%5;//Pick column [0,4]
            if(uS[col][row]=='1')hit=1;
            guess++;
        }while(hit!=1&&guess<4);
        if(uB[col][row]=='X'||uB[col][row]=='O')guess=0;
    }while(guess==0);
    
    //Output Pick
    cout<<"Enemy picked: "
        <<static_cast<char>(col+65)
        <<static_cast<char>(row+49)
        <<endl;
    
    //Pick Results
    if(uS[col][row]=='1'){
        uB[col][row]='X';
        return true;
    }else{
        uB[col][row]='O';
        return false;
    }
}

void dBoard(char array[][COLS],int rows){
    //Output Header
    cout<<"    ";
    for(int col=0;col<COLS;col++){
            cout<<setw(2)<<col+1<<" ";
    }
    cout<<"\n    --------------\n";
    
    //Output Board
    for(int row=0;row<rows;row++){
        char r='A';
        cout<<" "<<static_cast<char>(r+row)<<" |";
        for(int col=0;col<COLS;col++){
            cout<<" "<<array[row][col]<<" ";
        }
        cout<<endl;
    }
}

void result(ofstream &output,string fn,int cHits,int uHits,int rnds,int time){
    //Open the file for writing
    output.open(fn.c_str());
    
    //Output result to screen
    cout<<endl<<endl
        <<((uHits==cHits)?"Tie!\n":
           (cHits==4)?"You Lost.\n":"You Won!\n")
        <<"\nPlayer Statistics"
        <<"\n-----------------"
        <<"\nRounds   = "<<rnds
        <<"\nMisses   = "<<rnds-uHits
        <<"\nHits     = "<<uHits
        <<fixed<<setprecision(2)
        <<"\nHit rate = "<<static_cast<float>(uHits)/rnds*100<<"%";
    if(rnds-uHits>uHits){
        cout<<"\nDifference between misses and hits = "
            <<setprecision(0)<<fdim(rnds-uHits,uHits);
    }else{
        cout<<"\nDifference between hits and misses = "
            <<setprecision(0)<<fdim(uHits,rnds-uHits);
    }
    cout<<"\nTotal play time in integer seconds = "<<time<<endl;
    
    //Output result to file
    output<<endl<<endl
        <<((uHits==cHits)?"Tie!\n":
          (cHits==4)?"You Lost.\n":"You Won!\n")
        <<"\nPlayer Statistics"
        <<"\n-----------------"
        <<"\nRounds   = "<<rnds
        <<"\nMisses   = "<<rnds-uHits
        <<"\nHits     = "<<uHits
        <<fixed<<setprecision(2)
        <<"\nHit rate = "<<static_cast<float>(uHits)/rnds*100<<"%";
    if(rnds-uHits>uHits){
        output<<"\nDifference between misses and hits = "
            <<setprecision(0)<<fdim(rnds-uHits,uHits);
    }else{
        output<<"\nDifference between hits and misses = "
            <<setprecision(0)<<fdim(uHits,rnds-uHits);
    }
    output<<"\nTotal play time in integer seconds = "<<time<<endl;    
    
    //Close the file
    output.close();
}