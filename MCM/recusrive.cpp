#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MCMrecursive(vector<int> &arr, int i, int j){
    if(i>=j){
        return 0;
    }
    int mn = INT_MAX;
    for(int k = i; k <= j-1; k++){
        int tempAns = MCMrecursive(arr,i,k) + MCMrecursive(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn, tempAns);
    }
    return mn;
}

int main(){
    vector<int> arr = {40,20,30,10,30};
    int minCost = MCMrecursive(arr, 1, arr.size() - 1);
    cout << "Minimum number of multiplication requried: " << minCost << endl;
}