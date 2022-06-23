#include <iostream>
using namespace std;
#include "Student.cpp"

int main(){
    // Create object statically
    Student s1,s2;

    s1.rollnumber = 102;

    // Create object dynamically
    Student *s3 = new Student;
    
    s3 ->rollnumber = 111;
    s1.display();
    s3 -> display();
    

}