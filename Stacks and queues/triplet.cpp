#include <iostream>
using namespace std;
#include "Pair.cpp"

int main()
{
    Pair<Pair<int, int>, double> p1;
    p1.setY(3.14);
    Pair<int, int> p2;
    p2.setX(10);
    p2.setY(20);
    p1.setX(p2);

    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;

    Pair<int, Pair<double, char>> p3;
    p3.setX(100);
    Pair<double, char> p4;
    p4.setX(67.89);
    p4.setY('N');
    p3.setY(p4);

    cout << p3.getX() << " " << p3.getY().getX() << " " << p3.getY().getY() << endl;

}
