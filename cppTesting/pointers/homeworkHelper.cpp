#include <iostream>
#include <string>
using namespace std;

int main(){
    int i=5;
    int s=7;
    int *p;
    int *w;

    p=&i;

    w=p;

    //p=&s;

    delete p;
    //*w=i;
    


    cout<<s<<endl;


}