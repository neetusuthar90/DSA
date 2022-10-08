#include <iostream>
#include <cstring>
using namespace std;


int knapsack(int wt[], int val[], int W, int n){
    int t[n+1][W+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < W+1; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < W+1; j++){
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else if(wt[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}


int main(){
    int val[] = {1,4,5,7};
    int wt[] = {1,3,4,5};
    int W = 7;
    int n = sizeof(val)/sizeof(val[0]);
    int maxProfit = knapsack(wt, val, W, n);
    cout << maxProfit << endl;
}

/*
Complexity Analysis:

Time Complexity: O(N*W), where N = number of weight of items and W = capacity.

Space Complexity: O(N*W) as we use 2d array.
*/