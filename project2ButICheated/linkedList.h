#ifndef LINKEDLIST
#define LINKEDLIST
#include "node.h"

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void print();
};
#endif