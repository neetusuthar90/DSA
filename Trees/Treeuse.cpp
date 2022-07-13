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


TreeNode<int> *takeInput(){
    int rootData;
    cout << "Enter data: "<< endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++){
        TreeNode<int> *child = takeInput();
        root -> children.push_back(child);
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

void printTree(TreeNode<int> *root){

    if (root == NULL){
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++){
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++){
        printTree(root->children[i]);
    }
}

void deleteTree(TreeNode<int> *root){
    for (int i = 0; i < root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

int main(){
    //TreeNode<int> *root = takeInput();
    TreeNode<int> *root = takeInputLevelwise();
    //printTree(root);
    printTreeLevelwise(root);

    delete root;  // This will call destructor

    //deleteTree(root);
    /*
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    root -> children.push_back(node1);
    root -> children.push_back(node2);
    printTree(root);
    */

}