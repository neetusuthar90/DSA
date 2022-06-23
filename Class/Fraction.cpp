#include <iostream>
using namespace std;

class Fraction
{
private:
    int nume;
    int deno;

public:
    Fraction(int nume, int deno){
        this -> nume = nume;
        this -> deno = deno;
    }

    void print(){
        cout << this -> nume << " / " << deno << endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(nume,deno);
        
        for (int i = 1; i < j; i++){
            if (this->nume % i == 0 && deno % i == 0){
                gcd = i;
            }
        }

        this -> nume = this -> nume / gcd;
        this -> deno = this -> deno / gcd;
    }

    void add(Fraction const &f2){
        int lcm = deno * f2.deno;
        int x = lcm/deno;
        int y = lcm/f2.deno;

        int numerator = x*nume + (y*f2.nume);

        nume = numerator;
        deno = lcm;

        simplify();

    }
    
    void multiply(Fraction f2){
        nume = nume*f2.nume;
        deno = deno*f2.deno;

        simplify();
    }
     
    
};

