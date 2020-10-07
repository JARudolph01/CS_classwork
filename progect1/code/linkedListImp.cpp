#include "linkedList.h"
#include <iostream>
using namespace std;

//Creates and adds nodes to the list
void linkedList::enqueue(int num){

    //if list is empty
    if(head == NULL){
        node* newNode = new node();
        head=newNode;
        head->setData(num);
        head->setNextPtr(NULL);
        tail = head;
    }
    else{
        //add the new node
        node* newNode = new node();
        tail->setNextPtr(newNode);
        tail=newNode;
        tail->setData(num);
        tail->setNextPtr(NULL);
    }
    
    
}

//Prints out the data from the nodes.
void linkedList::dequeue(){
    node* markODeath;
    markODeath=head;
    head=head->getNextPtr();
    delete(markODeath);
}

void linkedList::printList(){
    node* current;
    current = head;
    while(current->getNextPtr()!=NULL){
        cout<<current->getData()<<" ";
        current=current -> getNextPtr();
    }
    cout<<current->getData()<<" ";//even though the last node points to null, it still has data
    cout<<endl;
}

//Constructor.
linkedList::linkedList(){
    head=NULL;
    tail=NULL;
    
}