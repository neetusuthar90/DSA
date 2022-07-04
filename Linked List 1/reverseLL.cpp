#include <iostream>
using namespace std;
#include "Node.cpp"

class Pair
{
public:
    Node* head;
    Node* tail;
};

Pair reverseLList2 (Node *head){
    // Base case
    if(head == NULL || head -> next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;  
        return ans;   
    }

    Pair smallAns = reverseLList2(head -> next);  
    smallAns.tail -> next = head;
    head -> next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;

    // Time Complexity: O(n)
}

Node* reverse_Better(Node *head){
    return reverseLList2(head).head;
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

Node *reverseLList3(Node *head){
    // Base case
    if(head == NULL || head -> next == NULL){
        return head;     
    }

    Node *smallAns = reverseLList3(head -> next);  
    Node *tail = head -> next;
    tail -> next = head;      
    head -> next = NULL;      
    return smallAns;

    // Time Complexity: O(n^2)
}

Node *reverseLList(Node *head){
    // Base case
    if(head == NULL || head -> next == NULL){
        return head;     
    }

    Node *smallAns = reverseLList(head -> next);  
    Node *temp = smallAns;                         
    while (temp -> next != NULL){
        temp = temp -> next;                        
    }
    temp -> next = head;      
    head -> next = NULL;      
    return smallAns;

    // Time Complexity: O(n)
}

// Main function

int main(){
    Node *head = takeInput();
    print(head);

    Node *reverse = reverseLList3(head);
    print(reverse);

    /*
    Node *reverse = reverse_Better(head);
    print(reverse);
    */
}
