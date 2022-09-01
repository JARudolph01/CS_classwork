/*
John
Joshua
Landis
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile;
ofstream outFile;


class Node{
public:
    Node* left;
    Node* right;
    int data;
};    

Node* insertNode(Node* root, int key){
	// if the root is null, create a new one
	if (root == nullptr){
        Node* n = new Node;
        n->left=nullptr;
        n->right=nullptr;
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
	if (root == nullptr){
        return;
    }
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void postorder(Node* root){
	if (root == nullptr){
        return;
    }
    inorder(root->left);
	inorder(root->right);
    cout << root->data << " ";
}



int main(){

    inFile.open("intsSortFunLab.txt");
    outFile.open("yeet.txt");

    Node* tree=nullptr;

    int arrayLen=0;

    
    int trash;
    while(!inFile.eof()){
        arrayLen++;
        inFile>>trash;
    }
    cout<<"it worked\n";
    inFile.close();
    inFile.open("intsSortFunLab.txt");
    int garray[arrayLen];
    int i=-1;
    while(!inFile.eof()){
        i++;
        inFile>>garray[i];
    }


     
    tree.insertNode((garray[arrayLen/2]))


    cout<<"inorder: ";
    postorder(tree);
    cout<<endl<<arrayLen<<endl;

    return 0;
}