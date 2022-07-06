#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queue_LL
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    queue_LL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isempty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    T front()
    {
        if (isempty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return head->data;
    }

    T dequeue()
    {
        if (isempty())
        {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};
