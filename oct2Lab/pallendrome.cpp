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
    string listOfPalindromes;

    while (!inFile.eof()){
        getline(inFile,str);

        //reverse str
        rev = string(str.rbegin(), str.rend());

        if(rev==str){//if str is a palindrome
            numOfPalindromes++;
            listOfPalindromes=listOfPalindromes+str+" ";
        }
    }
    inFile.close();

    cout<<"number of palindromes: "<<numOfPalindromes<<endl;
    cout<<"list of palindromes: "<<listOfPalindromes<<endl;
    
    return 0;
}
