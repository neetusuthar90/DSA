#include <iostream>
using namespace std;
#include "queue_Array.h"

int main(){
    queue_Array<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.front() << endl;
    cout << q.getsize() << endl;
    cout << q.isempty() << endl;
}