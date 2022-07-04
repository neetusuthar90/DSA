#include <iostream>
using namespace std;
#include <climits>
template <typename T>

class Stack_array
{
private:
    T *data;
    int nextIndex;
    int capacity;
public:
    Stack_array (){
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    // Size of the stack
    int size(){
        return nextIndex;  // O(1)
    }


    // Status of Stack
    bool isempty(){
        return nextIndex == 0;  // O(1)
    }

    // Insert elements
    void push(T ele){
        if (nextIndex == capacity){
            T *newData = new T[2*capacity];
            for (int i =0; i < capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = ele;
        nextIndex ++;
    }

    // O(1)

    // Delete elements
    T pop(){
        if (isempty()){
            cout << "Stack is empty" << endl;
            return 0;
        }
        nextIndex --;
        return data[nextIndex];
    }
    
    // O(1)

    // Access top element
    T top(){
        if (isempty()){
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
    // O(1)
};

