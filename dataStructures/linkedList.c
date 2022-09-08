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

void print_length(){
    struct node *current = head;
    int c=0;
    while(current!=NULL){
        c++;
        current=current->next;
    }
    printf("%d\n",c);
}


// int main(){
//     // insert(5,1);
//     // insert(6,2);
//     // insert(7,3);
//     // insert(8,4);

//     // print(head);
//     // printf("\n");


//     // insertAfterKey(8,9,100);
//     // print(head);

//     // printf("\n");

//     // delete(8);
//     // print(head);
//     // printf("\n");

//     // search(7);

int main()
{
 int ch = 0;

 while(ch !=6) {
 int K, k, d;
 printf("1- Print list\n");
 printf("2- Print list length\n");
 printf("3- Insert\n");
 printf("4- Delete\n");
 printf("5- Search\n");
 printf("6- Exit\n");
 printf("\nYour choice: ");
 scanf("%d", &ch);

 if(ch == 1) {
 print();
 } else if(ch == 2) {
 print_length();
 } else if(ch == 3) {
 int ch2 = 0;

 printf("1- Insert first\n");
 printf("2- Insert after key\n");
 printf("\nYour choice: ");
 scanf("%d", &ch2);

 printf("\nEnter key:");
 scanf("%d", &k);

 printf("\nEnter data:");
 scanf("%d", &d);

 if(ch2 == 1) {
 insert(k, d);
 } else if(ch2 == 2) {
 scanf("%d", &K);
 insertAfterKey(K,k,d);
 }

 } else if(ch == 4) {
 printf("\nEnter key:");
 scanf("%d", &k);
 delete(k);
 } else if(ch == 5) {
 printf("\nEnter key:");
 scanf("%d", &k);
 search(k);
 }
 }

 return 0;
}