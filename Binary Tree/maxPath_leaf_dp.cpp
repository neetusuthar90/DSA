#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <climits>
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

int solve(BinaryTreeNode<int> *root, int& res){

    //Base case
    if(root == NULL){
        return 0;
    }

    //Hypothesis
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    //Induction
    int temp = max(l,r)+root->data;
    if(root->left == NULL && root->right == NULL){
        temp = max(temp,root->data);
    }
    int ans = max(temp, l+r+root->data);
    res = max(ans,res);
    return temp;
}

// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int res = INT_MIN;
    cout << "The maxPath of this tree is: " << solve(root,res) << endl;
}