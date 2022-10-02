#include <iostream>
#include <vector>
using namespace std;

int rollDice(vector<vector<int>> &dp, int d, int f, int target)
{
    // Base case: d==0 or target<=0
    // If d==0 and target==0 return 1 otherwise return 0
    if (d == 0 || target <= 0)
        return (int)(d == target);

    // If precalculation exists then return value
    if (dp[d][target] != -1){
        cout << dp[d][target] << endl;
        return dp[d][target];
    }
    int res = 0;
    for (int i = 1; i <= f; i++){
        res = (res + rollDice(dp, d - 1, f, target - i));
    }
    // Store calculated value for respective d and target
    dp[d][target] = res;

    return dp[d][target];
}

int numRollsToTarget(int d, int f, int target)
{
    vector<vector<int>> dp(d + 1, vector<int>(target + 1, -1));
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp.size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return rollDice(dp, d, f, target);
}

int main()
{
    int d, f, target;
    d = 2;
    f = 6;
    target = 7;
    int option = numRollsToTarget(d,f,target);
    cout << option << endl;
}