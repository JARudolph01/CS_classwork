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
int partition(LinkedList* list, int first, int last);
void recQuickSort(LinkedList* list, int first, int last);
void swap(LinkedList* list, int first, int second);
Node* indexTranslate(LinkedList* list, int index);
void insertionSort(LinkedList* list);

int comparisons = 0;
int dataMoves = 0;

int main()
{
    ofstream outfile;
    outfile.open("comparisons.txt");

    ifstream inFile;
    inFile.open("ints.txt");

    //generate 2 lists for insersion and quick
    LinkedList* list1 = new LinkedList();
    LinkedList* list2 = new LinkedList();
    for (int i = 0; i < 30; i++)
    {
        int temp;
        inFile>>temp;
        list1->add(temp);
        list2->add(temp);
        
    }
    inFile.close();

    quickSort(list1, list1->length);
    cout<<"quick sort comparisons: "<<comparisons<<"\n";
    outfile<<"quick sort comparisons: "<<comparisons<<"\n";
    cout<<"quick sort data moves: "<<dataMoves<<"\n";
    outfile<<"quick sort data moves: "<<dataMoves<<"\n";

    //reset comparisons and data moves for next sort
    comparisons=0;
    dataMoves=0;

    insertionSort(list2);

    cout<<"insertion sort comparisons: "<<comparisons<<"\n";
    outfile<<"insertion sort comparisons: "<<comparisons<<"\n";
    cout<<"insertion sort data moves: "<<dataMoves<<"\n";
    outfile<<"insertion sort data moves: "<<dataMoves<<"\n";

    outfile.close();

    delete list1;
    delete list2;

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
}

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
}

void sortedInsert(struct Node**, struct Node*); 

void insertionSort(LinkedList* list) 
{ 
    struct Node **head_ref = &list->head;
    struct Node *sorted = NULL; 
    struct Node *current = *head_ref; 

    while (current != NULL) 
    { 
        struct Node *next = current->next; 
        sortedInsert(&sorted, current); 
        current = next; 
    } 
  
    *head_ref = sorted; 
} 

void sortedInsert(Node** head_ref, Node* new_node) 
{ 
    Node* current; 
    //special case for head
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        dataMoves++;
        *head_ref = new_node; 
        dataMoves++;
    } 
    else
    { 
        //find the target node
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