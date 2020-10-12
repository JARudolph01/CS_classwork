//John Rudolph
//jar.stacksAndQueues linkList stack header
//due 10/14

#ifndef LINKED_LIST_STACK
#define LINKED_LIST_STACK

#include "jar.node.h"
class linkedListStack : protected node{
    public:
        void push(int);
        void pop();
        void printList();
        linkedListStack();

    private:
        node *head;
};

#endif