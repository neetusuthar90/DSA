#include<iostream>
using namespace std;
#include <queue>

int main(){
    priority_queue<int> pq; // For inbuilt MAX Heap
    // priority_queue<int, vector<int>, greater<int>> pq; // For inbuilt MIN Heap
    pq.push(100);
    pq.push(10);
    pq.push(21);
    pq.push(172);
    pq.push(3);
    pq.push(11);

    cout << "Size: " << pq.size() << endl;
    cout << "Max: " << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}