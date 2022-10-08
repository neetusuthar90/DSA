#include <iostream>
#include <string>
using namespace std;
#include <unordered_map>

int main(){
    int a = 3; int b = 3;
    cout << &a << " " << &b << endl;
    int c = 7;
    cout << &c;
    return 0;
}