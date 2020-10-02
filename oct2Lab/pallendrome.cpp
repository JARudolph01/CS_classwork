#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream inFile("input.txt");

    string str;
    string rev;
    int numOfPalindromes;
    numOfPalindromes=0;

    while (!inFile.eof()){
        getline(inFile,str);

        //reverse str
        rev = string(str.rbegin(), str.rend());

        if(rev==str){
            numOfPalindromes++;
            cout<<str<<endl;
        }
    }
    inFile.close();

    cout<<"number of palindromes: "<<numOfPalindromes<<endl;
    
    return 0;
}
