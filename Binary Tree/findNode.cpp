#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

bool searchNode(BinaryTreeNode<int> *root, int k){
    if (root == NULL){
        return false;
    }
    if (root->data == k){
        return true;
    }
    return searchNode(root ->left, k) or searchNode(root->right,k);
}

// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    int k;
    cout << "Enter the search node: ";
    cin >> k;
    cout << boolalpha << searchNode(root, k) << endl;
    delete root;
}