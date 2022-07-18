#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

void mirrorOfTree(BinaryTreeNode<int> *root){
    if (root == NULL){
        return;
    }

    mirrorOfTree(root -> left);
    mirrorOfTree(root -> right);
    swap(root->left, root->right);
    return;
}

// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    mirrorOfTree(root);
    printBTreeLevelWise(root);
    delete root;
}