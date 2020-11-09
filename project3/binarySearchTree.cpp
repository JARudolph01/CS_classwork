//https://www.techiedelight.com/insertion-in-bst/
#include <iostream>

using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int data;
};

Node* insertNode(Node* root, int key)
{
	// if the root is null, create a new node and return it
	if (root == nullptr){
        Node* n = new Node;
        n->left=nullptr;
        n->right=nullptr;
        n->data=key;
        return n;
    }

	else if (key < root->data){
		root->left = insertNode(root->left, key);
    }

	else{
		root->right = insertNode(root->right, key);
    }

	return root;
}

void inorder(Node* root)
{
	if (root == nullptr){
        return;
    }
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void preorder(Node* root)
{
	if (root == nullptr){
        return;
    }
	cout << root->data << " ";
    inorder(root->left);
	inorder(root->right);
}
void postorder(Node* root)
{
	if (root == nullptr){
        return;
    }
    inorder(root->left);
	inorder(root->right);
    cout << root->data << " ";
}


int main(){

    Node* tree=nullptr;

    tree=insertNode(tree, 5);
    tree=insertNode(tree, 3);
    tree=insertNode(tree, 1);
    tree=insertNode(tree, 7);
    tree=insertNode(tree, 7);
    postorder(tree);


    return 0;
}