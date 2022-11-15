#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int data;
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

Node* findNode(Node* root, int key){
    //if root is null
    if (root == NULL){
        return NULL;
    }

    //else find the node
    else if (key < root->data){
        return findNode(root->left,key);
    }
    else if (key > root->data){
        return findNode(root->right,key);
    }
    else{
        return root;
    }
}

//https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
Node* minValueNode(Node* root){
    Node* current = root;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}
//https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
Node* deleteNode(Node* root, int key){
    if (root == NULL){
        return root;
    }
    if (key < root->data){
        // cout << "go left\n";
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data){
        // cout << "go right\n";
        root->right = deleteNode(root->right, key);
    }
    else{
        if (root->left==NULL and root->right==NULL){
            // cout << "no child\n";
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        return root;
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

    int initNumbers [21] = { 70, 60, 92, 50, 63, 82, 94, 40, 68, 72, 88, 98, 20, 45, 65, 75, 85, 96, 35, 80, 78 };

    for(int i=0;i<21;i++){
        tree=insertNode(tree,initNumbers[i]);
    }


    cout<<"inorder: ";
    inorder(tree);
    cout<<"\npreorder: ";
    preorder(tree);
    cout<<"\npostorder: ";
    postorder(tree);
    cout<<endl;


    cout<<"\ndeleting node\n";
    deleteNode(tree,63);


    cout<<"inorder: ";
    inorder(tree);
    cout<<"\npreorder: ";
    preorder(tree);
    cout<<"\npostorder: ";
    postorder(tree);
    cout<<endl;



    return 0;
}