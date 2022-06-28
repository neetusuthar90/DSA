#include <iostream>
using namespace std;
#include "student2.cpp"

int main(){
    char name[] = "abcd";
    student2 s1(20,name);
    s1.display();

    name[3] = 'e';
    student2 s2(22,name);
    s2.display();
    s1.display();

}