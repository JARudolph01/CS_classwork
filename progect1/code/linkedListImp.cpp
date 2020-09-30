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

//Removes a number from the linked list.
void linkedList::removeNum(int num){
    current=head;
    while(current->getNextPtr()!=NULL){ 
        if(current->getNextPtr()->getData()==num){ //if the next node contains the number

            //get the node after the one to be deleted
            node* replacement=new node();
            replacement=current->getNextPtr()->getNextPtr();

            //mark the node for deletion.
            node* markOfDeath;
            markOfDeath=current->getNextPtr();

            //point to the new next node
            current->setNextPtr(replacement);

            //free up the memory
            delete(markOfDeath);

            cout<<"removed "<<num<<" from linkedList\n";
            return;
        }
        current=current -> getNextPtr();
    }
    cout<<"cannot delete node. "<<num<<" not in the linkedList. :(\n";
}

//Trys to find a number in the linked list.
void linkedList::findNum(int num){
    current = head;
    while(current->getNextPtr()!=NULL){
        if(current->getNextPtr()->getData()==num){
            cout<<"yup, "<<num<<" is in the linkedList! ;)\n";
            return;
        }
        current=current -> getNextPtr();
    }
    cout<<"sadly, "<<num<<" is not in the linkedList. :(\n";
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