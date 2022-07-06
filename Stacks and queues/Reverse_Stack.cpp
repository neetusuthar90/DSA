#include <iostream>
using namespace std;
#include <queue>
#include <stack>

void reverse_Stack(stack<int> &s1, stack<int> &s2){
    int temp = s1.top();
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    //s1.push(temp);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return;
}

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main(){
    int N, data;
    cin >> N;
    stack<int> s1;
    stack<int> s2;
    for (int i = 0; i < N; i++){
        cin >> data; 
        s1.push(data);
    }
    reverse_Stack(s1,s2);
    print(s1);
}