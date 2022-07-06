#include <iostream>
using namespace std;
#include <queue>
#include <stack>

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while ((!s.empty()))
    {
        q.push(s.top());
        s.pop();
    }
    return;
}

void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    int N, data;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        q.push(data);
    }

    reverseQueue(q);
    print(q);

}