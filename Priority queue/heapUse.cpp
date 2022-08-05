#include <iostream>
#include "PriorityQueue.h"
using namespace std;

// Check max heap or not
bool maxHeap(int *arr, int n, int index = 0){
    if(index > (n-2)/2){
        return true;
    }
    
    int leftIndex = 2*index + 1;
    int rightIndex = 2*index + 2;

    bool isleftheap = maxHeap(arr, n, leftIndex);
    bool isrightheap = maxHeap(arr, n, rightIndex);

    
}

int main(){
    PriorityQueue p;
    int N, data;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> data;
        p.insert(data);
    }
    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    while (!p.isEmpty())
    {
        cout << p.removeMin() << ",";
    }

    cout << endl;

}