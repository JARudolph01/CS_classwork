#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void reverse(string &s) {
    int begin = 0;
    int end = s.length();

    while ((begin != end) && (begin != --end)){
        swap(s[begin++], s[end]);
    }
}

int main(){

    ifstream inFile("input.txt");

    string str;
    string rev;
    int numOfPalindromes;
    numOfPalindromes=0;

    while (!inFile.eof()){
        getline(inFile,str);

        rev=str;
        reverse(rev);

        if(rev==str){
            numOfPalindromes++;
            cout<<str<<endl;
        }

    }
    inFile.close();

    cout<<numOfPalindromes<<endl;
    
    return 0;
}
