#include <iostream>
using namespace std;

class People
{

public:
    int id;
    int age;

private:
    char name;

public:

    // Default destructor
    ~People(){
        cout << "Destructor called!" << endl;
    }

    // Default Constructor
    People(){

    }

    // Parameterized Constructor

    People(int a){
        cout << "Constructor 2 called!" << endl;
        age = a;
    }

    People(int a, int i){
        cout <<  "Constructor 3 called!" << endl;
        age = a;
        id = i;
    }

    void display(){
        cout << age << " " << id << endl;
    }

    
};
