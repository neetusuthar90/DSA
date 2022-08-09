#include <iostream>
using namespace std;
#include "maxHeap.h"

int main(){
    maxHeap p;
    p.insert(15);
    p.insert(2);
    p.insert(20);
    p.insert(9);
    p.insert(0);
    p.insert(100);

    cout << p.getSize() << endl;
    cout << p.getMax() << endl;

    while (!p.isEmpty())
    {
        cout << p.removeMax() << " ";
    }

    cout << endl;
}