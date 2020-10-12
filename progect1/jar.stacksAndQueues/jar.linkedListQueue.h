//John Rudolph
//jar.stacksAndQueues linkList queue header
//due 10/14

#ifndef LINKED_LIST_QUEUE
#define LINKED_LIST_QUEUE

#include "jar.node.h"
class linkedListQueue : protected node{
    public:
        void enqueue(int);
        void dequeue();
        void printList();
        linkedListQueue();

    private:
        node *front;
        node *rear;
};

#endif