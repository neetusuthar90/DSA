#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node (int data){
        this -> data = data;
        next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* intersection(Node *head1, Node *head2){
    Node *head;
    while (head1 != NULL || head2 != NULL)
    {
        Node *temp = head;
        Node *temp1 = head1;
        Node *temp2 = head2;
        if(temp1 -> data < temp2->data){
            temp1 = temp1 -> next;
        }
        if(temp1 -> data > temp2->data){
            temp2 = temp2 -> next;
        }
        Node *n1 = new Node(temp1 -> data);
        head = n1;
        temp = temp -> next;
    }
    return(head); 
}

Node *intersection_sorted(Node *head1, Node *head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }

    if (head1 -> data < head2 -> data){
        return(head1->next, head2);
    }

    if (head1 ->data > head2->data){
        return(head1, head2->next);
    }

    Node *head;
    head -> data = head1 -> data;
    head -> next = intersection_sorted(head1 -> next, head2->next);
    return head;
}

int main(){
    Node *n1 = new Node(1);
    Node *head1 = n1;
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(6);
    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;

    Node *m1 = new Node(2);
    Node *head2 = m1;
    Node *m2 = new Node(4);
    Node *m3 = new Node(6);
    Node *m4 = new Node(10);
    m1 -> next = m2;
    m2 -> next = m3;
    m3 -> next = m4;

    cout << "Linked List 1:" << endl;
    print(head1);
    cout << "Linked list 2:" << endl;
    print(head2);

    Node * head = intersection_sorted(head1, head2);
    print(head);
    return 0;
}