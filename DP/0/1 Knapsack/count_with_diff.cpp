#include <iostream>
using namespace std;

int countofSubsetsum(int arr[], int sum, int n){
    int t[n+1][sum+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0) t[i][j] = 0;
            if(j == 0) t[i][j] = 1;
        }
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int helper(int arr[], int n, int diff){
    int array_sum = 0;
    for(int i = 0; i < n; i++){
        array_sum = array_sum + arr[i];
    }
    int s1 = diff + array_sum;
    if(s1%2 != 0){
        return 0;
    }
    return countofSubsetsum(arr, s1/2, n);
}

int main(){
    int arr[] = { 1,1,1,1,1 };
    int diff = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = helper(arr, n, diff);
    cout << count << endl;
}
