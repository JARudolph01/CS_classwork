#include <iostream>
#include "linkedList.h"
using namespace std;



int main () 
{
    linkedList list;
    list.enqueue(5);
    list.enqueue(6);
    list.enqueue(7);
    list.printList();

    list.dequeue();
    list.printList();

    list.dequeue();
    list.printList();

    list.dequeue();
    list.printList();

    return 0; 
} 