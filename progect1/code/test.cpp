#include <iostream>
#include "linkedList.h"
using namespace std;



int main () 
{
    linkedList list;
    list.addNum(5);
    list.addNum(6);
    list.removeNum(6);
    list.printList();
    return 0; 
} 