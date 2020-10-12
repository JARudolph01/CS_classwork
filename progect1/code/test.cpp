#include <iostream>
#include "linkedListStack.h"
#include "linkedListQueue.h"
#include "arrayStack.h"
#include "arrayQueue.h"

using namespace std;



int main () 
{

    
    linkedListQueue linkQueue;
    linkQueue.enqueue(5);
    linkQueue.enqueue(6);
    linkQueue.enqueue(7);
    linkQueue.printList();
    linkQueue.dequeue();
    linkQueue.printList();
    linkQueue.dequeue();
    linkQueue.printList();

    cout<<endl;

    linkedListStack linkStack;
    linkStack.push(7);
    linkStack.push(8);
    linkStack.push(9);
    linkStack.printList();
    linkStack.pop();
    linkStack.printList();
    
    cout<<endl;

    arrayStack arrStack;
    arrStack.push(7);
    arrStack.push(8);
    arrStack.push(9);
    arrStack.printList();
    arrStack.pop();
    arrStack.printList();

    cout<<endl;

    arrayQueue arrQueue;
    arrQueue.enqueue(5);
    arrQueue.enqueue(6);
    arrQueue.enqueue(7);
    arrQueue.printList();
    arrQueue.dequeue();
    arrQueue.printList();
    arrQueue.dequeue();
    arrQueue.printList();

    return 0; 
} 