#include <iostream>
#include <vector>
using namespace std;

int knapsackRecursive(vector<int> &val, vector<int> &wt, int weight, int n){
    if(n==0 || weight == 0){
        return 0;
    }

    if(wt[n-1] <= weight){
        return max(val[n-1] + knapsackRecursive(val, wt, weight - wt[n-1], n),
                    knapsackRecursive(val, wt, weight, n-1));
    }else{
        return knapsackRecursive(val, wt, weight, n-1);
    }
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