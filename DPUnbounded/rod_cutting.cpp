#include <iostream>
#include <vector>
using namespace std;

int knapsackRecursive(vector<int> &price, vector<int> &length, int N, int n){
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[N+1];
    }
    for(int i = 0; i <=n; i++){
        for(int j = 0; j <= N; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            
            else if(length[i-1] <= j){
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][N];
}

int main(){
    vector<int> price = {1,5,8,9,10,17,17,20};
    vector<int> length = {1,2,3,4,5,6,7,8};
    int N = 8;
    int n = length.size();
    int maxProfit = knapsackRecursive(price, length, N, n);
    cout << maxProfit << endl;
    return 0;
}