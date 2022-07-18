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

BinaryTreeNode<int>* helper(int ino[], int pre[], int inS, int inE, int preS, int preE){
    if(inS > inE){
        return NULL;
    }
    int rootValue = pre[preS];
    int rootIndex = 0;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootValue);
    for(int i = inS; i <= inE; i++){
        if (rootValue == ino[i]){
            rootIndex = i;
            break;
        }
    }
    
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    
    root->left = helper(ino, pre, lInS, lInE, lPreS, lPreE);
    root->right = helper(ino,pre,rInS, rInE, rPreS, rPreE);

    return root;
}

BinaryTreeNode<int>* buildTree(int ino[], int pre[], int size){
    return helper(ino, pre ,0, size-1, 0, size-1);
}

// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main(){
    int pre[] = {1,2,4,5,3,6,8,9,7};
    int ino[] = {4,2,5,1,8,6,9,3,7};
    BinaryTreeNode<int>* root = buildTree(ino, pre, 9);
    printBTreeLevelWise(root);
    delete root;
}