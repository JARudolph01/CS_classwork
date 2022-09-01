/*
John Rudolph
Project 3 node implementation
11/20
*/

#include <iostream>
#include "jar.node.h"

using namespace std;

void Node::inorder(Node* root){
	if (root == NULL){
        return;
    }
	Node::inorder(root->left);
	cout << root->data << " ";
	Node::inorder(root->right);
}
void Node::preorder(Node* root){
	if (root == NULL){
        return;
    }
	cout << root->data << " ";
    Node::preorder(root->left);
	Node::preorder(root->right);
}
void Node::postorder(Node* root){
	if (root == NULL){
        return;
    }
    Node::postorder(root->left);
	Node::postorder(root->right);
    cout << root->data << " ";
}


Node* Node::insertNode(Node* root, int key){
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