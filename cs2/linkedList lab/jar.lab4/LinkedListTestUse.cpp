#include <iostream>
#include <fstream>
#include "linkedList.h"
using namespace std;
int main(){

    int temp = 0;
    
    //opening data.txt
    ifstream inFile;
    inFile.open("data.txt");
    
    //Creating a instance of the linked list.
    linkedList list;

    //Takes data from data.txt and adds it to the linked list
    for(int i; i < 10; i++){
        inFile >> temp;
        list.addNum(temp);
    }
    
    //prints the linked list, finds a number in the linked list, and removes a number from the linked list.
    list.printList();
    list.findNum(0);
    list.removeNum(260);
    
    list.addNum(65);
    list.findNum(0);
    list.printList();
    
    //Closing data.txt
    inFile.close();

    cout<<"it works!\n";
    return 0;
}