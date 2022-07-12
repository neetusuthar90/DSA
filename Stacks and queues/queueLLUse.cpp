#include <iostream>
using namespace std;
#include "queue_LL.h"

int main(){
    queue_LL<int> q;
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
    cout << q.getSize() << endl;
    cout << q.isempty() << endl;
}