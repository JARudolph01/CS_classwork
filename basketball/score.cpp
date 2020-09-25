#include <iostream>  
#include <string>
#include <fstream>

using namespace std;

ifstream fileIn;
ofstream fileOut;

int main(){

    fileIn.open("scores.txt");

    char ch;
    int aScore;
    bool isAPoint;
    bool isScoreVal;

    while(!fileIn.eof()){
        fileIn>>ch;
        if(ch=='A'||ch=='B'){
            isAPoint=ch=='A';
        }
        else{
            if(isAPoint){
                aScore+=ch;
            }
            else{
                aScore-=ch;
            }
        }
    }
    if(aScore)
    cout<<(aScore>bScore)<<endl;

/*
    fstream fin("scores.txt", fstream::in);
    while (fin >> noskipws >> ch) {
        //if(ch='\n') 
    }
 */   


    return 0;
}