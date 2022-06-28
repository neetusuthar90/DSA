#include <iostream>
using namespace std;

class dynamicArray
{
private:
    int *data;
    int nextindex;
    int size;

public:
    dynamicArray(){
        data = new int[5];
        nextindex = 0;
        size = 5;
    }
    
    // Deep copy
    dynamicArray(dynamicArray const &d){
        // this -> data = d.data;  // Shallow copy
        this -> data = new int[d.size];
        for (int i = 0; i < d.nextindex; i++){
            this -> data[i] = d.data[i];
        }
        this -> nextindex = d.nextindex;
        this -> size = d.size;
    }

    void operator=(dynamicArray const &d){
        this -> data = new int[d.size];
        for (int i = 0; i < d.nextindex; i++){
            this -> data[i] = d.data[i];
        }
        this -> nextindex = d.nextindex;
        this -> size = d.size;
    }


    void add(int ele){
        if(nextindex == size){
            int *newData = new int[2*size];
            for(int i = 0; i < size; i++){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            size *= 2;
        }
        data[nextindex] = ele;
        nextindex++;
    }

    int get(int i) const {
        if(i<nextindex){
            return data[i];
        }
        else{
            return -1;
        }
    }

    void add(int i,int ele){
        if ( i < nextindex){
            data[i] = ele;
        }
        else if (i = nextindex)
        {
            add(ele);
        }
        else{
            return ;
        }
        
    }

    void print() const {
        for(int i = 0; i < nextindex; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
