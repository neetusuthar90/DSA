#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

int heightofTree(BinaryTreeNode<int> *root){
    if (root == NULL){
        return 0;
    }
    return max(heightofTree(root->left), heightofTree(root->right)) + 1;
}

int diameter(BinaryTreeNode<int>* root){
    if (root == NULL){
        return 0;
    }

    int option1 = heightofTree(root->left) + heightofTree(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1,max(option2, option3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh,rh);
    int diameter = max(lh+rh, max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;
    delete root;
}