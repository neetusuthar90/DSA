#include <iostream>
using namespace std;

void f(const int * p){
    (*p)++;  
}

int main(){
    int const i = 10;

    int const *p = &i;
   // (*p)++; // Error: constant canot be change

    int j = 11;
    int * p3 = &j;
    f(p3);

    int const *p2 = &j;
    cout << *p2 << endl;
    j++;
    //(*p2)++; // Error: constant canot be change
    cout << *p2 << endl;
       
}