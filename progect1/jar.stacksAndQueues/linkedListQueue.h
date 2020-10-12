#ifndef LINKED_LIST_QUEUE
#define LINKED_LIST_QUEUE

#include "node.h"
class linkedListQueue : protected node{
    public:
        void enqueue(int);
        void dequeue();
        void printList();
        linkedListQueue();

    private:
        node *head;
        node *tail;
};

#endif