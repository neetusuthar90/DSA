#include <iostream>
#include <cstring> 
using namespace std;
class student2
{
private:
    int age;
    char *name;
public:
    student2(int age, char *name){
        this -> age = age;
        // Shallow copy
        //this -> name = name;

        // Deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

    }

    void display(){
        cout << name << " " << age << endl;
    }
};

