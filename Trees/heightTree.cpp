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

int heightOfTree(TreeNode<int> *root){
    int height = 0;
    if (root == NULL){
        return height;
    }
    for (int i = 0; i < root -> children.size(); i++){
        int temp =  heightOfTree(root -> children[i]);
        height = max(temp,height);
    }
    return height + 1;
}

int main(){
    TreeNode<int> *root = takeInputLevelwise();
    printTreeLevelwise(root);
    int h = heightOfTree(root);
    cout << h << endl;
    
}