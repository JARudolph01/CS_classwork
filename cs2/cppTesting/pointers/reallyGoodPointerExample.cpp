#include <iostream>
#include <string>
using namespace std;

int main(){
    string *str;
    string fName, lName;
    str=&fName;
    *str="Miller";
    str=&lName;
    *str="Tommy";
    cout<<fName<<" "<<lName<<endl;
    
}