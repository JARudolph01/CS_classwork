#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *back = NULL;

//add a node to the back of the queue
void push(int data){
    //allocate memory
    struct node *new = (struct node*)malloc(sizeof(struct node)); 

    //add data
    new->data = data;

    //link
    if(front==NULL){
        front=new;
        back=new;
    }
    else{
        back->next = new;
        back=new;
    }
}

int pop(){
    int data = front->data;
    struct node *tmp=front;
    front=front->next;
    free(tmp);
    return data;
}

//print all nodes in the queue
void print(){
    struct node *current = front;

    while(current!=NULL){
        //get values
        int data = current->data;

        //print values
        printf("data: %d\n",data);

        current=current->next;
    }
} 

int main(){
    printf("wtf");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    print();

    return 0;
}