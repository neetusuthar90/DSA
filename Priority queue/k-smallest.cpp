#include <iostream>
using namespace std;
#include <queue>

void ksmallest(int *arr, int n, int k){
    priority_queue<int> pq;
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < n; i++){
        if(arr[i] < pq.top()){
            pq.push(arr[i]);
            pq.pop();
        }
        else{
            continue;
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    int arr[] = {2,12,9,16,10,5,3,20,25,11,1,8,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    ksmallest(arr, n, k);
}