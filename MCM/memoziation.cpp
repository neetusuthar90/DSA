#include<bits/stdc++.h>
using namespace std;

const int d = 1000;
int t[d][d];

int MCM_memo(vector<int> &arr, int i, int j){
    if(i>=j){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int mn = INT_MAX;
    for(int k = i; k <= j-1; k++){
        int tempAns = MCM_memo(arr,i,k) + MCM_memo(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn, tempAns);
    }
    return t[i][j] = mn;
}

int main(){
    vector<int> arr = {40,20,30,10,30};
    memset(t, -1, sizeof(t));
    int minCost = MCM_memo(arr, 1, arr.size() - 1);
    cout << "Minimum number of multiplication requried: " << minCost << endl;
}