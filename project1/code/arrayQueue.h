#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

class arrayQueue{
    public:
        void enqueue(int);
        void dequeue();
        void printList();
        arrayQueue();

    private:
        int arr[20];
        int front;
        int rear;
};

#endif