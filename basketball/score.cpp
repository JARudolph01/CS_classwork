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
    aScore=0;
    bool isAPoint;

    while(!fileIn.eof()){
        fileIn.get(ch);

        if(ch=='\n'){
            if(aScore>1||aScore<-1){
                if(aScore>1){
                    cout<<"A"<<aScore<<"\n";
                }
                else{
                    cout<<"B"<<aScore<<"\n";
                }
                aScore=0;
            }
            else{
                cout<<"invalid input\n";
            }
        }
        else{
            if(ch=='A'||ch=='B'){
                isAPoint=ch=='A';
            }
            else{
                if(isAPoint){
                    aScore+=(ch-'0');
                }
                else{
                    aScore-=(ch-'0');
                }
                //cout<<(ch-'0')<<" ";
            }
        }
    }

        
    if(aScore>1||aScore<-1){
        if(aScore>1){
            cout<<"A"<<aScore<<"\n";
        }
        else{
            cout<<"B"<<aScore<<"\n";
        }
        aScore=0;
    }
    else{
        cout<<"invalid input\n";
    }

/*
    fstream fin("scores.txt", fstream::in);
    while (fin >> noskipws >> ch) {
        //if(ch='\n') 
    }
 */   


    return 0;
}