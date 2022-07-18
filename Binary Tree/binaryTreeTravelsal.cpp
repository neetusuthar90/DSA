#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

void inorder(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    delete root;
}