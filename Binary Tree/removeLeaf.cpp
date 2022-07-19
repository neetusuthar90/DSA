#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

BinaryTreeNode<int>* removeLeafNode(BinaryTreeNode<int>* root){
    if (root == NULL){
        return root;
    }

    if (root -> left == NULL & root -> right == NULL){
        return NULL;
    }

    root -> left = removeLeafNode(root->left);
    root -> right = removeLeafNode(root->right);
    return root;
}

void printNodesWithoutSiblings(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }

    if (root->left == NULL and root->right != NULL){
        cout << root->right->data << " ";
    }
    else if (root -> left != NULL and root->right == NULL){
        cout << root->left->data << " ";
    }
    printNodesWithoutSiblings(root->left);
    printNodesWithoutSiblings(root->right);
}


// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    printNodesWithoutSiblings(root);
    cout << endl;
    BinaryTreeNode<int>* update_root = removeLeafNode(root);
    printBTreeLevelWise(update_root);
    delete root;
}