#include <iostream>
using namespace std;

int main(){
    // constant int
    const int i = 10;
    int const i2 = 12;

    // constant reference from a non constant int
    int j = 13;
    const int &k = j;
    j++;
    cout << k << endl;

    // comstant refeence from a constant int
    int const j2 = 12;
    int const & k2 = j2;
    k2++;

    // reerence from a const int
    int const j3 = 123;
    int &k3 = j3;

}