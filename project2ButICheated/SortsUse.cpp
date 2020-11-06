/*  John Rudolph
    Sorting Use file
    11/8/2020
*/
#include <iostream>
#include "node.h"
#include "linkedList.h"
#include <fstream>



using namespace std;

void quickSort(LinkedList* list, int length);
void insertionSort(LinkedList* list, int length);
int partition(LinkedList* list, int first, int last);
void recQuickSort(LinkedList* list, int first, int last);
void swap(LinkedList* list, int first, int second);
Node* indexTranslate(LinkedList* list, int index);

void insertionSortStolen(struct Node **head_ref);

int comparisons = 0;
int dataMoves = 0;

int main()
{
    ofstream outfile;
    outfile.open("output.txt");



    LinkedList* list = new LinkedList();
    for (int i = 0; i < 30; i++)
    {
        //list->add(i);
        list->add((i*i)%(89));
    }
    list->print();
    //std::cout << "List Length: " << list->length << std::endl;

    //swap(list, 9,0);
    //list->print();
    quickSort(list, list->length);
    //insertionSort(list, list->length);
    //insertionSortStolen(&list->head);
    list->print();
    cout<<comparisons<<"\n";
    outfile<<comparisons<<"\n";
    cout<<dataMoves;
    outfile<<dataMoves<<"\n";

    outfile.close();

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

void swap(LinkedList* ll, int first, int second){
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
        dataMoves+=4;
    }
    else if(second-first==1)
    {
        Node* tempSecond = indexTranslate(ll, second);
        Node* tempPostSecond = indexTranslate(ll, second + 1);
        tempSecond->next=(indexTranslate(ll, first));
        indexTranslate(ll, first)->next=(tempPostSecond);
        indexTranslate(ll, first - 1)->next=(tempSecond);
        dataMoves+=3;
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
        dataMoves+=4;
    }
    comparisons++;
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
    comparisons++;
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
        comparisons++;

    swap(list, first, smallIndex);

    return smallIndex;
} //end partition

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

void sortedInsertStolen(Node** head_ref, Node* new_node) 
{ 
    Node* current; 
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        dataMoves++;
        *head_ref = new_node; 
        dataMoves++;
    } 
    else
    { 
        /* Locate the node before the point of insertion */
        current = *head_ref; 
        while (current->next!=NULL && current->next->data < new_node->data) 
        { 
            current = current->next; 
            comparisons++;
        } 
        new_node->next = current->next; 
        current->next = new_node; 
        dataMoves+=2;
    } 
    comparisons++;
} 