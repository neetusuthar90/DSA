#include <iostream>
using namespace std;
#include "Node.cpp"

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

Node *SwapNodes(Node *head, int i, int j){
    if (i == j){
        return head;
    }
    int count = 0;
    Node *cur = head;
    while (cur != NULL)
    {
        if (count == i){

        }
        else{
            
        }
    }
    
}

int main(){

}