#include "linkedList.h"
#include <iostream>
using namespace std;

//Creates and adds nodes to the list
void linkedList::addNum(int num){

    //if list is empty
    if(head == NULL){
        node* newNode = new node();
        head=newNode;
        //head->setData(num);
        head->setNextPtr(NULL);
    }

    //find the end of the linkedList
    current = head;
    while(current->getNextPtr()!=NULL){
        current=current -> getNextPtr();
    }

    //add the new node
    node* newNode = new node();
    current->setNextPtr(newNode);
    current=newNode;
    current->setData(num);
    current->setNextPtr(NULL);
    
}

//Prints out the data from the nodes.
void linkedList::printList(){
    cout<<"LinkedList { ";
    current = head;
    while(current->getNextPtr()!=NULL){
        cout<<current->getNextPtr()->getData()<<" ";
        current=current -> getNextPtr();
    }
    //cout<<current->getData()<<" ";//even though the tail points to null, it still has data
    cout<<"}\n";
}

//Constructor.
linkedList::linkedList(){
    head=NULL;
    current=NULL;
    //I ended up not using next
}