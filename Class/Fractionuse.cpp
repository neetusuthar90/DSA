#include <iostream>
using namespace std;
#include "Fraction.cpp"

int main(){

    Fraction f1(10,2);
    Fraction f2(15,4);

    cout << "f1: ";
    f1.print();
    cout << "f2: ";
    f2.print();

    int choice;
    cin >> choice;

    if (choice == 1){
        f1.add(f2);
        f1.print();
    }
    else if (choice == 2){
        f1.multiply(f2);
        f1.print();
    }
    else 
    {
        return 0;
    }
}