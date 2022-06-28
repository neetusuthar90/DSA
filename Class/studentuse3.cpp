#include <iostream>
using namespace std;
#include "Student3.cpp"

int main(){
    Student3 s1;
    Student3 s2,s3,s4;

    //cout << s1.age << " " << s1.rollnumber << endl;

    //cout << Student3 :: totalstudents << endl;

    cout << Student3 :: gettotalstudents() << endl;

}