// 3 Ways to check weather a given binary tree is binary search tree or not

#include <iostream>
#include <climits>
using namespace std;
#include "binTreeInput_Print.cpp"

int maximum(BinaryTreeNode<int>* root){
    if (root == NULL){
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
    if (root == NULL){
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){
    if (root == NULL){
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

class IsBstReturn{
    public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBstReturn isBST2(BinaryTreeNode<int>* root){
    if (root == NULL){
        return {true, INT_MAX, INT_MIN};
    }

    IsBstReturn leftOutput = isBST2(root -> left);
    IsBstReturn rightOutput = isBST2(root -> right);

    IsBstReturn output;
    output.minimum = min(root -> data, min(leftOutput.minimum, rightOutput.minimum));
    output.maximum = max(root -> data, max(leftOutput.maximum, rightOutput.maximum));
    output.isBST = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

    return output;
}
// Time Complexity: O(n)

bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if (root == NULL){
        return true;
    }

    if (root->data < min || root->data > max){
        return false;
    }
    bool isLeftOk = isBST3(root->left, min, root->data - 1);
    bool isRightOk = isBST3(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printBTreeLevelWise(root);
    cout << boolalpha << isBST(root) << endl;
    cout << boolalpha << isBST3(root) << endl;
    //IsBstReturn output = isBST2(root);
    //cout << boolalpha << output.isBST << endl;
}