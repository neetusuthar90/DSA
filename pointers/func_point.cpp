#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void function_increment(int *p)
{
    p = p + 1;
}

void increment(int *p)
{
    (*p)++;
}

int main()
{
    int i = 10;
    int *p = &i;
    print(p);
    cout << p << endl;
    function_increment(p);
    cout << p << endl;
    cout << *p << endl;
    increment(p);
    cout << *p << endl;
}