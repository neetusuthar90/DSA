#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> arr;
    int N = nums.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j != i && j < N; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else
            {
                continue;
            }
        }
    }
    return arr;
}

int main()
{
    vector<int> nums = {3, 5, 4, 8};
    vector<int> arr = twoSum(nums,7);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}