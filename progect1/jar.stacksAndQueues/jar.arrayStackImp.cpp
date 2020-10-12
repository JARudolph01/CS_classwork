#include <iostream>
#include "jar.arrayStack.h"
using namespace std;

void arrayStack::push(int num){
    arr[bottom+1]=num;
    bottom++;
}

void arrayStack::pop(){
    arr[bottom]=0;
    bottom--;
}

void arrayStack::printList(){
    for(int i=0; i<=bottom; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

arrayStack::arrayStack(){
    bottom=-1;
}