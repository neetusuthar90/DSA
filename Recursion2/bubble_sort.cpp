#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[], int n){
    int i ,j;
    for(i = 0; i < n; i++){
        for (j = i+1; j < n; j++)
        {
            if(arr[j] < arr[i]){
                swap(&arr[j],&arr[i]);
            }
        }
        
    }
}

int main(){
    int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
    int m = sizeof(arr)/sizeof(arr[0]);

    bubblesort(arr,m);
    for (int i = 0; i< m; i++){
        cout << arr[i] << " ";
    }
}