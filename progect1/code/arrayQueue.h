#ifndef ARRAY_STACK
#define ARRAY_STACK

class arrayQueue{
    public:
        void enqueue(int);
        void dequeue();
        void printList();
        arrayQueue();

    private:
        int arr[];
};

#endif