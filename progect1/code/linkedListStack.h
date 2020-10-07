#ifndef LINKED_LIST_STACK
#define LINKED_LIST_STACK

#include "node.h"
class linkedList : protected node{
    public:
        void push(int);
        void pop();
        void printList();
        linkedList();

    private:
        node *head;
};

#endif