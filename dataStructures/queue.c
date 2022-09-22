#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *back = NULL;

//add a node to the back of the queue
void insert(int data){
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
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);

    print();

    return 0;
}