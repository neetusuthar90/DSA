#include <iostream>
using namespace std;
#include "Stack_LL.cpp"

int main(){
    Stack_LL<char> s;
    s.push(64);
    s.push(65);
    s.push(66);
    s.push(67);
    s.push(68);
    s.push(69);

    cout << s.getsize() << endl;
    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.top() << endl;
    cout << s.isempty() << endl;

}
