#include <iostream>
#include <climits>
#include <utility>
using namespace std;
#include "binTreeInput_Print.cpp"

pair<int,int> minMaxNodes(BinaryTreeNode<int>* root){
    if (root == NULL){
        return{INT_MAX,INT_MIN};
    }

    // pair.first = min and pair.second = max.
    pair<int,int> left = minMaxNodes(root->left);
    pair<int,int> right = minMaxNodes(root->right);


    //corner case
    if(left.first == INT_MAX and right.first == INT_MAX and left.second == INT_MIN and right.second == INT_MIN) {
        return {root -> data, root -> data};
    }
    
    int cur_min = min(left.first, right.first);
    int cur_max = max(left.second, right.second);

    if (root->data < cur_min){
        return {root->data, cur_max};
    }
    else if (root->data > cur_max){
        return {cur_min, root->data};
    }
    else{
        return {cur_min, cur_max};
    }


}

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBTreeLevelWise(root);
    pair<int,int> p = minMaxNodes(root);
    cout << "Minimum: " << p.first << endl;
    cout << "Maximum: " << p.second << endl;
    delete root;
}