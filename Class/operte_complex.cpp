#include <iostream>
using namespace std;
#include "Complexnumber.cpp"

int main(){

    int a1,a2,b1,b2;

    cin >> a1 >> b1;
    cin >> a2 >> b2;

    Complexnumber c1(a1,b1);
    Complexnumber c2(a2,b2);

    cout << "c1: ";
    c1.print();
    cout << "c2: ";
    c2.print();

    int choice;
    cin >> choice;

    if (choice == 1){
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2){
        c1.multiply(c2);
        c1.print();
    }
    else{
        return 0;
    }

}