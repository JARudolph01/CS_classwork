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
    //std::cout << "List Length: " << list->length << std::endl;

    //swap(list, 9,0);
    //list->print();
    quickSort(list, list->length);
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
    if(first==0||second==0)
    {
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
        else if(second == 0)
        {
            Node* tempFirst = indexTranslate(ll, first);
            Node* tempPreFirst = indexTranslate(ll, first-1);
            Node* tempPreSecond = ll->head->next;
            ll->head->next=(indexTranslate(ll, first+1));
            tempPreFirst->next=(ll->head);
            ll->head = tempFirst;
            tempFirst->next=(tempPreSecond);
        }
    }
    else if(first-second==1||second-first==1)
    {
        if(first>second)
        {
            Node* tempFirst = indexTranslate(ll, first);
            Node* tempPostFirst = indexTranslate(ll, first + 1);
            tempFirst->next=(indexTranslate(ll, second));
            indexTranslate(ll, second)->next=(tempPostFirst);
            indexTranslate(ll, second - 1)->next=(tempFirst);
        }
        else if(second>first)
        {
            Node* tempSecond = indexTranslate(ll, second);
            Node* tempPostSecond = indexTranslate(ll, second + 1);
            tempSecond->next=(indexTranslate(ll, first));
            indexTranslate(ll, first)->next=(tempPostSecond);
            indexTranslate(ll, first - 1)->next=(tempSecond);
        }
    }
    else
    {
        if(first>second)
        {
            Node* tempFirst = indexTranslate(ll, first);
            Node* tempPreFirst = indexTranslate(ll, first-1);
            Node* tempPostFirst = indexTranslate(ll, first+1);
            indexTranslate(ll, first)->next=(indexTranslate(ll, second + 1));
            indexTranslate(ll, first-1)->next=(indexTranslate(ll, second));
            indexTranslate(ll, second)->next=(tempPostFirst);
            indexTranslate(ll, second-1)->next=(tempFirst);
        }
        else if(second>first)
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
