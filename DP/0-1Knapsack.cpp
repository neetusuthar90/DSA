#include <iostream>
#include <cstring>
using namespace std;

const int d = 1000;
int dp[d][d];

int knapsack(int wt[], int val[], int W, int n){
    // Base case
    if(n == 0 || W == 0){
        return 0;
    }

    if(dp[n][W]!= -1){
        return dp[n][W];
    }
    else{
        if(wt[n-1] <= W){
        dp[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1),knapsack(wt,val,W,n-1));
        }
        else if(wt[n-1] > W){
            dp[n][W] = knapsack(wt,val,W,n-1);
        }
        return dp[n][W];
    }    
}


int main(){
    int val[] = {1,4,5,7};
    int wt[] = {1,3,4,5};
    int W = 7;
    int n = sizeof(val)/sizeof(val[0]);
    memset(dp, -1, sizeof(dp));
    int maxProfit = knapsack(wt, val, W, n);
    cout << maxProfit << endl;
}

/*
Complexity Analysis:
Time complexity: T(N) = 2T(N-1) + O(1), which is simplified to O(2^N).
*/