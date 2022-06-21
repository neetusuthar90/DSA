#include <iostream>
using namespace std;


void quick_sort(int a[], int si, int ei){
    if (si>= ei){
        return;
    }

    int m = si + (ei - si)/2;
    int pivot = a[m];
    int i = si;
    int j = ei;

    while (i <= j){
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        
        if (i <= j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        
    }

    quick_sort(a,si,j);
    quick_sort(a,i,ei);
}


int main(){
    int arr[] = {5,9,8,3,2,7,1};
    int m = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, m);

    for (int i = 0; i< m; i++){
        cout << arr[i] << " ";
    }

}