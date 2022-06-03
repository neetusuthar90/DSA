#include <iostream>
using namespace std;
int main(){
    int a[] = {2,3,4};
    char b[] = "abcd";
    cout << a << endl;
    cout << b << endl;

    char *c = &b[0];
    cout << c << endl;
}
