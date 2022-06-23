#include <iostream>
using namespace std;

void insertionsort(int arr[], int n){
    int key,i,j;

    for (i = 1; i< n; i++){
        key = arr[i];
        j = i-1;

        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {5,3,4,1,7};
    int m = sizeof(arr)/sizeof(arr[0]);

    insertionsort(arr,m);
    for (int i = 0; i< m; i++){
        cout << arr[i] << " ";
    }
}