#include <iostream>
using namespace std;

int main(){
    int i = 65;
    char c = i;

    int *p = &i;
    char * pc = (char*)p;  // converting address of i to character and try to read only one char
    
    cout << p << endl;
    cout << pc << endl;
    cout << *p << endl;
    cout << *pc << endl;
    cout << *(pc +1) << endl;

}