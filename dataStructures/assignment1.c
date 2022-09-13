#include <stdio.h>
#include <stdlib.h>

struct node{
    int reading_date;
    int reading_time;
    int value;
    struct node *next;
};

struct node *head = NULL;
struct current *current = NULL;

void insert(int reading_date, int reading_time, int value){
    struct node *new = (struct node*)malloc(sizeof(struct node)); //allocate memory

    //add data
    new->reading_date = reading_date;
    new->reading_time = reading_time;
    new->value = value;

    //link
    new->next = head;
    head = new;
}


void print(){
    struct node *next = head;
    while(next!=NULL){
        int reading_date = next->reading_date;
        int reading_time = next->reading_time;
        int value = next->value;
        printf("date:%d ",reading_date);
        printf("time:%d ",reading_time);
        printf("value:%d\n",value);
        next=next->next;
    }
}
/*
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
*/
void print_length(){
    struct node *current = head;
    int c=0;
    while(current!=NULL){
        c++;
        current=current->next;
    }
    printf("%d\n",c);
}

int main()
{
//frontend stolen and tweaked from blackboard
 int ch = 0;

 while(ch !=6) {
int rd,rt,d;
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

 printf("\nEnter date:");
 scanf("%d", &rd);

printf("\nEnter time:");
 scanf("%d", &rt);

 printf("\nEnter value:");
 scanf("%d", &d);

 if(ch2 == 1) {
 insert(rd,rt,d);
 }

 } else if(ch == 4) {
 printf("\nEnter key:");
//  delete(k);
 } else if(ch == 5) {
 printf("\nEnter key:");
//  search(k);
 }
 }

 return 0;
}