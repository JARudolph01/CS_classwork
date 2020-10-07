#include "linkedList.h"
#include <iostream>
using namespace std;

//Creates and adds nodes to the list
void linkedList::addNum(int num){

    if(head == NULL){
        node* temp = new node();
        head=temp;
        head->setData(num);
        head->setNextPtr(NULL);
    }
    else{
        next = head;
        while(next->getNextPtr()!=NULL){
            next=next -> getNextPtr();
        }
        node* temp = new node();
        next->setNextPtr(temp);
        next=temp;
        next->setData(num);
        next->setNextPtr(NULL);
    }
}

//Removes a number from the linked list.
void linkedList::removeNum(int num){
    next=head;
    while(next->getNextPtr()!=NULL){ 
        if(next->getNextPtr()->getData()==num){ //if the one after next contains the number

            node* replacement=new node();
            replacement=next->getNextPtr()->getNextPtr();

            //mark the node for deletion. might not be nessisary in hindsight...
            node* markOfDeath;
            markOfDeath=next->getNextPtr();

            next->setNextPtr(replacement);

            delete(markOfDeath);
            cout<<"removed "<<num<<" from linkedList...\n";
            return;
        }
        next=next -> getNextPtr();
    }
    cout<<"cannot delete node. "<<num<<" not in the linkedList. :(\n";
}

//Trys to find a number in the linked list.
void linkedList::findNum(int num){
    next = head;
    while(next->getNextPtr()!=NULL){
        if(next->getData()==num){
            cout<<"yup, "<<num<<" is in the linkedList! ;)\n";
            return;
        }
        next=next -> getNextPtr();
    }
    cout<<"sadly, "<<num<<" is not in the linkedList. :(\n";
}

//Prints out the data from the nodes.
void linkedList::printList(){
    next = head;
    while(next->getNextPtr()!=NULL){
        cout<<next->getData()<<" ";
        next=next -> getNextPtr();
    }
    cout<<next->getData()<<" ";//even though the tail points to null, it still has data
    cout<<endl;
}

//Constructor.
linkedList::linkedList(){
    head=NULL;
    next=NULL;
    current=NULL;

}