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

void delete(int date, int time){
    //if head itself needs to be deleted
    if(head->reading_date=date && head->reading_time==time){
        struct node *tmp = head;
        head=head->next;
        free(tmp);
        return;
    }
    struct node *current = head;
    struct node *next = head->next;
    while(current!=NULL){
        if(next->reading_date==date && next->reading_time==time){
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

void deleteAllWithValue(int value){
    //if head itself needs to be deleted

    while (head->value==value){
        struct node *tmp = head;
        head=head->next;
        printf("deleted head\n");
        free(tmp);
        if(head==NULL){
            return;
        }
    }
    
    struct node *current = head;
    while(current!=NULL){
        while (current->next!=NULL && current->next->value==value ){
            
            //link around
            struct node *tmp = current->next;
            current->next = current->next->next;
            printf("deleted body\n");
            free(tmp);
        }
        current=current->next;
    }
    
}



void search(int value){
    if(head->value==value){
        int reading_date = head->reading_date;
        int reading_time = head->reading_time;
        int value = head->value;
        printf("date:%d ",reading_date);
        printf("time:%d ",reading_time);
        printf("value:%d\n",value);
        return;
    }
    struct node *next = head;
    while(next!=NULL){
        if(next->value==value){
            int reading_date = next->reading_date;
            int reading_time = next->reading_time;
            int value = next->value;
            printf("date:%d ",reading_date);
            printf("time:%d ",reading_time);
            printf("value:%d\n",value);
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

int main(){
 int ch = 0;
 insert(1,2,3);
 insert(1,2,3);
 insert(4,5,6);
 insert(1,2,3);
 insert(1,2,3);
 insert(1,2,3);

printf("Welcome to sensory reading system\n");

 while(ch !=8) {
int rd,rt,d;
printf("1- Add a sensory reading\n");
printf("2- Remove a sensory reading based on specific date and time\n");
printf("3- Remove all sensory readings with a specific value\n");
printf("4- Search for a specific sensory reading value\n");
printf("5- Print information of all sensory readings\n");
printf("6- Print the number of sensory readings saved in the system\n");
printf("7- Print the average of all sensory reading values\n");
printf("8- Exit\n");
printf("\nYour choice: ");
scanf("%d", &ch);

//insert
if(ch == 1) {

 printf("\nEnter date:");
 scanf("%d", &rd);

printf("\nEnter time:");
 scanf("%d", &rt);

 printf("\nEnter value:");
 scanf("%d", &d);

 insert(rd,rt,d);
} 

//remove specific
else if(ch==2){
    printf("\nEnter date:");
    scanf("%d", &rd);

    printf("\nEnter time:");
    scanf("%d", &rt);

    delete(rd,rt);
} 

//remove all
else if(ch==3){
    printf("\nEnter value:");
    scanf("%d", &d);
    deleteAllWithValue(d);
}

//search
else if(ch == 4) {
  printf("\nEnter value:");
    scanf("%d", &d);
    search(d);
 }

 //print all
else if(ch == 5) {
 print();
 }

 //print number
 else if(ch == 6) {
    print_length();
 }

 //print ave
 else if(ch == 7) {
 continue;
 }

 //exit
 else if(ch == 8) {
    return 0;
 }

 } 
 return 0;
 }