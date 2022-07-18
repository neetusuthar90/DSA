// Construct tree from preorder and inorder tree travelsal
#include <iostream>
#include <queue>
using namespace std;
#include "BinaryTreeNode.h"

// Construct array
void array(int a[], int N){
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
}

void printBTreeLevelWise(BinaryTreeNode<int> *root){
    if (root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> node;
    node.push(root);
    while (node.size() != 0)
    {
        BinaryTreeNode<int> *front = node.front();
        node.pop();
        cout << front->data << ": ";
        if (front -> left != NULL){
            cout << "L" << front -> left -> data << ",";
            node.push(front->left);
        }
        if (front -> right != NULL){
            cout << "R" << front -> right -> data;
            node.push(front->right);
        }
        cout << endl;
    }
}

BinaryTreeNode<int>* helper(int ino[], int post[], int inS, int inE, int postS, int postE){
    if(inS > inE){
        return NULL;
    }
    int rootValue = post[postE];
    int rootIndex = 0;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootValue);
    for(int i = inS; i <= inE; i++){
        if (rootValue == ino[i]){
            rootIndex = i;
            break;
        }
    }
    
    int lInS = inS;
    int lInE = rootIndex-1;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS ;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;
    
    root->left = helper(ino, post, lInS, lInE, lPostS, lPostE);
    root->right = helper(ino,post,rInS, rInE, rPostS, rPostE);

    return root;
}

BinaryTreeNode<int>* buildTree(int ino[], int post[], int size){
    return helper(ino, post ,0, size-1, 0, size-1);
}

// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main(){
    int ino[] = {4,2,1,5,3,6};
    int post[] = {4,2,5,6,3,1};
    //int ino[] = {4,2,5,1,6,3,7};
    //int post[] = {4,5,2,6,7,3,1};
    BinaryTreeNode<int>* root = buildTree(ino, post, 6);
    printBTreeLevelWise(root);
    delete root;
}