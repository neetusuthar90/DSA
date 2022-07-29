#include <iostream>
using namespace std;

class BST{
public:
   int data;
   BST* left;
   BST* right;
   int height;  
};

int max(int a, int b);

// Calculate height
int height(BST* node){
    if (node == NULL){
        return 0;
    }
    return node->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
BST* newNode(int data ){
    BST* node = new BST();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Right Roatate
BST* rightRotation(BST* y){
    BST* x = y->left;
    BST* T2 = x->right;

    // Perform roation
    x->right = y;
    y->left = T2;

    //updates height
    y -> height = max(height(y->left), height(y->right)) + 1;
    x -> height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// LEFT ROATION
BST* leftRotation(BST* x){
    BST* y = new BST();
    BST* T2 = new BST();

    //Perform rotation
    y->left = x;
    x->right = T2;

    //updates height
    y -> height = max(height(y->left), height(y->right)) + 1;
    x -> height = max(height(x->left), height(x->right)) + 1;

    return y; 
}

int getBalance(BST* node){
    if (node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

BST* insert(int data, BST* node){
    if (node == NULL){
        return newNode(data);
    }

    if (data <= node->data){
        node -> left = insert(data, node->left);
    }
    else if (data > node->data){
        node -> right = insert(data, node->right);
    }

    return node;

    node->height = 1 + max(height(node->left),height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data){
        return rightRotation(node);
    }
    // Right Right Case
    if (balance < -1 && data > node->right->data){
        return leftRotation(node);
    }
    // Left Right Case
    if (balance > 1 && data > node->left->data){
        node -> left = leftRotation(node->left);
        return rightRotation(node);
    }
    // Right left Case
    if (balance < -1 && data < node->right->data){
        node -> right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

void preOrder(BST *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main()
{
    BST *root = NULL;
     
    /* Constructing tree given in
    the above figure */
    root = insert(10,root);
    root = insert(20,root);
    root = insert(30,root);
    root = insert(40,root);
    root = insert(50,root);
    root = insert(5 ,root);
    
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
     
    return 0;
}
