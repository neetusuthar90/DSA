#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int pt1, pt2;
        int closetsum = 10000000;

        for(int i = 0; i < n-2; i++){
            pt1 = i+1;
            pt2 = n-1;
            while(pt1 < pt2){
                int sum = nums[i] + nums[pt1] + nums[pt2];
                
                if(sum == target) return sum;

                if(abs(sum - target) < abs(target - closetsum)) {
                    closetsum = sum;
                }

                if(sum > target){
                    pt2--;
                }
                else{
                    pt1++;
                }

            }
        }
        return closetsum;
    }

int main(){
    vector<int> nums = {-1,2,1,4};
    int target = 1;
    int p1 = threeSumClosest(nums, target);
    cout << p1 << endl;
}