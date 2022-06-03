#include <iostream>
using namespace std;

void increment(int& i){
    i++;
}
 // bad practice
int& f(int n){
    int a = n;
    return a;
}

// bad pracrice
int* f2(){
    int i = 10;
    return &i;
}

int main(){
    int i;
    i = 10;
    int& j = i;
    
    int& k2 = f(i);
     
    int k = 100;
    j = k;
    cout << i << endl;

}