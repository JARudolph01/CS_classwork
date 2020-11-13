#ifndef NODE
#define NODE 

using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int data;
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
    Node* insertNode(Node* root, int key);
};


#endif