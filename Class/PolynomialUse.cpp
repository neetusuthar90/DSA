#include <iostream>
using namespace std;
#include "Polynomial_class.cpp"

int main(){
    int n1,n2,choice;
    cin >> n1;
    
    int *deg1 = new int[n1];
    int *coef1 = new int[n1];

    for(int i = 0; i < n1; i++){
        cin >> deg1[i];
    }
    for(int i = 0; i < n1; i++){
        cin >> coef1[i];
    }

    Polynomial_class p1;
    for(int i = 0; i < n1; i++){
        p1.setcoff(deg1[i],coef1[i]);
    }

    cin >> n2;
    
    int *deg2 = new int[n2];
    int *coef2 = new int[n2];

    for(int i = 0; i < n2; i++){
        cin >> deg2[i];
    }
    for(int i = 0; i < n2; i++){
        cin >> coef2[i];
    }

    Polynomial_class p2;
    for(int i = 0; i < n2; i++){
        p2.setcoff(deg2[i],coef2[i]);
    }

    cin >> choice;
    
    p1.print();
    p2.print();
    
    Polynomial_class p3;
    switch (choice){

        // Add
        case 1:
        p3 = p1 + p2;
        p3.print();
        break;

        // Subtract
        case 2:
        p3 = p1 - p2;
        p3.print();
        break;

        // Multiplication
        case 3:
        p3 = p1*p2;
        p3.print();
        break;

        // Copy Constructor
        Polynomial_class p4(p1);
        
        // Copy assignment opertor
        Polynomial_class p5;
        p5 = p2;

    }

}