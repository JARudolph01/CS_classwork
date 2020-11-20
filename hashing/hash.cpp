#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int mod=17;

int main(){

    ifstream inFile("line.txt");

    string strings[mod];

    while(!inFile.eof()){
        string line;
        getline(inFile,line);

        int sum=0;
        for(int i=0; i<line.length(); i++){
            int temp;
            temp=line[i];
            sum+=temp;
        }
        sum%=mod;
        strings[sum]=line;
        cout<<sum;
        cout<<endl;
        sum=0;
    }
    return 0;
}