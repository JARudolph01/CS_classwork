#include "node.h"
#include <iostream>
using namespace std;

//Node constructor
node::node(){
    intData=0;
    ptr=NULL;
}

//Sets the Next Pointer
void node::setNextPtr(node* inPtr){
    ptr = inPtr;
}

//Returns the next Pointer
node* node::getNextPtr(){
    return ptr;
}

//Sets the data in the node
void node::setData(int inData){
    intData=inData;
}

//Returns the data from the node
int node::getData(){
    return intData;
}