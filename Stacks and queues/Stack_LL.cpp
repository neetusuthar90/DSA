#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node (T data){
        this -> data = data;
        next = NULL;
    }

};

template <typename T>
class Stack_LL
{
private:
    Node<T> *head;
    int size;

public:
    Stack_LL(){
        head = NULL;
        size = 0;
    }

    int getsize(){
        return size;
    }

    bool isempty(){
        return size == 0;
    }

    void push(T data){
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL){
            head = newNode;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
        size++;
    }

    T top(){
        if (head == NULL){
            return -1;
        }
        return head -> data;
    } 

    T pop(){
        if (head == NULL){
            return -1;
        }

        int temp = head -> data;
        head = head -> next;
        size --;
        return temp;
    }

};

