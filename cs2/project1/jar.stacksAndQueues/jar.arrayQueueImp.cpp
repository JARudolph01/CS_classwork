//John Rudolph
//jar.stacksAndQueues array queue implementation
//due 10/14

#include <iostream>
#include "jar.arrayQueue.h"
using namespace std;

void arrayQueue::enqueue(int num){
    arr[rear+1]=num;
    rear++;
}

void arrayQueue::dequeue(){
    arr[front]=0;
    front++;
}

void arrayQueue::printList(){
    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

arrayQueue::arrayQueue(){
    rear=-1;
    front=0;
}