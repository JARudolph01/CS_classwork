#include <iostream>  
#include <string>
#include <fstream>

using namespace std;

ifstream fileIn;
int score;

void tallyScores(){
    if(score>1||score<-1){//win by 2 rule
        if(score>1){
            cout<<"A\n";
        }
        else{
            cout<<"B\n";
        }
    }
    else{
        cout<<"Invalid game: (must win by 2)\n";
    }
    score=0;
}


int main(){

    fileIn.open("scores.txt");

    char ch;
    bool isScore;
    bool isAPoint;

    while(!fileIn.eof()){
        fileIn.get(ch);

        if(ch=='\n'){
            tallyScores();
        }
        else{
            if(ch=='A'||ch=='B'){
                isAPoint=ch=='A';
                isScore=true;
            }
            else if(isScore){
                if(isAPoint){
                    score+=(ch-'0');
                }
                else {
                    score-=(ch-'0');
                }
                isScore=false;
            }
        }
    }
    tallyScores();

    return 0;
}

