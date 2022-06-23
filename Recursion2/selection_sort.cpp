#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int arr[], int n){
    int i,j,min_index;

    for(i = 0; i < n-1; i++){
        min_index = i;
        
        for (j = i+1; j< n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(&arr[i],&arr[min_index]);
    }
}

int main(){
    int arr[] = {5,3,4,1,7};
    int m = sizeof(arr)/sizeof(arr[0]);

    selectionsort(arr,m);
    for (int i = 0; i< m; i++){
        cout << arr[i] << " ";
    }
}