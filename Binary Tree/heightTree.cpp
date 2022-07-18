#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

int heightofTree(BinaryTreeNode<int> *root){
    if (root == NULL){
        return 0;
    }
    return max(heightofTree(root->left), heightofTree(root->right)) + 1;
}

// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    int h = heightofTree(root);
    cout << "Height of binary tree is: " << h << endl;
    delete root;
}