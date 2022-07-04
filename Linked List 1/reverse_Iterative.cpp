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

Node* reverseIter(Node *head){
    // Base case
    if(head == NULL || head -> next == NULL){
        return head;     
    }
    
    Node *pre = NULL;
    Node *cur = head;
    Node *nx;
    while (cur != NULL)
    {
        nx = cur -> next; 
        cur -> next = pre;
        pre = cur;
        cur = nx;
    }
    return pre;

}

int main(){

    Node *head = takeInput();
    print(head);
    Node *rev = reverseIter(head);
    print(rev);
}