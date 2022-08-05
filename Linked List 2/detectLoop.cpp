// Implementation of Floyd’s Cycle-Finding Algorithm: 
#include <iostream>
using namespace std;

class Node
{
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
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

bool detectLoop(Node* head)
{
    Node *slow = head;
    Node *fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast->next->next;
        if(slow == fast){
            return 1;
        }
    }
    return 0;
}

int main(){
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    if (detectLoop(head)){
        cout << "loop found" << endl;
    }
    else{
        cout << "No loop" << endl;
    }
    return 0;
}