#include <iostream>
using namespace std;
#include "Node.cpp"

int indexNode(Node *head, int x){
    // Base case
    if (head == NULL){
        return -1;
    }
    if (head -> data == x){
        return 0;
    }
    
    int ans = indexNode(head -> next, x);
    if (ans == -1){
        return ans;
    }
    else{
        return ans +1;
    }
}

Node* takeInput(){   // O(n) 
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);  
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node *head = takeInput();
    print(head);
    int x;
    cin >> x;
    int ind = indexNode(head,x);
    cout << ind << endl;
}