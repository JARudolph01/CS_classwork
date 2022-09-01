//John Rudolph
//jar.stacksAndQueues linkList stack implementation
//due 10/14

#include "jar.linkedListStack.h"
#include <iostream>
using namespace std;

//Creates and adds nodes to the queue
void linkedListStack::push(int num){

    //if list is empty
    if(top == NULL){
        node* newNode = new node();
        top=newNode;
        top->setData(num);
        top->setNextPtr(NULL);
    }
    else{
        //add the new node
        node* newNode = new node();
        newNode->setNextPtr(top);
        newNode->setData(num);
        top=newNode;
    }
    
    
}

//removes the first item in the queue
void linkedListStack::pop(){
    node* markODeath;
    markODeath=top;
    top=top->getNextPtr();
    delete(markODeath);
}

//Prints out the data from the nodes.
void linkedListStack::printList(){
    node* current;
    current = top;
    while(current->getNextPtr()!=NULL){
        cout<<current->getData()<<" ";
        current=current -> getNextPtr();
    }
    cout<<current->getData()<<" ";//even though the last node points to null, it still has data
    cout<<endl;
}

//Constructor.
linkedListStack::linkedListStack(){
    top=NULL;
}