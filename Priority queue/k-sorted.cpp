#include <iostream>
using namespace std;
#include <queue>

void kSortedArray(int *arr, int n, int k){
    priority_queue<int> pq;
    for(int i= 0; i < k; i++){
        pq.push(arr[i]);
    }

    int j = 0;
    for(int i = k; i < n; i++){
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while (!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
    
}
// Time Complexity: O(n)
// Space Complexity: 

int main(){
    int arr[] = {10,12,6,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    kSortedArray(arr, n, 3);
    for(int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}