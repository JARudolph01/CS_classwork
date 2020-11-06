/*  John Rudolph
    Sorting linked list implementation
    11/6/2020
*/
#include <iostream>
#include "node.h"
#include "linkedList.h"
using namespace std;

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED";
}

void LinkedList::add(int data){
    Node* node = new Node();
    
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::print(){
    Node* current = this->head;

    int i = 1;
    while(current->next){
        //std::cout << i << ": " << current->data << " ";
        cout<<current->data<<" ";
        current = current->next;
        i++;
    }
    cout<<current->data<<"\n";
}