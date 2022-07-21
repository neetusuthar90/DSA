#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

bool searchElement(BinaryTreeNode<int>* root, int k){
    if (root == NULL){
        return false;
    }

    bool flag = false;
    if (root->data < k){
        flag = searchElement(root->right, k);
    }
    else if (root->data > k){
        flag = searchElement(root->left,k);
    }
    else{
        return true;
    }

    return flag;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printBTreeLevelWise(root);
    int k;
    cout << "Enter serch element: ";
    cin >> k;
    cout << searchElement(root,k) << endl;
    
}