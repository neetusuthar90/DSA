#include <iostream>
using namespace std;
#include <stack>

int main(){

    // Inbuilt Stack
    stack<char> s;
    s.push(64);
    s.push(65);
    s.push(66);
    s.push(66);
    s.push(67);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.empty() << endl;
      
}
