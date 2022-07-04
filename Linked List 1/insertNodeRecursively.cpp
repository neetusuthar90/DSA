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

Node* insert_recursive(Node *head, int i, int data){
    Node *newNode = new Node(data);
    if (head == NULL){
        return head;
    }
    
    if (i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }

    Node *temp = insert_recursive(head->next, i-1, data);
    head -> next = temp;
    return head;

}

Node* delete_recursive(Node *head, int i){
    if (head == NULL){
        return head;
    }

    if (i == 0){
        Node* a = head -> next;
        delete head;
        head = a;
        return head;
    }

    Node *temp = delete_recursive(head->next, i-1);
    head -> next = temp;
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
    
    // Linked List
    Node *head = takeInput();
    print(head);
    
    /*
    int i, data;
    cin >> i >> data;
    head = insert_recursive(head,i,data);
    print(head);
    */

   int i;
   cin >> i;
   head = delete_recursive(head,i);
   print(head);
    
}