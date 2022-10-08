#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int p = 100;
int t[p][p];

int knapsackRecursive(vector<int> &val, vector<int> &wt, int weight, int n){
    if(n==0 || weight == 0){
        return 0;
    }
    
    if(t[n][weight] != -1){
        return t[n][weight];
    }

    if(wt[n-1] <= weight){
        t[n][weight] = max(val[n-1] + knapsackRecursive(val, wt, weight - wt[n-1], n),
                    knapsackRecursive(val, wt, weight, n-1));
    }else{
        t[n][weight] = knapsackRecursive(val, wt, weight, n-1);
    }
    return t[n][weight];
}

int main(){
    vector<int> val = {10,40,50,70};
    vector<int> wt = {1,3,4,5};
    int weight = 8;
    int n = wt.size();
    memset(t, -1, sizeof(t));
    int maxProfit = knapsackRecursive(val, wt, weight, n);
    cout << maxProfit << endl;
    return 0;
}