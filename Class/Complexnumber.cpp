#include <iostream>
using namespace std;

class Complexnumber
{
private:
    int real;
    int img;
public:
    
    Complexnumber(int real, int img){
        this -> real = real;
        this -> img = img;
    }

    void print(){
        cout << real << " + " << img << "i" << endl;
    }

    void plus(Complexnumber const &c2){
        real = real + c2.real;
        img = img + c2.img;
    }

    void multiply(Complexnumber const &c2){
        int x = (real * c2.real) - (img * c2.img);
        int y = (real * c2.img) + (img * c2.real);

        real = x;
        img = y;
    }
};

