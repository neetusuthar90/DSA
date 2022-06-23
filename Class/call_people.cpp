#include <iostream>
using namespace std;
#include "People.cpp"

int main(){

    People p1;
    p1.display();

    People *p2 = new People;
    cout << "Parametrized constructor demo:" << endl;
    People p3(12);
    p3.display();

    People *p4 = new People(11);
    p4->display();

    People p5(15,1234);
    cout << "p5 :";
    p5.display();

    People p6(p5);  // Copy Constructor
    cout << "p6 :";
    p6.display();

    delete p2;
    delete p4;



} 