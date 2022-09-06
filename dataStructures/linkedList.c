#include <stdio.h>
#include <stdlib.h>

struct node{
    int key; //no idea why we need this
    int data;
    struct node *next;
};

struct node *head = NULL;
struct current *current = NULL;

void insert(int key, int data){
    struct node *new = (struct node*)malloc(sizeof(struct node)); //allocate memory

    //add data
    new->key = key;
    new->data = data;

    //link
    new->next = head;
    head = new;
}

void print(){
    struct node *next = head;
    while(next!=NULL){
        int data = next->data;
        printf("%d\n",data);
        next=next->next;
    }
}

void delete(int key){
    struct node *current = head;
    struct node *next = head->next;
    while(current!=NULL){
        if(next->key==key){
            //link around
            current->next = next->next;
            return;
        }
        int data = current->data;
        printf("%d\n",data);
        current=next;
        next=next->next;
    }
}


int main(){
    insert(5,1);
    insert(6,2);
    insert(7,3);
    insert(8,4);

    print(head);
    printf("\n");

    delete(7);
    print(head);


    return 0;
}