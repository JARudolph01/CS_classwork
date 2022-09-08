#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
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

void insertAfterKey(int key, int newKey, int data){
    struct node *current = head;
    while(current!=NULL){
        if(current->key==key){

            struct node *new = (struct node*)malloc(sizeof(struct node)); //allocate memory

            //add data
            new->key = key;
            new->data = data;

            //link
            new->next = current->next;
            current->next = new;

            return;
        }
        current=current->next;
    }
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
    //if head itself needs to be deleted
    if(head->key=key){
        struct node *tmp = head;
        head=head->next;
        free(tmp);
        return;
    }
    struct node *current = head;
    struct node *next = head->next;
    while(current!=NULL){
        if(next->key==key){
            //link around
            struct node *tmp = current->next;
            current->next = next->next;
            free(tmp);
            return;
        }
        current=next;
        next=next->next;
    }
}

void search(int key){
    if(head->key==key){
        int data = head->data;
        printf("%d\n",data);
        return;
    }
    struct node *next = head;
    while(next!=NULL){
        if(next->key==key){
            int data = next->data;
            printf("%d\n",data);
            return;
        }
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


    insertAfterKey(8,9,100);
    print(head);

    printf("\n");

    delete(8);
    print(head);
    printf("\n");

    search(7);


    return 0;
}