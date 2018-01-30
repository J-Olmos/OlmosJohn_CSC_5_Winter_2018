/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Jan 29, 2018, 12:45 PM
 * Purpose: Shooting game 
 */

//System Libraries Here
#include <iostream> //I/O Library
#include <cstdlib>  //srand 
#include <ctime>    //Time
#include <iomanip>  //Format Currency
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool pHit(float);
void shoot(bool,float,bool &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    bool aL,bL,cL;
    float aP,bP,cP;
    int rnds,A;
    int sA,sB,sC;
    
    //Input or initialize values Here
    sA=sB=sC=0;
    aP=0.3f;
    bP=0.5f;
    cP=1.0f;
    rnds=100000;
    
    for(int rnd=1;rnd<=rnds;rnd++){
    aL=bL=cL=true;
    A=3;
    
        //Process
        do{
            if(aL&&cL){
                shoot(aL,aP,cL);
            }else if (aL&&bL){
                shoot(aL,aP,bL);
            }
            if(bL&&cL){
                shoot(bL,bP,cL);
            }else if (bL&&aL){
                shoot(bL,bP,aL);
            }
            if(cL&&bL){
                shoot(cL,cP,bL);
            }else if (cL&&aL){
                shoot(cL,cP,aL);
            }
            A=aL+bL+cL;
        }while(A>1);
        sA+=aL;
        sB+=bL;
        sC+=cL;
    }    
    
    //Output
    cout<<"Al      "<<1.0f*sA/rnds<<endl
        <<"Bob     "<<1.0f*sB/rnds<<endl
        <<"Charlie "<<1.0f*sC/rnds<<endl;
    
    //Exit stage right!
    return 0;
}

void shoot(bool s,float sP,bool &v){
    if(v){
        v=pHit(sP)?false:true;
    }
}

bool pHit(float perc){
    static const unsigned int  mRand=(1<<31)-1;//Max rand
    float random=static_cast<float>(rand())/mRand;//[0,1]
    return random<perc;
}