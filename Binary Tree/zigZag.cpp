#include <iostream>
#include "BinaryTreeNode.h"
#include <stack>
#include <queue>
using namespace std;


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

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    //corner case
    if(root == NULL) {
        return;
    }
    
    stack<BinaryTreeNode<int>*> oddLevel;  // At odd level we print from left to right
    stack<BinaryTreeNode<int>*> evenLevel; // At odd level we print from right to left
    
    oddLevel.push(root); // considering root at level 1
    
    
    while(oddLevel.size() or evenLevel.size()) {
        while(oddLevel.size()) {
        	BinaryTreeNode<int> *top = oddLevel.top();
            cout << top -> data << " ";
            oddLevel.pop();
            
            if(top -> left) {
                evenLevel.push(top -> left);
            }
            if(top -> right) {
                evenLevel.push(top -> right);
            }
            if(oddLevel.empty()){
                cout << endl;
            }
        }
         
        while(evenLevel.size()) {
        	BinaryTreeNode<int> *top = evenLevel.top();     
        	cout << top -> data << " ";
            evenLevel.pop();
            
            if(top -> right) {
                oddLevel.push(top -> right);
            }
            if(top -> left) {
                oddLevel.push(top -> left);
            }
            if(evenLevel.empty()) {
                cout << endl;
            }
        }
    }

    return;
}    
// 
int main(){

    BinaryTreeNode<int> *root = takeInputLevelWise();
    zigZagOrder(root);
    delete root;
}