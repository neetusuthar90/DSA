// PRE AND POST ORDER TRAVERSAL PRINTING IN TREE

#include <iostream>
#include <queue>
using namespace std;
#include "TreeNode.h"

TreeNode<int> *takeInputLevelwise(){
    int rootData;
    cout << "Enter root data: "<< endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);

    while (pendingNode.size() != 0)
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << "Enter number of children of " << front -> data << endl;
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++){
            int childData;
            cout << "Enter " << i << "th child of " << front -> data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front -> children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}

void printTreeLevelwise(TreeNode<int> *root){
    queue<TreeNode<int>*> node;
    node.push(root);
    while(node.size() != 0){
        TreeNode<int> *front = node.front();
        node.pop();
        cout << front ->data << ":";
        for (int i = 0; i < front->children.size(); i++){
            cout << front->children[i]->data << ",";
            node.push(front->children[i]);
        }
        cout << endl;
    }
}

void preorder(TreeNode<int> *root){
    if (root == NULL){
        return ;
    }

    cout << root -> data << endl;
    for (int i = 0; i < root->children.size(); i++){
        preorder(root -> children[i]);
    }
}

void postorder(TreeNode<int> *root){
    if (root == NULL){
        return ;
    }
    for (int i = 0; i < root->children.size(); i++){
        postorder(root -> children[i]);
    }
    cout << root -> data << endl;
}


// 1 3 2 3 4 1 5 2 6 7 0 0 2 8 9 0 0 0
int main(){
    TreeNode<int> *root = takeInputLevelwise();
    cout << "Level wise tree print: " << endl;
    printTreeLevelwise(root);
    cout << "Pre Order tree printing: " << endl;
    preorder(root);
    cout << "Post order tree printing: " << endl;
    postorder(root);
}