#include <iostream>

using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int data;
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
};

Node* insertNode(Node* root, int key){
	// if the root is null, create a new one
	if (root == NULL){
        Node* n = new Node;
        n->left=NULL;
        n->right=NULL;
        n->data=key;
        return n;
    }
    //else, insert the node
	else if (key < root->data){
		root->left = insertNode(root->left, key);
    }
	else{
		root->right = insertNode(root->right, key);
    }
	return root;
}

void inorder(Node* root){
	if (root == NULL){
        return;
    }
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void preorder(Node* root){
	if (root == NULL){
        return;
    }
	cout << root->data << " ";
    preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root){
	if (root == NULL){
        return;
    }
    postorder(root->left);
	postorder(root->right);
    cout << root->data << " ";
}


int main(){
    Node* tree=NULL;

    tree=insertNode(tree, 5);
    tree=insertNode(tree, 3);
    tree=insertNode(tree, 1);
    tree=insertNode(tree, 7);
    tree=insertNode(tree, 7);


    cout<<"inorder: ";
    inorder(tree);
    cout<<"\npreorder: ";
    preorder(tree);
    cout<<"\npostorder: ";
    postorder(tree);
    cout<<endl;
    return 0;
}