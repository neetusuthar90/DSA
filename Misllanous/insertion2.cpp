#include <iostream>
#include <vector>
using namespace std;

int insertionSort2(int n, vector<int> arr) {
    int key, k,j;
    int count = 0;
    for(int k = 1; k < n; k++){
        key = arr[k];
        j = k - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
            count += 1;
        }
        arr[j+1] = key;
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return count;
}

int main(){
    vector<int> arr = {4,3,2,1};
    int n = arr.size();
    cout << n << endl;
    int count = insertionSort2(n, arr);
    cout << count << endl;
    return 0;
}