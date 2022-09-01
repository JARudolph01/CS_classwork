//John Rudolph
//jar.stacksAndQueues linkList queue implementation
//due 10/14

#include "jar.linkedListQueue.h"
#include <iostream>
using namespace std;

//Creates and adds nodes to the queue
void linkedListQueue::enqueue(int num){

    //if list is empty
    if(front == NULL){
        node* newNode = new node();
        front=newNode;
        front->setData(num);
        front->setNextPtr(NULL);
        rear = front;
    }
    else{
        //add the new node
        node* newNode = new node();
        rear->setNextPtr(newNode);
        rear=newNode;
        rear->setData(num);
        rear->setNextPtr(NULL);
    }
    
    
}

//removes the first item in the queue
void linkedListQueue::dequeue(){
    node* markODeath;
    markODeath=front;
    front=front->getNextPtr();
    delete(markODeath);
}

//Prints out the data from the nodes.
void linkedListQueue::printList(){
    node* current;
    current = front;
    while(current->getNextPtr()!=NULL){
        cout<<current->getData()<<" ";
        current=current -> getNextPtr();
    }
    cout<<current->getData()<<" ";//even though the last node points to null, it still has data
    cout<<endl;
}

//Constructor.
linkedListQueue::linkedListQueue(){
    front=NULL;
    rear=NULL;
}