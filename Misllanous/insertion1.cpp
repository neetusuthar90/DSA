#include <iostream>
#include <vector>
using namespace std;

void insertionSort1(int n, vector<int> arr) {
    int cur_idx = n-1;
    int val = arr[cur_idx],i;
   
    for(i = cur_idx -1; arr[i] > val && i >=0; i--){
        arr[i+1] = arr[i];
        for(int j = 0; j < n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    arr[i+1] = val;
    for(int j = 0; j < n; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {2,4,6,8,3};
    int n = sizeof(arr)/sizeof(arr[1]) - 1;
    insertionSort1(n, arr);
    return 0;
}