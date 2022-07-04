#include <iostream>
using namespace std;
#include "Node.cpp"

void print(Node *head){
    Node *current = head;
    if(head == NULL){
        return;
    }

    while (current != NULL)
    {
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << endl;
    
    /*
    Node *temp = head;
    if (temp -> prev == NULL){
        while (temp != NULL)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
    else if (temp -> next == NULL){
        while (temp != NULL)
        {
            cout << temp -> data << " ";
            temp = temp -> prev;
        }    
    }
    */
     
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
            newNode -> prev = tail;
            tail = newNode;
            tail -> next = NULL;
        }
        cin >> data;
    }
    return head;
}

Node *insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);

    if (i == 0){
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
        return head;
    }
    int count = 0;
    Node *temp = head;
    while(temp != NULL && count < i-1){
        temp = temp -> next;
        count ++;
    }
    if (temp != NULL){
        temp -> prev = newNode;
        newNode -> next = temp -> next;
        temp -> next = newNode;
        newNode -> prev = temp;
    }
    return head;
}

int main(){

    Node *head = takeInput();
    print(head);
    int i, data;
    cin >> i >> data;
    head = insertNode(head,i,data);
    print(head);

    /*
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    
    n2 -> prev = n1;
    n3 -> prev = n2;
    n4 -> prev = n3;
    print(head);
    */

}
