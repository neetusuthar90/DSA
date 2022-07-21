#include "BinaryTreeNode.h"

class BinarySearchTreeNode
{
private:
    BinaryTreeNode<int>* root;
public:
    // Constructor
    BinarySearchTreeNode(){
        root = NULL;
    }

    // Destructor
    ~BinarySearchTreeNode(){
        delete root;
    }

private:
    bool hasData(int data, BinaryTreeNode<int>* node){
        if (node == NULL){
            return false;
        }

        if (node->data == data){
            return true;
        }
        else if (data < node->data){
            return hasData(data, node->left);
        }
        else{
            return hasData(data, node->right);
        }
    }

public:
    bool hasData(int data){
        return hasData(data, root);
    }

private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
        if (node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (data <= node->data){
            node -> left = insert(data, node->left);
        }
        else if (data > node->data){
            node -> right = insert(data, node->right);
        }

        return node;
    }

public:
    void insert(int data){
        this -> root = insert(data, root);
    }

private:
    void print(BinaryTreeNode<int>* root){
        if (root == NULL){
            return;
        }

        cout << root -> data << ": ";
        if (root -> left != NULL){
            cout << "L" << root->left->data << ",";
        }
        if (root -> right != NULL){
            cout << "R" << root -> right->data << endl;
        }
    
        print(root->left);
        print(root->right);
    }

public:
    void print(){
        return print(root);
    }

private:
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* root){
        if (root == NULL){
            return NULL;
        }

        if (data < root ->data){
            root -> left = deleteData(data, root -> left);
            return root;
        }
        else if (data > root->data){
            root -> right = deleteData(data, root->right);
            return root;
        }

        else{
            if (root->left == NULL and root->right == NULL){
                delete root;
                return NULL;
            }
            else if (root -> left == NULL){
                BinaryTreeNode<int>* temp = root->right;
                root -> right = NULL;
                delete root;
                return temp;
            }
            else if (root -> right == NULL){
                BinaryTreeNode<int>* temp = root->left;
                root -> left = NULL;
                delete root;
                return temp;
            }
            else{
                BinaryTreeNode<int>* newroot = root -> right;
                while(newroot->left != NULL){
                    newroot = newroot -> left;
                }
                int rightMin = newroot -> data;
                root -> data = rightMin;
                root -> right = deleteData(rightMin, root->right);
                return root;

            }
        }
    }
public:
    void deleteData(int data){
        root = deleteData(data, root);
    }

};
