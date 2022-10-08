#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

int CountSubsetSum(vector<int> &nums, int sum, int n)
{
    int t[n + 1][sum + 1];
    int k = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(i == 0) t[i][j] = 0;
            if(j == 0) t[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (nums[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return t[n][sum];
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sumofArray = 0;
    for (int i = 0; i < n; i++)
    {
        sumofArray += nums[i];
    }
    int sum = sumofArray + target;
    if (sum % 2 != 0)
    {
        return 0;
    }
    else
    {
        return CountSubsetSum(nums, sum / 2, n);
    }
}

int main()
{
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    int target = 1;
    int count = findTargetSumWays(nums, target);
    cout << count << endl;
}
