#include <iostream>
using namespace std;
#include "Stack_array.h"

int main()
{

    Stack_array<int> s;

    s.push(64);
    s.push(65);
    s.push(66);
    s.push(66);
    s.push(67);

    cout << s.size() << endl;
    cout << s.top() << endl;

    s.pop();
    s.pop();

    cout << s.top() << endl;
    cout << s.isempty() << endl;
}
