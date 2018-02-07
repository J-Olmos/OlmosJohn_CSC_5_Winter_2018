/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 6th, 2018, 9:18 PM
 * Purpose:  Mini Battleship
 */

//System Libraries
#include <iostream> //I/O Library
#include <cstdlib>  //Contains srand
#include <ctime>    //Time Library
#include <cmath>    //Math Library
#include <iomanip>  //Format Library
#include <string>   //Strings
#include <fstream>  //File I/O
#include <vector>   //Vectors
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
void result(int,int,int,vector<int> &);
void score(fstream &,string,int[],vector<int> &,int);
void write(ofstream &,string,int [],int);
void selSort(int [],int);
void bubSort(int [],int);
float calc(int,int,float);
int calc(int,int);
int ex(int=0);

//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream cShips;         //Enemy ships
    fstream inLogs;         //Input logs
    ofstream outLogs;       //Output logs
    const int ROWS=5;       
    static int var=2;
    char cS[ROWS][COLS];    //Enemy ship locations
    char uS[ROWS][COLS];    //User ship locations
    char cB[ROWS][COLS];    //Offensive board
    char uB[ROWS][COLS];    //Defensive board
    vector<int> timer(var); //Game Time array
    int tSize=10;
    int times[tSize];       //Time records array
    int rnds;               //Rounds counter
    
    //Initialize Variables
    string brdName="GameBoard.dat";     //Board filename
    string logName="GameScores.dat";    //Score Filename
    int hits[]={0,0};   //Initialize hit counter
    rnds=0;             //Initialize rounds
    
    //Clear & Set Boards
    sDefBd(uB,uS,ROWS); //Defensive Board
    sOffBd(cB,cS,ROWS); //Offensive Board
    
    //Display Intro
    dIntro();
    
    //Computer Ship Placement
    cPlace(cShips,brdName,cS,ROWS);
    
    //Display Defensive Board
    dBoard(uB,ROWS);
    
    //User Ship Placement
    uPlace(uB,uS,ROWS); 
    
    //Display Game Start
    dStart();
    
    //Start Game Timer
    timer[0]=time(0);
    
    
    //Repeat rounds until user or computer hit all targets
    do{
        //User Pick
        hits[1]+=pick(cB,cS,ROWS);

        //Computer Pick
        hits[0]+=cPick(uB,uS,ROWS);

        //Output round results
        //Display defensive board
        cout<<"\n  Defensive Board\n";
        dBoard(uB,ROWS);
        //Display offensive board
        cout<<"\n  Offensive Board\n";
        dBoard(cB,ROWS);
        
        rnds++;//Increment rounds
    }while(hits[1]<9&&hits[0]<9);
    
    //Stop Game Timer
    timer[1]=time(0);
    
    //Display Game statistics
    result(hits[0],hits[1],rnds,timer);

    //If user wins, sort & record time scores 
    //to file then exit, otherwise exit.
    (hits[1]>hits[0])?
    //Open file and read into array and sort
    score(inLogs,logName,times,timer,tSize),
    //Write to file
    write(outLogs,logName,times,tSize),
    //Exit Function 
    ex():
    
    //Exit Function
    ex();
}

void dIntro(){
    cout<<"This is a simple game of Battleship.\n"
        <<"To start you will need to place your\n"
        <<"ships on the 5x5 board shown below.\n\n"; 
}

void sDefBd(char array1[][COLS],char array2[][COLS],int rows){
    //Set Defensive Board & clear ships
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            array1[row][col]=' ';
            array2[row][col]='0';
        }
    }
}

void sOffBd(char array1[][COLS],char array2[][COLS],int rows){
    //Set Offensive Board & clear ships
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            array1[row][col]='?';
            array2[row][col]='0';
        }
    }
}

void cPlace(fstream &input,string fn,char cS[][COLS],int rows){
    //Open the file
    input.open(fn.c_str(),ios::in);
    
    //Read ship placement data from file
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            input>>cS[row][col];
        }
    }
            
    //Close the file
    input.close();
}

