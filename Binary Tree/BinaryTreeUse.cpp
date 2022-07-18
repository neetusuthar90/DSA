#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;
    if (rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftchild = takeInput();
    BinaryTreeNode<int> *rightchild = takeInput();
    root -> left = leftchild;
    root -> right = rightchild;
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front -> data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
            front -> left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front -> data << endl;
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
            front -> right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printBTree(BinaryTreeNode<int> *root){
    if (root == NULL){
        return;
    }
    cout << root -> data << ":";
    if (root -> left != NULL){
        cout << "L" << root -> left -> data << ", ";
    }
    if (root -> right){
        cout << "R" << root -> right -> data;
    }
    cout << endl;

    printBTree(root -> left);
    printBTree(root -> right);
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

// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1

int main(){

    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    delete root;

    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root -> left = node1;
    root -> right = node2;
    printBTree(root);
    delete root;
    */
}