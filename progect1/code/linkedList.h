#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
class linkedList : protected node{
    public:
        void enqueue(int);
        void dequeue();
        void printList();
        linkedList();

    private:
        node *head;
        node *tail;
};

#endif