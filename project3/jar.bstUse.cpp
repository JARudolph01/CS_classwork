#include <iostream>
#include "jar.node.h" 

using namespace std;

int main(){
    Node* tree=NULL;

    tree=tree->insertNode(tree, 5);
    tree=tree->insertNode(tree, 3);
    tree=tree->insertNode(tree, 1);
    tree=tree->insertNode(tree, 7);
    tree=tree->insertNode(tree, 7);


    cout<<"inorder: ";
    tree->inorder(tree);
    cout<<"\npreorder: ";
    tree->preorder(tree);
    cout<<"\npostorder: ";
    tree->postorder(tree);
    cout<<endl;
    return 0;
}