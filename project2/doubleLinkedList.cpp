#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
public:
    Node* next;
    Node* previous;
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
    if(this->head != NULL){
    this->head->previous = node;
    }
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
    //std::cout << i << ": " << current->data << std::endl;
    cout<<current->data<<"\n";


    //cout<<"reverse reverse!\n";

    /*
    while(current){
        std::cout << i << ": " << current->data << std::endl;
        current = current->previous;
        i--;
    }
    */
}
void insertionSort(LinkedList* list, int length);
int main()
{
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 100; ++i)
    {
        //list->add(i);
        list->add((i*i)%(8765));
    }
    list->print();
    std::cout << "List Length: " << list->length << std::endl;

    insertionSort(list, list->length);
    list->print();

    delete list;


    return 0;
}


void insertionSort(LinkedList* list, int length)
{
    Node* firstOutOfOrder = list->head->next;

    while(firstOutOfOrder){
        if(firstOutOfOrder->data<firstOutOfOrder->previous->data){
            int temp=firstOutOfOrder->data;
            Node* location=firstOutOfOrder;

            do{
                location->data=location->previous->data;
                location=location->previous;
            }while(location!=list->head && location->previous->data>temp);
            location->data=temp;
        }
        firstOutOfOrder=firstOutOfOrder->next;
    }
}