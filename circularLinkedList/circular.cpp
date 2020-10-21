#include <iostream>
using namespace std;

class Node
{
public:
    Node* next;
    int data;
    int priority;
};

class LinkedList
{
public:
    int length;
    Node* head;
    Node* front;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void print();
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
    this->front=head;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED\n";
}

void LinkedList::add(int data){
    Node* node = new Node();
    node->data=data;
    node->priority=0;
    if(!this->head){
        this->front=node;
        this->head=node;
    }
    else{
        this->front->next=node;
    }
    node->next=this->head;
    this->head=node;
    this->length++;
}

void LinkedList::print(){
    Node* current = this->front->next;
    int i = 1;
    while(current!=front){
        std::cout << i << ": " << current->data << std::endl;
        current = current->next;
        i++;
    }
    std::cout << i << ": " << current->data << std::endl;
}
int main()
{
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 100; ++i)
    {
        list->add(i);
    }
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    delete list;
    return 0;
}

