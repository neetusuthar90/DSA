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

int main(){
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 15;
    int n = sizeof(arr)/sizeof(arr[0]);
    bool f = isSubsetPossible(arr, sum, n);
    cout << std::boolalpha << f << endl;
}

/*
Complexity Analysis: 
Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
*/
