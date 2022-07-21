#include <iostream>
using namespace std;
#include "binTreeInput_Print.cpp"

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node (T data){
        this -> data = data;
        this -> next = NULL;
    }

};

pair<Node<int>*,Node<int>*> helper(BinaryTreeNode<int>* root){
    if (root == NULL){
        pair<Node<int>*,Node<int>*> p1;
        p1.first = NULL;
        p1.second = NULL;
        return p1;
    }

    // p1.first = head and p1.second = tail;
    Node<int>* node = new Node<int>(root->data);
    pair<Node<int>*,Node<int>*> left = helper(root->left);
    pair<Node<int>*,Node<int>*> right = helper(root -> right);

    if (left.first == NULL){
        left.first = node;
        left.second = node;
    }
    else{
        left.second -> next = node;
        left.second = node;
    }

    if (right.first == NULL){
        right.first = node;
        right.second = node;
    }
    else{
        node->next = right.first;
    }
    return {left.first, right.second};

}

Node<int>* build_LL(BinaryTreeNode<int>* root){
    return helper(root).first;
}

void print(Node<int>* head){
    Node<int>* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    Node<int>* head = build_LL(root);
    print(head);
}