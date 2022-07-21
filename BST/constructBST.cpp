#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

BinaryTreeNode<int>* helper(int *arr, int sI, int eI){
    if (arr == NULL){
        return NULL;
    }
    
    if (sI > eI){
        return NULL;
    }

    int mid = sI + (eI - sI)/2;
    int rootValue = arr[mid];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootValue);
    root -> left = helper(arr, sI, mid - 1);
    root -> right = helper(arr, mid + 1, eI);

    return root;
}

BinaryTreeNode<int>* buildBST(int *arr, int n){
    return helper(arr, 0, n-1);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    BinaryTreeNode<int>* root = buildBST(arr,10);
    printBTreeLevelWise(root);
}