void uPlace(char uB[][COLS],char uS[][COLS],int ROWS){
    //Declare & Initialize
    const int BSIZE=4;//Battleship
    const int SSIZE=3;//Submarine
    const int DSIZE=2;//Destroyer
    string place,dir;
    bool valid=false;
    
    //Select Battleship Location
    do{
        do{
            cout<<"\nSet your Battleship (4 spaces long)"
                <<"\nSelect a starting space (ex B2): ";
            cin>>place;
            //Validate Input
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
    
    //Display Defensive Board
    cout<<"\n  Defensive Board\n";    
    dBoard(uB,ROWS);
    
    
    //Set Submarine Location
    valid=false;
    do{
        do{
            cout<<"\nSet your Submarine (3 spaces long)"
                <<"\nSelect a space (ex B2): ";
            cin>>place;
            //Validate Input
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
    
    //Place Submarine on Defensive Board
    setShip(uB,uS,place,dir,SSIZE);
    
    //Display Defensive Board
    cout<<"\n  Defensive Board\n";    
    dBoard(uB,ROWS);
    
    
    //Set Destroyer Location
    valid=false;
    do{
        do{
            cout<<"\nSet your Destroyer (2 spaces long)"
                <<"\nSelect a space (ex B2): ";
            cin>>place;
            //Validate Input
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
    
    //Place Destroyer on Defensive Board
    setShip(uB,uS,place,dir,DSIZE);
    
    //Display Defensive Board
    cout<<"\n  Defensive Board\n";    
    dBoard(uB,ROWS);
}

bool vShip1(string place, string dir){
    //Declare & Initialize checks
    bool check1=false;
    bool check2=false;
    
    //Validate ship placement on the board
    if(dir[0]!='Y'&&dir[0]!='y'){       //Check Vertical placements
        if(place[0]=='A'||place[0]=='B'||place[0]=='C'||
           place[0]=='D'||place[0]=='E')check1=true;
        if(place[1]=='1'||place[1]=='2')check2=true;
    }else{                              //Check Horizontal placements
        if(place[0]=='A'||place[0]=='B')check1=true;
        if(place[1]=='1'||place[1]=='2'||place[1]=='3'||
           place[1]=='4'||place[1]=='5')check2=true;
    }
    
    //Return True if ship fits, else return False
    switch(check1&&check2){
        case 1:return true;break;
        default:cout<<"\nError, ship does not fit\n";
                return false;break;
    }
}

bool vShip2(string place, string dir){
    //Declare & Initialize checks
    bool check1=false;
    bool check2=false;
    
    //Validate ship placement on the board
    if(dir[0]!='Y'&&dir[0]!='y'){       //Check Vertical placements
        if(place[0]=='A'||place[0]=='B'||place[0]=='C'||
           place[0]=='D'||place[0]=='E')check1=true;
        if(place[1]=='1'||place[1]=='2'||place[1]=='3')check2=true;
    }else{                              //Check Horizontal placements
        if(place[0]=='A'||place[0]=='B'||place[0]=='C')check1=true;
        if(place[1]=='1'||place[1]=='2'||place[1]=='3'||
           place[1]=='4'||place[1]=='5')check2=true;
    }
    
    //Return True if ship fits, else return False
    if(check1&&check2){
        return true;
    }else{
        cout<<"\nError, ship does not fit\n";
        return false;
    }
}

bool vShip3(string place, string dir){
    //Declare & Initialize checks
    bool check1=false;
    bool check2=false;
    
    //Validate ship placement on the board
    if(dir[0]!='Y'&&dir[0]!='y'){       //Check Vertical placements
        if(place[0]=='A'||place[0]=='B'||place[0]=='C'||
           place[0]=='D'||place[0]=='E')check1=true;
        if(place[1]=='1'||place[1]=='2'||
           place[1]=='3'||place[1]=='4')check2=true;
    }else{                              //Check Horizontal placements
        if(place[0]=='A'||place[0]=='B'||
           place[0]=='C'||place[0]=='D')check1=true;
        if(place[1]=='1'||place[1]=='2'||place[1]=='3'||
           place[1]=='4'||place[1]=='5')check2=true;
    }

    //Return True if ship fits, else return False
    if(check1&&check2){
        return true;
    }else{
        cout<<"\nError, ship does not fit\n";
        return false;
    }
}

bool valShip(char a[][COLS],string s,string o,int n,int rows){
    //Declare & Initialize checks
    char test[rows][COLS];
    char r,c;
    r=s[0]-65;
    c=s[1]-49;
    
    //Clear test board
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            test[row][col]='0';
        }
    }
    
    //Place ship on test board
    //Search for matching elements between the test and active boards.
    //If the search finds an equal element then ships would overlap.
    if(o[0]=='Y'||o[0]=='y'){       //Check Vertical placements
        for(int i=0;i<n;i++){
            test[r+i][c]='1';
            //Check if place is occupied
            if(test[r+i][c]==a[r+i][c]){
                cout<<"\nError, ships overlap\n";
                return false;
            }
        }
    }else{                          //Check Horizontal placements
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
    //Declare & Initialize
    char row,col;
    row=s[0]-65;
    col=s[1]-49;
    
    //Change Board to place ship
    if(o[0]=='Y'||o[0]=='y'){       //Vertical placements
        for(int i=0;i<rows;i++){
            a1[row+i][col]='S';
            a2[row+i][col]='1';
        }
    }else{                          //Horizontal placements
        for(int i=0;i<rows;i++){
            a1[row][col+i]='S';
            a2[row][col+i]='1';
        }
    }
}

void dStart(){
    cout<<"\n****************************************************"
        <<"\nAll battleships have now been set.\n"
        <<"Try to find and destroy the enemy's fleet by hitting\n"
        <<"all points on their ships before they can sink yours.\n"
        <<"Board key: [? = Unknown] [0 = Misses] [X = Hits]\n"
        <<"******************************************************\n\n";
}

bool pick(char cB[][COLS],char cS[][COLS],int rows){
    //Declare & Initialize
    string place="F6";
    
    //User Pick, loop until input is valid
    while((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
           place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
           place[1]!='4'&&place[1]!='5')){
        cout<<"\nSelect a space to target (ex B2): ";
        cin>>place;
        //Display error if invalid
        if((place[0]!='A'&&place[0]!='B'&&place[0]!='C'&&place[0]!='D'&&
           place[0]!='E')||(place[1]!='1'&&place[1]!='2'&&place[1]!='3'&&
           place[1]!='4'&&place[1]!='5')){
            cout<<"\nInvalid entry\n";
        }
    }
    
    //Output Pick
    cout<<"\nYou picked  : "<<place<<endl;
    
    //Convert string to Char
    char col=place[0]-65;
    char row=place[1]-49;
    
    //Update offensive board with X if pick hit, else O
    if(cS[col][row]=='1'){
        cB[col][row]='X';
        return true;    //Return true if pick hit ship
    }else{
        cB[col][row]='O';
        return false;  //Return false if pick missed ship
    }
}

bool cPick(char uB[][COLS],char uS[][COLS],int rows){
    //Declare & Initialize
    int col,row;
    int guess=0;
    int hit=0;
    
    //Computer Pick, computers gets multiple tries per turn.
    //Loop and guess until computer pick hits user ship or
    //once four guess have been made (unless guess matches a
    //previous round pick, then reset counter end repeat).
    do{
        do{
            col=rand()%5;//Pick row [0,4]
            row=rand()%5;//Pick column [0,4]
            if(uS[col][row]=='1')hit=1;
            guess++;
        }while(hit!=1&&guess<pow(2,2));
        if(uB[col][row]=='X'||uB[col][row]=='O')guess=0;
    }while(guess==0);
    
    //Output Final Pick
    cout<<"Enemy picked: "
        <<static_cast<char>(col+65)
        <<static_cast<char>(row+49)
        <<endl;
    
    //Update defensive board with X if pick hit, else O
    if(uS[col][row]=='1'){
        uB[col][row]='X';
        return true;        //Return true if pick hit ship
    }else{
        uB[col][row]='O';
        return false;       //Return false if pick misses ship
    }
}

void dBoard(char array[][COLS],int rows){
    //Display Header
    cout<<"    ";
    for(int col=0;col<COLS;col++){
            cout<<setw(2)<<col+1<<" ";
    }
    cout<<"\n    --------------\n";
    
    //Display Grid
    for(int row=0;row<rows;row++){
        char r='A';
        cout<<" "<<static_cast<char>(r+row)<<" |";
        for(int col=0;col<COLS;col++){
            cout<<" "<<array[row][col]<<" ";
        }
        cout<<endl;
    }
}

void result(int cHits,int uHits,int rnds,vector<int> &timer){
    //Output game information
    if(uHits==cHits)cout<<"\n\nTie!\n";
    else if (uHits>cHits)cout<<"\n\nYou Won!\n";
    else cout<<"\n\nYou Lost.\n";
    cout<<"\nPlayer Statistics"
        <<"\n-----------------"
        <<"\nRounds   = "<<rnds
        <<"\nMisses   = "<<calc(rnds,uHits)
        <<"\nHits     = "<<uHits
        <<fixed<<setprecision(2)
        <<"\nHit rate = "<<calc(uHits,rnds,100.0f)<<"%"
        <<"\nTotal play time in integer seconds = "<<timer[1]-timer[0]<<endl;
}

void score(fstream &scores,string fn,int t[],vector<int> &a,int n){
    //Open the file
    scores.open(fn.c_str(),ios::in);
    
    //Read and copy the data from the file into array
    for(int i=0;i<n;i++){
        scores>>t[i];
    }
    
    //Selection sort array
    selSort(t,n);
    
    //Add game score to end of array
    t[9]=a[1]-a[0];
    
    //Bubble sort new array
    bubSort(t,n);
            
    //Close the file
    scores.close();
}

void write(ofstream &output,string fn,int t[],int n){
    //Open the file for writing
    output.open(fn.c_str());
    
    //Output the result to file
    for(int i=0;i<n;i++){
        output<<t[i]<<endl;
    }
    
    //Close the file
    output.close();
}

void selSort(int a[],int n){
    //Declare variables
    int mI,mV;
    
    //Selection sort
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

void bubSort(int array[], int size){ 
    //Declare Variables
    bool swap; 
    int temp;
    
    //Bubble Sort
    do{ 
       swap=false; 
       for (int count = 0; count<(size-1); count++){ 
          if (array[count]>array[count+1]){ 
              temp=array[count]; 
              array[count]=array[count+1]; 
              array[count+1]=temp; 
              swap=true; 
          }
       } 
    }while(swap);  
} 

float calc(int x,int y,float z){
    return z*x/y;//Calculate %
}

int calc(int x,int y){
    return x-y;//Subtract
}

int ex(int n){
    exit(n); //Exit function with defaulted argument
}