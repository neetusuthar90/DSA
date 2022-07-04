#include <iostream>
using namespace std;
#include "Pair.cpp"

int main()
{

    Pair<int, double> p1;
    p1.setX(10);
    p1.setY(3.14);

    cout << p1.getX() << " " << p1.getY() << endl;
}