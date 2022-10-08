#include <iostream>
using namespace std;

bool isSubsetPossible(int arr[], int sum, int n){
    bool t[n+1][sum+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0) t[i][j] = false;
            if(j == 0) t[i][j] = true;
        }
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}


bool isEqualSumPossible(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    if(sum%2 != 0){
        return false;
    }
    else{
        return isSubsetPossible(arr, sum/2, n);
    }
}

int main(){
    int arr[] = {1,5,11,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool ans = isEqualSumPossible(arr,n);
    cout << std::boolalpha << ans << endl;
    return 0;
}