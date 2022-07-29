#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersectionKey(int *arr1, int *arr2, int n, int m){
    unordered_map<int,int> hashmap;
    for(int i = 0; i<n; i++){
        hashmap[arr1[i]]++;
    }

    for(int i =0; i<m; i++){
        if(hashmap[arr2[i]] != 0){
            cout << arr2[i] << endl;
            hashmap[arr2[i]]--;
        }
        else{
            continue;
        }
    }
}

int main(){
    int arr1[] = {2,6,8,5,4,3,12,7,1};
    int arr2[] = {2,4,7,3,8,11,1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    printIntersectionKey(arr1,arr2,n,m);
}