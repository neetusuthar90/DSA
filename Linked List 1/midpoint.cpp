#include <iostream>
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

int length(Node *head){
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp -> next;
        count++;
    }
    return count; 
}


int lenRecursily(Node *head){
    // Base case
    if (head == NULL){
        return 0;
    }

    int len;
    len = lenRecursily(head -> next);
    return len + 1;
}

Node* midpoint(Node *head){
    Node *slow = head;
    Node *fast = head -> next;

    while ( fast != NULL and fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* mergetwosortLL(Node *head1, Node *head2){
    Node *fh = NULL;
    Node *fT = NULL;
    
    if (head1 == NULL){
        return head2;
    }
    if (head2 == NULL){
        return head1;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data){
            if ( fh == NULL)
            {
                fh = head1;
                fT = head1;
            }
            else
            {
                fT -> next = head1;
                fT = head1;
            }
            head1 = head1 -> next;
        }

        else
        {
            if ( fh == NULL)
            {
                fh = head2;
                fT = head2;
            }
            else
            {
                fT -> next = head2;
                fT = head2;
            }
            head2 = head2 -> next;
        }
           
    }
    
    if (head1 != NULL){
        fT -> next = head1;
    }
    if (head2 != NULL){
        fT -> next = head2;
    }
    return fh;
}

Node* mergeSort(Node *head){

    // Base case
    if (head == NULL || head -> next == NULL){
        return head;
    }

    Node *mid;
    mid = midpoint(head);
    Node *head1 = head;
    Node *head2 = mid->next;
    mid -> next = NULL;

    // Recursion Call
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    // Merge two sorted LL
    Node* updatedHead = mergetwosortLL(head1, head2);
    return updatedHead;
    
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



int main(){

    Node *head = takeInput();
    print(head);
    
    int len = lenRecursily(head);
    cout << len << endl;

    //head = mergeSort(head);
    //print(head);

    /*
    Node *head1 = takeInput();
    Node *head2 = takeInput();

    Node *merge_head = mergetwosortLL(head1, head2);
    print(merge_head);
    */

    /*
    Node *head = takeInput();
    Node *mid;
    mid = midpoint(head);
    cout << mid->data << endl;
    */
  
}