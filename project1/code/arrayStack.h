#ifndef ARRAY_STACK
#define ARRAY_STACK

class arrayStack{
    public:
        void push(int);
        void pop();
        void printList();
        arrayStack();

    private:
        int arr[20];
        int bottom;
};

#endif