#include <iostream>
#include <unordered_map>
using namespace std;

int getMaxFrequency(int *a, int size){
    unordered_map<int,int> frequency;
    for(int i = 0; i < size; i++){
        frequency[a[i]]++;
    }

    int key = 0;
    int count = 0;
    for(int i = 0; i<size; i++){
        if(frequency[a[i]] > count){
            key = a[i];
            count = frequency[a[i]];
        }
    }
    return key;
}

int main(){
    int a[] = {2,12,2,11,12,2,1,2,2,11,12,2,6};
    int size = sizeof(a)/sizeof(a[0]);
    int key = getMaxFrequency(a,size);
    cout << key << endl;

}