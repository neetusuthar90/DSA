#include <iostream>
using namespace std;

int main(){
    int *p = new int;
    delete p;

    p = new int;
    delete p;  // single elemnet

    p = new int[100];
    delete [] p; // array deleetion

    /* memory add every time loop run and waste memory
    while (true){
        int *p = new int;
    }
    while (true){
        int i = 10;
    }

*/

}