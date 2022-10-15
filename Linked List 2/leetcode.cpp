#include <iostream>
#include <cmath>
using namespace std;
#include "Node.cpp"

void print(Node *head){
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


Node* deleteMiddle(Node* head) {
    Node* temp = head;
    int n = 0;
    while(temp != NULL){
        n += 1;
        temp = temp -> next;
    }
    int i = ceil(n/2);
    int count = 0;
    Node* node = head;
    while (node != NULL && count < i-1)
    {
        node = node -> next;
        count++;
    }
    if(node != NULL){
        Node *a = node -> next;
        Node *b = a -> next;
        node -> next = b;
        delete a;
    }
    return head;   
}

int main(){
    Node* n1 = new Node(1);
    Node *head = n1;
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    print(head);
    head = deleteMiddle(head);
    print(head);
}