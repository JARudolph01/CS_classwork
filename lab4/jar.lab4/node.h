#ifndef NODE
#define NODE
class node{
    public:
        node();
        void setNextPtr(node*);
        node* getNextPtr();
        void setData(int);
        int getData();
        
    private:
        node *ptr;
        int intData;
};
#endif