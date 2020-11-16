#include <iostream>
#include <fstream>
#include "jar.node.h" 

using namespace std;

ifstream inFile;


int main(){
    Node* tree=NULL;

    inFile.open("ints.txt");
    while(!inFile.eof()){
        int temp;
        inFile>>temp;
        tree=tree->insertNode(tree, temp);
    }
    inFile.close();

    cout<<"inorder: ";
    tree->inorder(tree);
    cout<<"\npreorder: ";
    tree->preorder(tree);
    cout<<"\npostorder: ";
    tree->postorder(tree);
    cout<<endl;

    return 0;
}