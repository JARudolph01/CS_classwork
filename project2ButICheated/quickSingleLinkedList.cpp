#include <iostream>
#include "node.h"
#include "linkedList.h"
using namespace std;



void quickSort(LinkedList* list, int length);
void insertionSort(LinkedList* list, int length);
int partition(LinkedList* list, int first, int last);
void recQuickSort(LinkedList* list, int first, int last);
void swap(LinkedList* list, int first, int second);
Node* indexTranslate(LinkedList* list, int index);

void insertionSortStolen(struct Node **head_ref);



int main()
{
    
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 34; i++)
    {
        //list->add(i);
        list->add((i*i)%(89));
    }
    list->print();
    //std::cout << "List Length: " << list->length << std::endl;

    //swap(list, 9,0);
    //list->print();
    //quickSort(list, list->length);
    //insertionSort(list, list->length);
    insertionSortStolen(&list->head);
    list->print();


    delete list;


    return 0;
}

Node* indexTranslate(LinkedList* list, int index){
    Node* current = list->head;
    for(int i=0; i<index; i++){
        current=current->next;
    }
    return current;
}

void swap(LinkedList* ll, int first, int second)
{
    if(first==second){
        return;
    }

    if(first>second){
        int temp=first;
        first=second;
        second=temp;
    }

    if(first==0)
    {
        Node* tempSecond = indexTranslate(ll, second);
        Node* tempPreSecond = indexTranslate(ll, second-1);
        Node* tempPreFirst = ll->head->next;
        ll->head->next=(indexTranslate(ll, second+1));
        tempPreSecond->next=(ll->head);
        ll->head = tempSecond;
        tempSecond->next=(tempPreFirst);
    }
    else if(second-first==1)
    {
        Node* tempSecond = indexTranslate(ll, second);
        Node* tempPostSecond = indexTranslate(ll, second + 1);
        tempSecond->next=(indexTranslate(ll, first));
        indexTranslate(ll, first)->next=(tempPostSecond);
        indexTranslate(ll, first - 1)->next=(tempSecond);
    }
    else
    {
        Node* tempSecond = indexTranslate(ll, second);
        Node* tempPreSecond = indexTranslate(ll, second-1);
        Node* tempPostSecond = indexTranslate(ll, second+1);
        indexTranslate(ll, second)->next=(indexTranslate(ll, first + 1));
        indexTranslate(ll, second-1)->next=(indexTranslate(ll, first));
        indexTranslate(ll, first)->next=(tempPostSecond);
        indexTranslate(ll, first-1)->next=(tempSecond);
    }
}

void quickSort(LinkedList* list, int length)
{
    recQuickSort(list, 0, length - 1);
}

void recQuickSort(LinkedList* list, int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }
} //end recQuickSort

int partition(LinkedList* list, int first, int last)
{
    Node* pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = indexTranslate(list, first);
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (indexTranslate(list, index)->data < pivot->data)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }

    swap(list, first, smallIndex);

    return smallIndex;
} //end partition



void insertionSort(LinkedList* list, int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
        if (indexTranslate(list, firstOutOfOrder)->data < indexTranslate(list, firstOutOfOrder-1)->data)
        {
            Node* temp = indexTranslate(list, firstOutOfOrder);
            int location = firstOutOfOrder;

            location--;
            while(location > 0 && indexTranslate(list, location-1)->data > temp->data){
                location--;
            }
            

            indexTranslate(list, firstOutOfOrder-1)->next = indexTranslate(list, firstOutOfOrder+1);
            temp->next = indexTranslate(list, location)->next;
            indexTranslate(list, location)->next=temp;
        }
} //end insertionSort






void sortedInsertStolen(struct Node**, struct Node*); 
  
// function to sort a singly linked list using insertion sort 
void insertionSortStolen(struct Node **head_ref) 
{ 
    // Initialize sorted linked list 
    struct Node *sorted = NULL; 
  
    // Traverse the given linked list and insert every 
    // node to sorted 
    struct Node *current = *head_ref; 
    while (current != NULL) 
    { 
        // Store next for next iteration 
        struct Node *next = current->next; 
  
        // insert current in sorted linked list 
        sortedInsertStolen(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted linked list 
    *head_ref = sorted; 
} 
  
/* function to insert a new_node in a list. Note that this 
  function expects a pointer to head_ref as this can modify the 
  head of the input linked list (similar to push())*/
void sortedInsertStolen(struct Node** head_ref, struct Node* new_node) 
{ 
    struct Node* current; 
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        /* Locate the node before the point of insertion */
        current = *head_ref; 
        while (current->next!=NULL && current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 