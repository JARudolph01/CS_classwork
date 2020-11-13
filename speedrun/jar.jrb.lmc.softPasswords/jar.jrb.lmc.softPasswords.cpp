/*
John
Joshua
Landis
*/

#include <iostream>
#include <string>

using namespace std;


int main(){

    string password = "";

    cout<<"Set a new password ";
    cin>>password;

    cout<<"What's the magic word? ";

    string input;
    cin>>input;

    if(password==input){
        cout<<"Yes\n";
        return 0;
    }

    for(int i=0;i<9;i++){
        if(password==to_string(i)+input){
            cout<<"Yes\n";
            return 0;
        }
        if(password==input+to_string(i)){
            cout<<"Yes\n";
            return 0;
        }
    }

    for(int i=0;i<input.length();i++){
        if(isupper(input[i])){
            input[i]=tolower(input[i]);
        }
        else if(islower(input[i])){
            input[i]=toupper(input[i]);
        }
    }

    if(password==input){
        cout<<"Yes\n";
        return 0;
    }
    
    cout<<"No\n";


    return 0;
}