#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
class linkedList : protected node{
    public:
        void addNum(int);
        void removeNum(int);
        void findNum(int);
        void printList();
        linkedList();

    private:
        node *head;
        node *next;
        node *current;
};

#endif