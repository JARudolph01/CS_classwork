#include <iostream>

using namespace std;

class Node
{
public:
    Node* next;
    int data;
};


class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void print();
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED";
}

void LinkedList::add(int data){
    Node* node = new Node();

    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::print(){
    Node* current = this->head;

    int i = 1;
    while(current->next){
        //std::cout << i << ": " << current->data << " ";
        cout<<current->data<<" ";
        current = current->next;
        i++;
    }
    cout<<current->data<<"\n";
}

void quickSort(LinkedList* list, int length);
int partition(LinkedList* list, int first, int last);
void recQuickSort(LinkedList* list, int first, int last);
void swap(LinkedList* list, int first, int second);
Node* indexTranslate(LinkedList* list, int index);




int main()
{
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 100; i++)
    {
        //list->add(i);
        list->add((i*i)%(89));
    }
    list->print();
    std::cout << "List Length: " << list->length << std::endl;

    cout<<indexTranslate(list, 0)->data<<endl;

    //quickSort(list, list->length);
    //list->print();

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



void swap(LinkedList* list, int first, int second)
{
    Node* temp = indexTranslate(list, first);

    indexTranslate(list, first);

    //temp = list[first];
    //list[first] = list[second];
    //list[second] = temp;

    
} //end swap


/*
void quickSort(LinkedList* list, int length)
{
    recQuickSort(LinkedList* list, 0, length - 1);
} //end quickSort


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
    int pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }

    swap(list, first, smallIndex);

    return smallIndex;
} //end partition
*/