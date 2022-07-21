#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

void printElement(BinaryTreeNode<int>* root, int S, int E){
    if (root == NULL){
        return;
    }

    if ( S < root->data){
        printElement(root->left, S, E);
    }
    if (root->data >= S and root -> data <= E){
        cout << root->data << " ";
    }
    if(root->data < E){
        printElement(root->right, S, E);
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printBTreeLevelWise(root);
    int S,E;
    cout << "Enter the range value: ";
    cin >> S >> E;
    printElement(root, S,E);
    
}