#include <iostream>
#include <vector>
using namespace std;

int knapsackRecursive(vector<int> &val, vector<int> &wt, int weight, int n){
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[weight+1];
    }
    for(int i = 0; i <=n; i++){
        for(int j = 0; j <= weight; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            
            else if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][weight];
}

int main(){
    vector<int> val = {10,40,50,70};
    vector<int> wt = {1,3,4,5};
    int weight = 8;
    int n = wt.size();
    int maxProfit = knapsackRecursive(val, wt, weight, n);
    cout << maxProfit << endl;
    return 0;
}