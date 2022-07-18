#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

int numNodes(BinaryTreeNode<int> *root){
    if (root == NULL){
        return 0;
    }

    return 1 + numNodes(root -> left) + numNodes(root -> right);
}

// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    int totalNodes = numNodes(root);
    cout << "Total nodes in binary tree are " << totalNodes << endl;
    delete root;
}