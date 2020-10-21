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
    if(head){
        this->front->next=node;
    }
    else{
        node->data = data;
        node->next = this->front;
        this->front = node;
        this->head->next=front;
    }
    this->length++;
}

void LinkedList::print(){
    Node* current = this->head;
    cout<<current->data<<endl;
    int i = 1;
    while(current!=head){
        std::cout << i << ": " << current->data << std::endl;
        current = current->next;
        i++;
    }
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

