#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> isSubsetPossible(int arr[], int sum, int n){
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
    vector<int> v; // contains all subset sums possible with n elements 
    for(int i = 0; i < sum; i++){
        if(t[n][i] == true){
            v.push_back(i);
        }
    }
    return v;

}

int minimumDiff(int arr[], int n){
    int range = 0;
    for(int i = 0; i < n; i++){
        range = range + arr[i];
    }
    vector<int> v = isSubsetPossible(arr,range,n);
    int mn = INT_MAX;
    for(int i = 0; i < v.size(); i++){
        mn = min(mn, abs(range - 2*v[i]));
    }
    return mn;
}

int main(){
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int minimum = minimumDiff(arr, n);
    cout << "Minimum difference of subset of the given array: " << minimum << endl;
}