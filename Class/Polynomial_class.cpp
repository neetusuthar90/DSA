#include <iostream>
using namespace std;

class Polynomial_class
{
private:
    int *dataCof;
    int size;
public:

    // Default Constructor
    Polynomial_class(){
        dataCof = new int[3];
        size = 3;
        for (int i= 0; i < size; i++){
            dataCof[i] = 0;
        }
    }
    
    // Set Value
    void setcoff(int index, int ele){
        if (index >= size){
            int capacity = index + 1;
            int *newdatacoff = new int[capacity];
            for (int i = 0; i < index ; i++){
                newdatacoff[i] =dataCof[i];
            }
            for (int i = size; i < capacity; i++){
                newdatacoff[i] = 0;
            }
            delete [] dataCof;
            dataCof = newdatacoff;
            size = capacity;
        }
        dataCof[index] = ele;
    }

    // Copy Constructor
    Polynomial_class(Polynomial_class const &d){
        this -> dataCof = new int[d.size];
        for (int i = 0; i < d.size; i++){
            this -> dataCof[i] = d.dataCof[i];
        } 
        this -> size = d.size;
    }

    // Copy Constructor
    void operator=(Polynomial_class const &d){
        this -> dataCof = new int[d.size];
        for (int i = 0; i < d.size; i++){
            this -> dataCof[i] = d.dataCof[i];
        } 
        this -> size = d.size;
    }

    Polynomial_class operator+(Polynomial_class const &p2){
        Polynomial_class pnew;
        pnew.size = max(size, p2.size);
        for (int i = 0; i < size; i++){
            pnew.dataCof[i] = dataCof[i] + p2.dataCof[i];
        }
        return pnew;
    }

    Polynomial_class operator-(Polynomial_class const &p2){
        Polynomial_class pnew;
        pnew.size = max(size, p2.size);
        for (int i = 0; i< size; i++){
            pnew.dataCof[i] = dataCof[i] - p2.dataCof[i];
        }
        return pnew;
    }

    Polynomial_class operator*(Polynomial_class const &p2){
        Polynomial_class pnew;
        pnew.size = size+(p2.size);
        pnew.dataCof = new int[pnew.size];
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                pnew.dataCof[i+j] += dataCof[i]*(p2.dataCof[j]);
            }
        }
        return pnew;
    }

    // print
    void print(){
        for (int i = 0; i < size; i++){
            if (dataCof[i] != 0){
                cout << dataCof[i] << "x^" << i << " + ";
            } 
        }
        cout << endl;
    }

};

