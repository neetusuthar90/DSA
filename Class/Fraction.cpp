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
        
        for (int i = 1; i <= j; i++){
            if (this->nume % i == 0 && deno % i == 0){
                gcd = i;
            }
        }

        this -> nume = this -> nume / gcd;
        this -> deno = this -> deno / gcd;
    }

    Fraction add(Fraction const &f2) {
        int lcm = deno * f2.deno;
        int x = lcm/deno;
        int y = lcm/f2.deno;

        int numerator = x*nume + (y*f2.nume);

        //nume = numerator;
        //deno = lcm;
        Fraction fnew(numerator,lcm);
        
        fnew.simplify();
        return fnew;
    }
    
    void multiply(Fraction const f2)  {
        nume = nume*f2.nume;
        deno = deno*f2.deno;

        simplify();
    }
     
    Fraction operator+(Fraction const &f2) const {
        int lcm = deno * f2.deno;
        int x = lcm/deno;
        int y = lcm/f2.deno;

        int numerator = x*nume + (y*f2.nume);

        //nume = numerator;
        //deno = lcm;
        Fraction fnew(numerator,lcm);
        
        fnew.simplify();
        return fnew;
    }

    Fraction operator*(Fraction const f2) const {
        int n = nume*f2.nume;
        int d = deno*f2.deno;
        Fraction fnew(n,d);
        fnew.simplify();
        return fnew;
    }

    bool operator==(Fraction const f2) const {
        return (nume == f2.nume && deno == f2.deno);
    }
    
    //pre-icrement
    Fraction& operator++(){
      nume = nume + deno;
      simplify();
      return *this;
    }

    //Post - increment
    Fraction operator++(int){
        Fraction fnew(nume,deno);
        nume = nume + deno;
        simplify();
        fnew.simplify();
        return fnew;

    }

    Fraction& operator+=(Fraction const f2){
        int lcm = deno * f2.deno;
        int x = lcm/deno;
        int y = lcm/f2.deno;

        int numerator = x*nume + (y*f2.nume);
        nume = numerator;
        deno = lcm;
        simplify();

        return *this;
    }
};

